/*
 * Copyright (c) 2016 Linaro Limited.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <pinmux.h>
#include <sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>

/* Include pinmux configuration generated file */
#include <st_stm32_pinmux_init.h>

/* pin assignments for 96boards Carbon board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_SPI_1
	{STM32_PIN_PA4, STM32F4_PINMUX_FUNC_PA4_SPI1_NSS},
	{STM32_PIN_PA5, STM32F4_PINMUX_FUNC_PA5_SPI1_SCK},
	{STM32_PIN_PA6, STM32F4_PINMUX_FUNC_PA6_SPI1_MISO},
	{STM32_PIN_PA7, STM32F4_PINMUX_FUNC_PA7_SPI1_MOSI},
#endif	/* CONFIG_SPI_1 */
#ifdef CONFIG_SPI_2
	{STM32_PIN_PB12, STM32F4_PINMUX_FUNC_PB12_SPI2_NSS},
	{STM32_PIN_PB13, STM32F4_PINMUX_FUNC_PB13_SPI2_SCK},
	{STM32_PIN_PB14, STM32F4_PINMUX_FUNC_PB14_SPI2_MISO},
	{STM32_PIN_PB15, STM32F4_PINMUX_FUNC_PB15_SPI2_MOSI},
#endif	/* CONFIG_SPI_2 */
#ifdef CONFIG_USB_DC_STM32
	{STM32_PIN_PA11, STM32F4_PINMUX_FUNC_PA11_OTG_FS_DM},
	{STM32_PIN_PA12, STM32F4_PINMUX_FUNC_PA12_OTG_FS_DP},
#endif	/* CONFIG_USB_DC_STM */
};

static int pinmux_stm32_init(struct device *port)
{
	ARG_UNUSED(port);

	/* Parse pinconf array provided above */
	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	/* Parse st_stm32_pinmux_pinconf array provided */
	/* in dts based generated file st_stm32_pinmux_init.h */
	stm32_setup_pins(st_stm32_pinmux_pinconf,
			 ARRAY_SIZE(st_stm32_pinmux_pinconf));
	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
		CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
