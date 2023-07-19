/*
 * Copyright (c) 2023 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
#define LOG_LEVEL CONFIG_SOC_LOG_LEVEL
LOG_MODULE_REGISTER(ll_sys_if);

#ifdef CONFIG_STM32WBA_DBG_BLE_LL_SYS_IF
#define LOG_SOC_DBG LOG_DBG
#else
#define LOG_SOC_DBG(...)
#endif

#include "ll_intf.h"
#include "ll_sys.h"
#include "adc_ctrl.h"
#include "linklayer_plat.h"

extern struct k_mutex ble_ctlr_stack_mutex;
extern struct k_work_q ble_ctlr_work_q;
struct k_work ll_sys_work, ll_sys_temp_work;

#if (USE_TEMPERATURE_BASED_RADIO_CALIBRATION == 1)

void ll_sys_bg_temperature_measurement(void);
static void request_temperature_measurement(void);

#endif /* USE_TEMPERATURE_BASED_RADIO_CALIBRATION */

void ll_sys_schedule_bg_process(void)
{
	LOG_SOC_DBG("");

	k_work_submit_to_queue(&ble_ctlr_work_q, &ll_sys_work);
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

	k_work_submit_to_queue(&ble_ctlr_work_q, &ll_sys_temp_work);
}

void request_temperature_measurement(void)
{
	int16_t temperature_value = 0;
	uint32_t basepri_value = __get_BASEPRI();

	LOG_SOC_DBG("");

	__set_BASEPRI_MAX(RCC_INTR_PRIO << 4);

	adc_ctrl_req(SYS_ADC_LL_EVT, ADC_ON);
	temperature_value = adc_ctrl_request_temperature();
	adc_ctrl_req(SYS_ADC_LL_EVT, ADC_OFF);
	ll_intf_set_temperature_value(temperature_value);

	__set_BASEPRI(basepri_value);
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
