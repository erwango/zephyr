/*
 * Copyright (c) 2023 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

#include <zephyr/logging/log.h>
#define LOG_LEVEL CONFIG_SOC_LOG_LEVEL
LOG_MODULE_REGISTER(ll_sys_if);

#ifdef CONFIG_STM32WBA_DBG_BLE_LL_SYS_IF
#define LOG_SOC_DBG LOG_DBG
#else
#define LOG_SOC_DBG(...)
#endif

#include "app_conf.h"
#include "ll_intf.h"
#include "ll_sys.h"
#include "linklayer_plat.h"

extern struct k_mutex ble_ctlr_stack_mutex;
extern struct k_work_q ll_work_q;
struct k_work ll_sys_work, ll_sys_temp_work;

#if (USE_TEMPERATURE_BASED_RADIO_CALIBRATION == 1)

void ll_sys_bg_temperature_measurement(void);
static void request_temperature_measurement(void);
const struct device *const dietemp_dev = DEVICE_DT_GET(DT_ALIAS(die_temp0));

#endif /* USE_TEMPERATURE_BASED_RADIO_CALIBRATION */

void ll_sys_schedule_bg_process(void)
{
	LOG_SOC_DBG("");

	k_work_submit_to_queue(&ll_work_q, &ll_sys_work);
}

}

static void ll_sys_bg_process_handler(struct k_work *work)
{
	k_mutex_lock(&ble_ctlr_stack_mutex, K_FOREVER);
	ll_sys_bg_process();
	k_mutex_unlock(&ble_ctlr_stack_mutex);
}

void ll_sys_bg_process_init(void) {
	k_work_init(&ll_sys_work, &ll_sys_bg_process_handler);
}

void LINKLAYER_PLAT_EnableOSContextSwitch(void)
{
	LOG_SOC_DBG("");
}

void LINKLAYER_PLAT_DisableOSContextSwitch(void)
{
	LOG_SOC_DBG("");
}

#if (USE_TEMPERATURE_BASED_RADIO_CALIBRATION == 1)

void ll_sys_bg_temperature_measurement(void)
{
	LOG_SOC_DBG("");

	k_work_submit_to_queue(&ll_work_q, &ll_sys_temp_work);
}

void request_temperature_measurement(void)
{
#if 0
	struct sensor_value val;
	uint32_t basepri_value;
	int rc;

	LOG_SOC_DBG("");

	if (!device_is_ready(dietemp_dev)) {
		printk("Temperature sensor is not ready\n");
		return;
	}

	/* TBD: Is that really required ? */
	basepri_value = __get_BASEPRI();
	__set_BASEPRI_MAX(RCC_INTR_PRIO << 4);

	/* fetch sensor samples */
	rc = sensor_sample_fetch(dietemp_dev);
	if (rc) {
		printk("Failed to fetch sample (%d)\n", rc);
	}

	rc = sensor_channel_get(dietemp_dev, SENSOR_CHAN_DIE_TEMP, &val);
	if (rc) {
		printk("Failed to get data (%d)\n", rc);
	}

	ll_intf_set_temperature_value((uint32_t)val.val1);

	__set_BASEPRI(basepri_value);
#endif
}

static void request_temperature_measurement_handler(struct k_work *work)
{

	LOG_SOC_DBG("");
	k_mutex_lock(&ble_ctlr_stack_mutex, K_FOREVER);
	request_temperature_measurement();
	k_mutex_unlock(&ble_ctlr_stack_mutex);
}

static void ll_sys_bg_temperature_measurement_init(void) {
	k_work_init(&ll_sys_temp_work, &request_temperature_measurement_handler);
}

#endif /* USE_TEMPERATURE_BASED_RADIO_CALIBRATION */

void ll_sys_config_params(void)
{
	LOG_SOC_DBG("");

	ll_intf_config_ll_ctx_params(USE_RADIO_LOW_ISR, NEXT_EVENT_SCHEDULING_FROM_ISR);

#if (USE_TEMPERATURE_BASED_RADIO_CALIBRATION == 1)

	ll_sys_bg_temperature_measurement_init();
	ll_intf_set_temperature_sensor_state();
#endif /* USE_TEMPERATURE_BASED_RADIO_CALIBRATION */
}
