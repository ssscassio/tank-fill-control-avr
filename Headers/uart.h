/*
 * uart.h
 *
 *  Header File
 *  Created on: 22 de nov de 2018
 *      Author: Cássio Santos
 */
#ifndef HEADERS_UART_H_
#define HEADERS_UART_H_

#include <stdio.h>

#define F_CPU 16000000UL /* CPU Frequency */

#define BAUD 57600UL                        /* Baud Rate */
#define BAUDGEN ((F_CPU / (16 * BAUD)) - 1) /* Divider   */

// Declare Uart communication Functions
int uart_putchar(char c, FILE *stream);

unsigned char uart_getchar(void);

void printf_init(void);

#endif /* HEADERS_UART_H_ */
