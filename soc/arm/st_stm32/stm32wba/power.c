/*
 * Copyright (c) 2022 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/pm/pm.h>
#include <soc.h>
#include <zephyr/init.h>

#include <stm32wbaxx_ll_bus.h>
#include <stm32wbaxx_ll_pwr.h>
#include <stm32wbaxx_ll_icache.h>
#include <stm32wbaxx_ll_rcc.h>
#include <stm32wbaxx_ll_system.h>
#include <clock_control/clock_stm32_ll_common.h>

#include "scm.h"

#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(soc, CONFIG_SOC_LOG_LEVEL);

void set_mode_stop(uint8_t substate_id)
{

	LL_PWR_ClearFlag_STOP();
	LL_RCC_ClearResetFlags();

	// EGO: HSE is ready at this point
	//while (LL_RCC_HSE_IsReady() == 0) {
	//}

	// EGO: No switch from HSI to HSE at this point
	scm_hserdy_isr();

	/* Disabling ICACHE */
	LL_ICACHE_Disable();

	/* Wait until ICACHE_SR.BUSYF is cleared */
	while(LL_ICACHE_IsActiveFlag_BUSY() == 1U);

	/* Wait until ICACHE_SR.BSYENDF is set */
	while(LL_ICACHE_IsActiveFlag_BSYEND() == 0U);

#ifdef CONFIG_BT_STM32WBA
	scm_setwaitstates(LP);
#endif
	// EGO: Done in pm_state_set
	//LL_LPM_EnableDeepSleep();

	while(LL_PWR_IsActiveFlag_ACTVOS( ) == 0) {
	}
	// AM: Here we must be sure to have RADIO in idle and RNG and ADC completely off
	// to reach power target value of about 30 uA
	switch (substate_id) {
	case 1: /* enter STOP0 mode */
		LL_PWR_SetPowerMode(LL_PWR_MODE_STOP0);
		break;
	case 2: /* enter STOP1 mode */
		LL_PWR_SetPowerMode(LL_PWR_MODE_STOP1);
		break;
	default:
		LOG_DBG("Unsupported power state substate-id %u", substate_id);
		break;
	}
}

void set_mode_standby(uint8_t substate_id)
{
	ARG_UNUSED(substate_id);
	/* Select standby mode */
	LL_PWR_SetPowerMode(LL_PWR_MODE_STANDBY);
}

/* Invoke Low Power/System Off specific Tasks */
void pm_state_set(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_SUSPEND_TO_IDLE:
		set_mode_stop(substate_id);
		break;
	case PM_STATE_STANDBY:
		/* To be tested */
		set_mode_standby(substate_id);
		break;
	default:
		LOG_DBG("Unsupported power state %u", state);
		return;
	}

	/* Set SLEEPDEEP bit of Cortex System Control Register */
	LL_LPM_EnableDeepSleep();

	/* Select mode entry : WFE or WFI and enter the CPU selected mode */
	k_cpu_idle();
}

/* Handle SOC specific activity after Low Power Mode Exit */
void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
{

	LL_ICACHE_Enable();
	while(LL_ICACHE_IsEnabled() == 0U);

#ifdef CONFIG_BT_STM32WBA
	if (LL_PWR_IsActiveFlag_STOP() == 1U) {
		scm_setup();
	} else {
		scm_setwaitstates(RUN);
	}
#endif

	switch (state) {
	case PM_STATE_SUSPEND_TO_IDLE:
		if (substate_id <= 2) {
			// EGO: Why removing ?
			LL_LPM_DisableSleepOnExit();
			LL_LPM_EnableSleep();
		} else {
			LOG_DBG("Unsupported power substate-id %u",
							substate_id);
		}
	case PM_STATE_STANDBY:
		/* To be tested */
		LL_LPM_EnableSleep();
	case PM_STATE_SUSPEND_TO_RAM:
		__fallthrough;
	case PM_STATE_SUSPEND_TO_DISK:
		__fallthrough;
	default:
		LOG_DBG("Unsupported power state %u", state);
		break;
	}
#if !defined(CONFIG_BT_STM32WBA)
	/* need to restore the clock */
	stm32_clock_control_init(NULL);
#endif

	/*
	 * System is now in active mode.
	 * Reenable interrupts which were disabled
	 * when OS started idling code.
	 */
	irq_unlock(0);
}

/* Initialize STM32 Power */
static int stm32_power_init(void)
{

#ifdef CONFIG_BT_STM32WBA
	// LL_PWR_SetRegulVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2);
	scm_init();
#endif

	/* enable Power clock */
	LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_PWR);

#ifdef CONFIG_DEBUG
	LL_DBGMCU_EnableDBGStopMode();
#else
	LL_DBGMCU_DisableDBGStopMode();
	LL_DBGMCU_DisableDBGStandbyMode();
#endif

	// AM: Enabling  Ultra Low power mode
	LL_PWR_EnableUltraLowPowerMode();

	// AM: Enable the FLASH power down during Low-Power sleep mode
	__HAL_FLASH_SLEEP_POWERDOWN_ENABLE();

	return 0;
}

SYS_INIT(stm32_power_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
