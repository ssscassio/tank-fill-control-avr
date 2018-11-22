/*
 * uart.h
 *
 *  Created on: 17 de nov de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_UART_H_
#define HEADERS_UART_H_

#include <stdio.h>

void uart_init(void);
void uart_send_string(char c, FILE *stream);
void uart_send_char(uint8_t byte);
void printf_init(void);

#endif /* HEADERS_UART_H_ */
