.. _zephyr_stm32_release_notes:

STM32 Platform – Noteworthy Changes (2025-11-13 – 2026-03-25)
##############################################################

This document lists the noteworthy changes related to the STM32 platform that
were merged in the upstream `zephyrproject-rtos/zephyr` repository between
2025-11-13 and 2026-03-25 (filter: ``is:pr label:"platform: STM32"``).

Changes are grouped by area of impact for easier reading.

New SoC and Series Support
**************************

* **STM32C5** – Initial support for the STM32C5 series was added
  (`#105577 <https://github.com/zephyrproject-rtos/zephyr/pull/105577>`_).
  Subsequent PRs completed the peripheral coverage:

  * DMA (`#105660 <https://github.com/zephyrproject-rtos/zephyr/pull/105660>`_)
  * I2C (`#105758 <https://github.com/zephyrproject-rtos/zephyr/pull/105758>`_)
  * SPI (`#105757 <https://github.com/zephyrproject-rtos/zephyr/pull/105757>`_)
  * ADC (`#105761 <https://github.com/zephyrproject-rtos/zephyr/pull/105761>`_)
  * RTC (`#105671 <https://github.com/zephyrproject-rtos/zephyr/pull/105671>`_)
  * Timers (`#105666 <https://github.com/zephyrproject-rtos/zephyr/pull/105666>`_)
  * Watchdog (`#105947 <https://github.com/zephyrproject-rtos/zephyr/pull/105947>`_)

* **STM32WBA2X** – Initial support added for the STM32WBA2X sub-series
  (`#105571 <https://github.com/zephyrproject-rtos/zephyr/pull/105571>`_).

* **STM32H5E/F** – New STM32H5E/F devices introduced with UART9 instance,
  SRAM node renames, HPDMA support, and pin-muxing conflict handling
  (`#105052 <https://github.com/zephyrproject-rtos/zephyr/pull/105052>`_,
  `#105852 <https://github.com/zephyrproject-rtos/zephyr/pull/105852>`_,
  `#105849 <https://github.com/zephyrproject-rtos/zephyr/pull/105849>`_,
  `#105651 <https://github.com/zephyrproject-rtos/zephyr/pull/105651>`_).

* **STM32U3** – New STM32U3 sub-series: added RTC support and enabled RTC on
  the Nucleo-U385RG-Q board
  (`#101133 <https://github.com/zephyrproject-rtos/zephyr/pull/101133>`_).
  ADC calibration was added
  (`#105929 <https://github.com/zephyrproject-rtos/zephyr/pull/105929>`_).
  Various flash driver fixes were applied
  (`#104662 <https://github.com/zephyrproject-rtos/zephyr/pull/104662>`_).

* **STM32MP215F-DK** – New board support added
  (`#103432 <https://github.com/zephyrproject-rtos/zephyr/pull/103432>`_).

* **STM32MP13** – Added SPI peripheral support
  (`#104320 <https://github.com/zephyrproject-rtos/zephyr/pull/104320>`_).
  Ethernet support enabled on the STM32MP135F-DK
  (`#96134 <https://github.com/zephyrproject-rtos/zephyr/pull/96134>`_).

New Board Support and Updates
*****************************

* ``nucleo_u3c5zi_q`` – New Nucleo board for the STM32C5 series
  (`#105503 <https://github.com/zephyrproject-rtos/zephyr/pull/105503>`_).
* ``stm32f469i_disco`` – Added AU1 variant and updated LCD display support
  (`#104144 <https://github.com/zephyrproject-rtos/zephyr/pull/104144>`_).
* ``stm32l4r9i_disco`` – DSI display via ST_B_DSI_MB1314 shield enabled
  (`#104115 <https://github.com/zephyrproject-rtos/zephyr/pull/104115>`_).
* ``stm32h7s78_dk`` – Ethernet support, FDCAN1, JLink runner, and updated
  documentation added
  (`#99296 <https://github.com/zephyrproject-rtos/zephyr/pull/99296>`_,
  `#99917 <https://github.com/zephyrproject-rtos/zephyr/pull/99917>`_,
  `#99142 <https://github.com/zephyrproject-rtos/zephyr/pull/99142>`_,
  `#102901 <https://github.com/zephyrproject-rtos/zephyr/pull/102901>`_).
* ``stm32h7s3l8`` – Introduced an App-in-External-Flash board variant
  (`#99647 <https://github.com/zephyrproject-rtos/zephyr/pull/99647>`_).
* ``stm32mp257f_ev1`` – FDCAN enabled on M33 core
  (`#102888 <https://github.com/zephyrproject-rtos/zephyr/pull/102888>`_).
* ``stm32n6570_dk`` – OTP via NVMEM enabled, detailed debug instructions added,
  and serial boot SRAM size increased
  (`#103236 <https://github.com/zephyrproject-rtos/zephyr/pull/103236>`_,
  `#102736 <https://github.com/zephyrproject-rtos/zephyr/pull/102736>`_,
  `#100693 <https://github.com/zephyrproject-rtos/zephyr/pull/100693>`_).
* ``stm32h573i_dk`` – TF-M non-secure app support and ST-LINK GDB server runner
  added
  (`#100114 <https://github.com/zephyrproject-rtos/zephyr/pull/100114>`_,
  `#102202 <https://github.com/zephyrproject-rtos/zephyr/pull/102202>`_).
* ``nucleo_wba55cg`` – IEEE 802.15.4 node enabled
  (`#105060 <https://github.com/zephyrproject-rtos/zephyr/pull/105060>`_).
* Multiple boards received ``stlink_gdbserver`` runner entries
  (`#100593 <https://github.com/zephyrproject-rtos/zephyr/pull/100593>`_,
  `#104996 <https://github.com/zephyrproject-rtos/zephyr/pull/104996>`_,
  `#104995 <https://github.com/zephyrproject-rtos/zephyr/pull/104995>`_).

Bluetooth and IEEE 802.15.4 (STM32WBx / STM32WBAx)
****************************************************

* STM32WBAx: BLE and IEEE 802.15.4 concurrent mode integration
  (`#97773 <https://github.com/zephyrproject-rtos/zephyr/pull/97773>`_).
* STM32WBA: 802.15.4 configuration types support (PAN, coordinator, etc.)
  (`#104829 <https://github.com/zephyrproject-rtos/zephyr/pull/104829>`_).
* STM32WBA: Bluetooth disable support
  (`#101877 <https://github.com/zephyrproject-rtos/zephyr/pull/101877>`_).
* STM32WBAx: OpenThread Kconfig configuration
  (`#104844 <https://github.com/zephyrproject-rtos/zephyr/pull/104844>`_).
* STM32WBAx: BLE controller and link layer thread initialization rework
  (`#105046 <https://github.com/zephyrproject-rtos/zephyr/pull/105046>`_).
* STM32WBAx: PM RF refactoring for improved power management
  (`#103931 <https://github.com/zephyrproject-rtos/zephyr/pull/103931>`_).
* STM32WBA: HSE trimming setting integration
  (`#97719 <https://github.com/zephyrproject-rtos/zephyr/pull/97719>`_).
* STM32WBA: HCI driver Kconfig options support
  (`#105195 <https://github.com/zephyrproject-rtos/zephyr/pull/105195>`_).
* STM32WBA: removed host API dependency in Bluetooth driver close/setup
  (`#104839 <https://github.com/zephyrproject-rtos/zephyr/pull/104839>`_).
* STM32WBAx: IEEE 802.15.4 MAC key null fix and RX failure notification
  (`#105134 <https://github.com/zephyrproject-rtos/zephyr/pull/105134>`_,
  `#105547 <https://github.com/zephyrproject-rtos/zephyr/pull/105547>`_).
* STM32WBA: IEEE 802.15.4 ED conversion to RSSI in dBm
  (`#105296 <https://github.com/zephyrproject-rtos/zephyr/pull/105296>`_).
* STM32WB IPM: extended advertising support
  (`#101889 <https://github.com/zephyrproject-rtos/zephyr/pull/101889>`_).
* hal_stm32 updated for STM32CubeWBA v1.8.0 and v1.9.0
  (`#104135 <https://github.com/zephyrproject-rtos/zephyr/pull/104135>`_,
  `#105050 <https://github.com/zephyrproject-rtos/zephyr/pull/105050>`_).
* STM32WB0: HAL updated to STM32CubeWB0 v1.4.0
  (`#101051 <https://github.com/zephyrproject-rtos/zephyr/pull/101051>`_).

USB
***

* USB UDC: proper isochronous endpoint support for the ST USB IP
  (`#105151 <https://github.com/zephyrproject-rtos/zephyr/pull/105151>`_).
* USB UDC: multi-instance support
  (`#102495 <https://github.com/zephyrproject-rtos/zephyr/pull/102495>`_).
* USB UDC: SOF (Start-of-Frame) interrupt support enabled
  (`#103586 <https://github.com/zephyrproject-rtos/zephyr/pull/103586>`_).
* USB UDC: PHY configuration moved to common code
  (`#102493 <https://github.com/zephyrproject-rtos/zephyr/pull/102493>`_).
* USB UDC: power configuration moved to common code
  (`#100519 <https://github.com/zephyrproject-rtos/zephyr/pull/100519>`_).
* USB DC: callbacks no longer invoked from ISR context
  (`#104390 <https://github.com/zephyrproject-rtos/zephyr/pull/104390>`_).
* USB OTG: fixed OTGHS on STM32F723/F730 with embedded USBPHYC
  (`#100756 <https://github.com/zephyrproject-rtos/zephyr/pull/100756>`_,
  `#99756 <https://github.com/zephyrproject-rtos/zephyr/pull/99756>`_).

ADC
***

* STM32 ADC: RTIO / stream support added
  (`#104304 <https://github.com/zephyrproject-rtos/zephyr/pull/104304>`_).
* STM32 ADC: resolution rework for full API compliance
  (`#101815 <https://github.com/zephyrproject-rtos/zephyr/pull/101815>`_).
* STM32 ADC: injected channel support (RFC)
  (`#99787 <https://github.com/zephyrproject-rtos/zephyr/pull/99787>`_).
* STM32G4: OPAMP driver support
  (`#99181 <https://github.com/zephyrproject-rtos/zephyr/pull/99181>`_).
* STM32: NVM OTP driver implemented and used by ADC sensor drivers
  (`#102976 <https://github.com/zephyrproject-rtos/zephyr/pull/102976>`_).

SPI
***

* Asynchronous DMA transfer support
  (`#103396 <https://github.com/zephyrproject-rtos/zephyr/pull/103396>`_).
* RTIO-DMA support
  (`#101331 <https://github.com/zephyrproject-rtos/zephyr/pull/101331>`_).
* Full FIFO utilization for H7-compatible SPI
  (`#103079 <https://github.com/zephyrproject-rtos/zephyr/pull/103079>`_).
* Extended data size support (beyond 16-bit)
  (`#99321 <https://github.com/zephyrproject-rtos/zephyr/pull/99321>`_).
* Baudrate prescaler bypass support
  (`#100467 <https://github.com/zephyrproject-rtos/zephyr/pull/100467>`_).
* Soft NSS support in peripheral (slave) mode
  (`#98446 <https://github.com/zephyrproject-rtos/zephyr/pull/98446>`_).
* Code cleanup and LL function prefix factorization
  (`#104026 <https://github.com/zephyrproject-rtos/zephyr/pull/104026>`_,
  `#102882 <https://github.com/zephyrproject-rtos/zephyr/pull/102882>`_).
* Fixed stale read in half-duplex master RX mode
  (`#103781 <https://github.com/zephyrproject-rtos/zephyr/pull/103781>`_).
* Kept SPE enabled for Slave Half-Duplex TX
  (`#103882 <https://github.com/zephyrproject-rtos/zephyr/pull/103882>`_).

DMA
***

* STM32C5: DMA peripheral support
  (`#105660 <https://github.com/zephyrproject-rtos/zephyr/pull/105660>`_).
* STM32U5 DMA: configurable burst lengths
  (`#99258 <https://github.com/zephyrproject-rtos/zephyr/pull/99258>`_).
* Fixed incorrect burst length in multiple drivers' DMA configurations
  (`#100105 <https://github.com/zephyrproject-rtos/zephyr/pull/100105>`_).
* Consolidated callback handling in ``dma_stm32_irq_handler``
  (`#101906 <https://github.com/zephyrproject-rtos/zephyr/pull/101906>`_).
* Fixed data sizes in memory-to-peripheral direction
  (`#101851 <https://github.com/zephyrproject-rtos/zephyr/pull/101851>`_).
* Removed on-stack copying of DMA configuration in STM32 drivers
  (`#100223 <https://github.com/zephyrproject-rtos/zephyr/pull/100223>`_).

Flash and Storage
*****************

* STM32WBA65: byte-write emulation for unaligned flash writes
  (`#103301 <https://github.com/zephyrproject-rtos/zephyr/pull/103301>`_).
* STM32U5 / STM32L5: readout protection implementation
  (`#101124 <https://github.com/zephyrproject-rtos/zephyr/pull/101124>`_).
* XSPI / OSPI flash driver: configurable delayed data sampling
  (`#98999 <https://github.com/zephyrproject-rtos/zephyr/pull/98999>`_).
* XSPI flash driver: instantiation support and RAM_LOAD mode
  (`#102911 <https://github.com/zephyrproject-rtos/zephyr/pull/102911>`_,
  `#99729 <https://github.com/zephyrproject-rtos/zephyr/pull/99729>`_).
* OSPI: fixed erase regression in OPI mode
  (`#101474 <https://github.com/zephyrproject-rtos/zephyr/pull/101474>`_).
* XSPI Manager driver added for SoC-level arbitration
  (`#104943 <https://github.com/zephyrproject-rtos/zephyr/pull/104943>`_).
* SDMMC: cache flush & invalidation for DMA transfers
  (`#100409 <https://github.com/zephyrproject-rtos/zephyr/pull/100409>`_).
* SDMMC: erase support when used in eMMC mode
  (`#104734 <https://github.com/zephyrproject-rtos/zephyr/pull/104734>`_).
* SDMMC: PM handling improvements
  (`#98724 <https://github.com/zephyrproject-rtos/zephyr/pull/98724>`_).

Ethernet
********

* DWMAC (STM32H7/H5/H7RS): added support for H5 and H7RS series, and
  configurable PHY connection type
  (`#105390 <https://github.com/zephyrproject-rtos/zephyr/pull/105390>`_).
* STM32 Ethernet: Port Selection (RMII / MII) support
  (`#100447 <https://github.com/zephyrproject-rtos/zephyr/pull/100447>`_).
* STM32 Ethernet: MAC address configuration from Device Tree
  (`#105090 <https://github.com/zephyrproject-rtos/zephyr/pull/105090>`_).
* STM32 Ethernet: MDIO clock range set correctly after MAC reset
  (`#103762 <https://github.com/zephyrproject-rtos/zephyr/pull/103762>`_).
* STM32 Ethernet: removed legacy MAC implementation parts
  (`#102810 <https://github.com/zephyrproject-rtos/zephyr/pull/102810>`_).
* STM32N6 / STM32MP: OTP-based MAC address loading via BSEC driver
  (`#102403 <https://github.com/zephyrproject-rtos/zephyr/pull/102403>`_).

Video and Display
*****************

* STM32H7RS DCMIPP: camera pipe enabled with ST-B-CAMS-OMV shield
  (`#100242 <https://github.com/zephyrproject-rtos/zephyr/pull/100242>`_).
* stm32-dcmipp: fixed driver initialization issue
  (`#102848 <https://github.com/zephyrproject-rtos/zephyr/pull/102848>`_).
* LTDC / DSI: pixel format handling properly using LTDC node properties
  (`#99277 <https://github.com/zephyrproject-rtos/zephyr/pull/99277>`_).
* LTDC: fixed deadlock on full write
  (`#105528 <https://github.com/zephyrproject-rtos/zephyr/pull/105528>`_).
* LTDC / DSI: fixed display flush and cached memory access
  (`#102273 <https://github.com/zephyrproject-rtos/zephyr/pull/102273>`_).
* STM32H7RS / STM32N6: video buffer pool placement in ZEPHYR REGION
  (`#100628 <https://github.com/zephyrproject-rtos/zephyr/pull/100628>`_).
* STM32 video encoder: various fixes
  (`#102169 <https://github.com/zephyrproject-rtos/zephyr/pull/102169>`_).
* STM32N6 DSP (NPU) initialized at device priority
  (`#104601 <https://github.com/zephyrproject-rtos/zephyr/pull/104601>`_).

CRC Driver
**********

* New CRC hardware driver for STM32 introduced
  (`#105302 <https://github.com/zephyrproject-rtos/zephyr/pull/105302>`_).

Clock Control and Power Management
***********************************

* STM32F2/F4/F7: full PLL clock rework for improved accuracy
  (`#100757 <https://github.com/zephyrproject-rtos/zephyr/pull/100757>`_).
* STM32H5 / STM32U5: fixed PLL rate calculation with fractional dividers
  (`#100800 <https://github.com/zephyrproject-rtos/zephyr/pull/100800>`_).
* STM32H7: fixed voltage scale0 setting
  (`#104749 <https://github.com/zephyrproject-rtos/zephyr/pull/104749>`_).
* STM32H7: fixed PLL rate with fractional PLL
  (`#101077 <https://github.com/zephyrproject-rtos/zephyr/pull/101077>`_).
* STM32H5: HSLV (High-Speed Low-Voltage) I/O cell support
  (`#105856 <https://github.com/zephyrproject-rtos/zephyr/pull/105856>`_).
* STM32: power supply configurable through Device Tree
  (`#99171 <https://github.com/zephyrproject-rtos/zephyr/pull/99171>`_).
* STM32U5: VOS (Voltage Operating Scale) selection via Device Tree
  (`#100319 <https://github.com/zephyrproject-rtos/zephyr/pull/100319>`_).
* STM32: LPTIM reset support
  (`#100613 <https://github.com/zephyrproject-rtos/zephyr/pull/100613>`_).
* STM32: Kconfig reorganized to unify family-wide defconfig
  (`#104762 <https://github.com/zephyrproject-rtos/zephyr/pull/104762>`_,
  `#100218 <https://github.com/zephyrproject-rtos/zephyr/pull/100218>`_).
* STM32: backup SRAM initialized early for retained memory support
  (`#105167 <https://github.com/zephyrproject-rtos/zephyr/pull/105167>`_).
* STM32U5: backup SRAM retention when regulator is in LDO mode
  (`#99821 <https://github.com/zephyrproject-rtos/zephyr/pull/99821>`_).

Pinctrl and GPIO
*****************

* STM32: GPIO and PINCTRL drivers decoupled for better modularity
  (`#104527 <https://github.com/zephyrproject-rtos/zephyr/pull/104527>`_).
* STM32: I/O cell driver (``stm32_iocell``) for managing special I/O attributes,
  extended with STM32H5 support
  (`#100539 <https://github.com/zephyrproject-rtos/zephyr/pull/100539>`_,
  `#104599 <https://github.com/zephyrproject-rtos/zephyr/pull/104599>`_).
* STM32: iosync pinctrl configuration moved to common code
  (`#105739 <https://github.com/zephyrproject-rtos/zephyr/pull/105739>`_).
* STM32F1: pin controller cleanup
  (`#104172 <https://github.com/zephyrproject-rtos/zephyr/pull/104172>`_).
* STM32 GPIO: added missing port "W" to instance list
  (`#104391 <https://github.com/zephyrproject-rtos/zephyr/pull/104391>`_).
* STM32 GPIO: use device as ISR argument (instead of data pointer)
  (`#104221 <https://github.com/zephyrproject-rtos/zephyr/pull/104221>`_).
* STM32 GPIO: GPIO instantiation converted to use FOR_EACH macro
  (`#99643 <https://github.com/zephyrproject-rtos/zephyr/pull/99643>`_).

RTC
***

* STM32 RTC: allow disabling a pending alarm
  (`#104894 <https://github.com/zephyrproject-rtos/zephyr/pull/104894>`_).
* STM32 RTC: fixed subsecond register read in counter driver
  (`#101223 <https://github.com/zephyrproject-rtos/zephyr/pull/101223>`_).
* STM32H7RS: RTC support with nodes enabled on Nucleo-H7S3L8 and STM32H7S78-DK
  (`#103487 <https://github.com/zephyrproject-rtos/zephyr/pull/103487>`_).

Timers and PWM
**************

* STM32 Timer: counter support for advanced timers
  (`#99240 <https://github.com/zephyrproject-rtos/zephyr/pull/99240>`_).
* STM32 PWM: DMA request support
  (`#88671 <https://github.com/zephyrproject-rtos/zephyr/pull/88671>`_).
* STM32 PWM: trigger output (TRGO/TRGO2) configurable via Device Tree
  (`#97433 <https://github.com/zephyrproject-rtos/zephyr/pull/97433>`_).
* STM32 PWM: deadtime configurable via Device Tree
  (`#98247 <https://github.com/zephyrproject-rtos/zephyr/pull/98247>`_).
* LPTIM: fixed incorrect timer configuration and hardened against wrong usage
  (`#105216 <https://github.com/zephyrproject-rtos/zephyr/pull/105216>`_).
* LPTIM: improved initialization sequence
  (`#102306 <https://github.com/zephyrproject-rtos/zephyr/pull/102306>`_).

CAN
***

* STM32 FDCAN: hardware RX timestamping support
  (`#101374 <https://github.com/zephyrproject-rtos/zephyr/pull/101374>`_).
* STM32 BXCAN: fixed TDTxR register configuration
  (`#103810 <https://github.com/zephyrproject-rtos/zephyr/pull/103810>`_).

I2S / SAI
*********

* STM32 SAI: DMA data size configuration support
  (`#99967 <https://github.com/zephyrproject-rtos/zephyr/pull/99967>`_).
* STM32 SAI: DMA priority configuration support
  (`#97871 <https://github.com/zephyrproject-rtos/zephyr/pull/97871>`_).
* STM32 SAI: SAI disable function added
  (`#99058 <https://github.com/zephyrproject-rtos/zephyr/pull/99058>`_).
* STM32 SAI: fixed F4 clock source selection
  (`#103420 <https://github.com/zephyrproject-rtos/zephyr/pull/103420>`_).

Watchdog
********

* STM32 IWDG: Early Wakeup Interrupt support
  (`#100038 <https://github.com/zephyrproject-rtos/zephyr/pull/100038>`_).
* STM32N6: IWDG and WWDG support enabled
  (`#104896 <https://github.com/zephyrproject-rtos/zephyr/pull/104896>`_).
* STM32 WWDG: removed floating-point usage to reduce code footprint
  (`#98759 <https://github.com/zephyrproject-rtos/zephyr/pull/98759>`_).

MSPI (Multi-SPI / XSPI / OSPI / HYPERBUS)
******************************************

* New STM32 MSPI driver for XSPI/OSPI/HYPERBUS interfaces
  (`#96670 <https://github.com/zephyrproject-rtos/zephyr/pull/96670>`_).
* MSPI: simplified XSPI/OSPI configuration flow with MX25U sample support
  (`#104357 <https://github.com/zephyrproject-rtos/zephyr/pull/104357>`_).
* MSPI: max frequency handling refactored
  (`#101935 <https://github.com/zephyrproject-rtos/zephyr/pull/101935>`_).
* MSPI PSRAM: configurable refresh interval via Device Tree
  (`#102735 <https://github.com/zephyrproject-rtos/zephyr/pull/102735>`_).

UART / Serial
*************

* STM32 UART: fixed RX length computation in DMA cyclic mode
  (`#102596 <https://github.com/zephyrproject-rtos/zephyr/pull/102596>`_).
* STM32 UART: fixed not releasing ``irq_lock``
  (`#102916 <https://github.com/zephyrproject-rtos/zephyr/pull/102916>`_).
* STM32 UART: fixed locked PM state
  (`#100234 <https://github.com/zephyrproject-rtos/zephyr/pull/100234>`_).

STM32N6 (Cortex-M55 / TrustZone)
*********************************

* STM32N6: preparation for non-secure execution context
  (`#104765 <https://github.com/zephyrproject-rtos/zephyr/pull/104765>`_).
* STM32N6: centralized RIF (Resource Isolation Framework) configuration
  (`#100695 <https://github.com/zephyrproject-rtos/zephyr/pull/100695>`_).
* STM32N6: NPU (Neural Processing Unit) cache (CACHEAXI) dedicated DT node
  (`#102232 <https://github.com/zephyrproject-rtos/zephyr/pull/102232>`_).
* STM32N6: added USB2 DT nodes
  (`#100359 <https://github.com/zephyrproject-rtos/zephyr/pull/100359>`_).
* STM32N6: AXISRAM multi-region configuration fixes
  (`#104984 <https://github.com/zephyrproject-rtos/zephyr/pull/104984>`_,
  `#99637 <https://github.com/zephyrproject-rtos/zephyr/pull/99637>`_).
* STM32N6: SDIO HAL support via hal_stm32 update
  (`#104750 <https://github.com/zephyrproject-rtos/zephyr/pull/104750>`_).

STM32MP2 (Cortex-A and Cortex-M)
**********************************

* STM32MP2: I3C support added
  (`#100687 <https://github.com/zephyrproject-rtos/zephyr/pull/100687>`_).
* STM32MP2x: OpenAMP resource table section added to linker script
  (`#102721 <https://github.com/zephyrproject-rtos/zephyr/pull/102721>`_).
* STM32MP2x: linker scripts for MPx series cleaned up
  (`#102640 <https://github.com/zephyrproject-rtos/zephyr/pull/102640>`_).

Random Number Generator
***********************

* STM32 RNG: NIST SP800-90B health test support
  (`#99232 <https://github.com/zephyrproject-rtos/zephyr/pull/99232>`_).
* STM32 RNG: kept RNG clock running during PKA operation
  (`#100463 <https://github.com/zephyrproject-rtos/zephyr/pull/100463>`_).

DAC
***

* DAC driver API enhancements applied to STM32
  (`#104630 <https://github.com/zephyrproject-rtos/zephyr/pull/104630>`_).

Regulator / VREFBUF
********************

* STM32 VREFBUF regulator driver added
  (`#99304 <https://github.com/zephyrproject-rtos/zephyr/pull/99304>`_).
* STM32WB: VREFBUF support
  (`#104841 <https://github.com/zephyrproject-rtos/zephyr/pull/104841>`_).

HAL Module Updates
******************

* hal_stm32 updated for STM32CubeWBA v1.8.0 and v1.9.0
  (`#104135 <https://github.com/zephyrproject-rtos/zephyr/pull/104135>`_,
  `#105050 <https://github.com/zephyrproject-rtos/zephyr/pull/105050>`_).
* hal_stm32 updated with new H7RS / L4 / L5 / N6 STM32Cube packages
  (`#100941 <https://github.com/zephyrproject-rtos/zephyr/pull/100941>`_).
* hal_stm32 updated with new WBxx / WLxx STM32Cube packages
  (`#101078 <https://github.com/zephyrproject-rtos/zephyr/pull/101078>`_).
* hal_stm32 updated for STM32N6 SDIO HAL and SPI pinctrl slew-rate
  (`#104750 <https://github.com/zephyrproject-rtos/zephyr/pull/104750>`_,
  `#103348 <https://github.com/zephyrproject-rtos/zephyr/pull/103348>`_).
* STM32: migrated to generic LL headers everywhere
  (`#99012 <https://github.com/zephyrproject-rtos/zephyr/pull/99012>`_).
* STM32: ``ll_func_*`` prefix replaced by ``ll_*`` across drivers
  (`#103838 <https://github.com/zephyrproject-rtos/zephyr/pull/103838>`_).
* STM32: DT clock helper macros introduced for cleaner instance definitions
  (`#98995 <https://github.com/zephyrproject-rtos/zephyr/pull/98995>`_).
