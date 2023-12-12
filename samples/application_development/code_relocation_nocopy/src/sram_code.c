/*
 * Copyright (c) 2022 Carlo Caione <ccaione@baylibre.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

uint32_t var_sram_data = 10U;

uint8_t firmware_image[10] = {0,1,2,3,4,5,6,7,8,9};

void function_in_sram(void)
{
	printk("Address of %s %p\n", __func__, &function_in_sram);
	printk("Address of var_sram_data %p (%d)\n", &var_sram_data, var_sram_data);
	printk("Address of firmware_image %p \n", &firmware_image);

	for (uint32_t i = 0U; i <10; i++) {
		printk("firmware_image[%d]:%d\n", i, firmware_image[i]);
	}
}
