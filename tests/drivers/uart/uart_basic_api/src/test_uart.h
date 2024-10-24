/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief UART cases header file
 *
 * Header file for UART cases
 */

#ifndef __TEST_UART_H__
#define __TEST_UART_H__

#include <uart.h>
#include <ztest.h>

#define UART_DEVICE_NAME CONFIG_UART_STM32_PORT_1_NAME

void test_uart_poll_out(void);
void test_uart_fifo_fill(void);
void test_uart_fifo_read(void);
void test_uart_poll_in(void);

#endif /* __TEST_UART_H__ */
