/*
 * serial_printf.h
 *  Redirection of the printf stream to the AVR serial port
 *  Header file
 *  Created on: 09/13/2016
 *      Author: jpsousa@fe.up.pt
 */

#ifndef SERIAL_PRINTF_H_
#define SERIAL_PRINTF_H_

#include <stdio.h>

#define F_CPU 16000000UL                    /* CPU Frequency    */

#define BAUD 57600UL                        /* Baud Rate        */
#define BAUDGEN ((F_CPU / (16 * BAUD)) - 1) /* Divider          */

int usart_putchar(char c, FILE *stream);

void printf_init(void);

#endif /* SERIAL_H_ */
