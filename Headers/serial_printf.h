/*
 * serial.h
 *  Redirection of the printf stream to the AVR serial port
 *  Header file
 *  Created on: 13/09/2016
 *      Author: jpsousa@fe.up.pt
 */

#ifndef SERIAL_PRINTF_H_
#define SERIAL_PRINTF_H_

#include <stdio.h>

#define F_CPU 16000000UL

#define BAUD 57600UL                        /* baud rate */
#define BAUDGEN ((F_CPU / (16 * BAUD)) - 1) /* divider   */

int /* usart */ _putchar(char c, FILE *stream);

void printf_init(void);

#endif /* SERIAL_H_ */
