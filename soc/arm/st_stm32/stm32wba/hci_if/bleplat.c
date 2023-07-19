/*
 * Copyright (c) 2023 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/irq.h>
#include <zephyr/drivers/entropy.h>
#include <zephyr/logging/log.h>
#define LOG_LEVEL CONFIG_SOC_LOG_LEVEL
LOG_MODULE_REGISTER(bleplat);

#include "app_common.h"
#include "bleplat.h"
#include "bpka.h"
#include "linklayer_plat.h"

#ifdef CONFIG_STM32WBA_DBG_BLE_PLAT
#define LOG_SOC_DBG LOG_DBG
#else
#define LOG_SOC_DBG(...)
#endif

RAMCFG_HandleTypeDef hramcfg_SRAM1;
RTC_HandleTypeDef hrtc;
const struct device *rng_dev;

void BLEPLAT_Init(void)
{
	LOG_DBG("");

	BPKA_Reset();

	rng_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_entropy));
	if (!device_is_ready(rng_dev)) {
		LOG_ERR("error: random device not ready");
	}
}

void BLEPLAT_RngGet(uint8_t n, uint32_t *val)
{
	LINKLAYER_PLAT_GetRNG((uint8_t *)val, 4 * n);

	LOG_SOC_DBG("n %d, val: %p", n, (void *)val);
	LOG_HEXDUMP_DBG(val, 4 * n, "RNG:");
}

int BLEPLAT_PkaStartP256Key(const uint32_t *local_private_key)
{
	return BPKA_StartP256Key(local_private_key);
}

void BLEPLAT_PkaReadP256Key(uint32_t *local_public_key)
{
	BPKA_ReadP256Key(local_public_key);
}

int BLEPLAT_PkaStartDhKey(const uint32_t *local_private_key, const uint32_t *remote_public_key)
{
	return BPKA_StartDhKey(local_private_key, remote_public_key);
}

int BLEPLAT_PkaReadDhKey(uint32_t *dh_key)
{
	return BPKA_ReadDhKey(dh_key);
}

void BPKACB_Complete(void)
{
	BLEPLATCB_PkaComplete();
}

void MX_RAMCFG_Init(void)
{
	/* Initialize RAMCFG SRAM1 */
	hramcfg_SRAM1.Instance = RAMCFG_SRAM1;
	if (HAL_RAMCFG_Init(&hramcfg_SRAM1) != HAL_OK) {
		LOG_ERR("Could not init RAMCFG");
	}
}

void *ble_memcpy(void *dst, const void *src, short unsigned int n)
{
	memcpy(dst, src, (size_t)n);

	return dst;
}

void *ble_memset(void *dst, uint8_t c, uint16_t n)
{
	memset((void *)dst, (int)c, (size_t)n);

	return dst;
}

int8_t ble_memcmp(const void *a, const void *b, uint16_t n)
{
	return (int8_t)memcmp(a, b, (size_t)n);
}

ll_sys_status_t ll_sys_dp_slp_exit(void)
{
	return 0;
}

ll_sys_status_t ll_sys_dp_slp_init(void)
{
	return 0;
}

void Error_Handler(void) {
	LOG_ERR("");
}

void scm_notifyradiostate(void) {}
void HW_RNG_DisableClock(uint8_t) {}
void HW_RNG_EnableClock(uint8_t) {}
