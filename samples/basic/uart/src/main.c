/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// #include <zephyr.h>
// #include <board.h>
// #include <device.h>
// #include <gpio.h>



#include <zephyr.h>
#include <misc/printk.h>
#include <uart.h>

int main(void) {

	struct device *uartGPS;
	uartGPS = device_get_binding(CONFIG_UART_STM32_PORT_1_NAME);

	printk("Start\n");

	while (1) {
		unsigned char recvChar;
		while (uart_poll_in(uartGPS, &recvChar) < 0)
			;
		// uart_poll_out(uartGPS, recvChar);
		printk("%c", recvChar);

		// if ((recvChar == '\n') || (recvChar == '\r')) {
		// 	printk("Stop\n");
		// 	break;
		// }
	}

	// while (1) {
	// 	unsigned char msg;
	// 	uart_poll_in(uartGPS, &msg);
	//
	// 	printk("%c", msg);
	// }


	return 0;
}

/* Change this if you have an LED connected to a custom port */
// #define PORT	LED0_GPIO_PORT
//
// /* Change this if you have an LED connected to a custom pin */
// #define LED	LED0_GPIO_PIN
//
// /* 1000 msec = 1 sec */
// #define SLEEP_TIME 	1000
//
// void main(void)
// {
// 	int cnt = 0;
// 	struct device *dev;
//
// 	dev = device_get_binding(PORT);
// 	/* Set LED pin as output */
// 	gpio_pin_configure(dev, LED, GPIO_DIR_OUT);
//
// 	while (1) {
// 		/* Set pin to HIGH/LOW every 1 second */
// 		gpio_pin_write(dev, LED, cnt % 2);
// 		cnt++;
// 		k_sleep(SLEEP_TIME);
// 	}
// }
