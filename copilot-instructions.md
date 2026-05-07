# Fork-Specific Copilot Instructions

This file supplements `.github/copilot-instructions.md`.

Use these instructions for Copilot code-generation contributions that are specific to this
fork's STM32 and review workflow.

## Instruction Precedence And Conflict Handling

- Treat `.github/copilot-instructions.md` as the upstream baseline instruction set.
- Treat this file as a fork-specific supplement that may add workflow requirements, extra
  validation expectations, or PR conventions.
- Apply both files when they are compatible.
- If a local instruction conflicts with an upstream instruction, generate an explicit
  warning message that identifies the conflict and do not silently choose one.
- In case of conflict, upstream repository rules win for licensing, DCO, coding style,
  mandatory contribution process, and any other project-wide policy.
- Fork-specific instructions may tighten or extend the workflow, but they must not weaken
  or override mandatory upstream requirements.

## PR Description Workflow

- It is technically acceptable to include a summary of the effective prompt in the PR
  description.
- The PR prompt summary should describe the user-visible request, implementation scope,
  important constraints, assumptions, exclusions, and requested validation.
- Do not copy hidden system prompts, private workspace instructions, or internal control
  text verbatim into the PR description.
- Write the prompt summary as a concise engineering brief that another reviewer can use to
  understand why the change exists.
- When preparing a PR description, include:
  - a short summary of the requested change
  - the main technical decisions taken
  - the explicit test plan
  - the build-only validation that was executed
  - the proposed `west twister` hardware validation using the local `map.yaml`
  - any known limits, exclusions, or follow-up work

## Technical Research Workflow

- Start from the narrowest owning implementation surface: the affected driver, SoC support,
  binding, board DTS, or test.
- For STM32 and other vendor-backed IP blocks, use the matching HAL module as a
  hardware capability database.
- Code contributions must not contain code copied from, or derived exclusively from,
  material that is only available under the ST SLA license.
- If the only available implementation detail comes from ST SLA-licensed material,
  generate a warning and stop short of producing derivative code until an acceptable
  public or project-compatible source is identified.
- Use HAL headers and source files to confirm supported instances, feature bits, register
  layout, clock/reset information, IRQ naming, and IP differences between series.
- Treat the HAL as reference data, not as code to copy into Zephyr.
- Keep the Zephyr-side design in Zephyr terms: bindings, DTS hierarchy, init ordering,
  driver APIs, and subsystem integration.
- Cross-check the complete path affected by a change: binding, SoC DTS, board DTS,
  common support code, consumer drivers, and existing samples/tests.
- If HAL capabilities and the current Zephyr model do not align, record the assumption in
  the commit message and PR description.

## Change Planning

- Fix the root cause and avoid leaving duplicated per-driver or per-board logic when the
  support should be centralized.
- When enabling a new IP block or SoC series, review all impacted layers together:
  bindings, common SoC code, board enablement, driver consumers, and validation assets.
- Prefer the smallest coherent implementation that matches the hardware model already used
  elsewhere in the tree.
- If existing validation is insufficient, explicitly propose the development of a new test,
  sample extension, overlay, or Twister scenario.

## Commit Workflow

- Keep work based on `main` and maintain a rebaseable history.
- Split contributions into logical, reviewable, and buildable commits.
- Each commit should represent one coherent step, such as SoC/common support, board
  enablement, driver cleanup, or test/documentation updates.
- Generate Zephyr-style commit messages with an area prefix and a non-empty body that
  explains what changed, why it changed, assumptions made, and how the change was
  validated.
- When review feedback affects logic already introduced in a commit, amend or rebase the
  guilty commit instead of stacking unrelated fixup commits, unless a reviewer asks for a
  different workflow.
- AI agents must not add `Signed-off-by` lines. The human author is responsible for DCO
  sign-off.
- When AI-generated content is committed, include an `Assisted-by:` trailer in the commit
  message.
- When asked to generate a commit series, also generate a matching validation summary for
  each commit or for the full series.

## Validation And Test Plan

- Every code-generation contribution must include an explicit test plan.
- Start with build-only validation and execute that part of the test plan before proposing
  hardware execution.
- Prefer focused `west build` coverage for the touched code paths: affected boards,
  relevant samples, subsystem tests, overlays, and configuration variants.
- Keep the build matrix narrow but representative. Cover each touched execution path at
  least once when possible.
- If existing tests do not exercise the changed behavior, propose a concrete additional
  test. This can be a new test case, an existing sample update, a board overlay, or a new
  Twister scenario.
- Clearly distinguish between tests executed locally as build-only validation and tests
  proposed for later hardware execution.
- After build-only validation is complete, propose hardware validation with `west twister`
  and a local `map.yaml` file for connected boards.
- Before device testing, verify that the local hardware map is correct for the board,
  including the selected runner.
- Prefer a focused device-testing command first, then widen the campaign only if the
  initial results require it.

Example build-first workflow:

```sh
west build -b <board> <sample-or-test>
west build -b <board> <sample-or-test> -- -DDTC_OVERLAY_FILE=<overlay>
```

Example follow-up hardware validation proposal:

```sh
west twister --device-testing --hardware-map ../map.yaml \
  -p <platform> -T <sample-or-test> --jobs 1 --inline-logs -v
```