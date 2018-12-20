/*
 * uart.c
 *
 *  Created on: 22 de nov de 2018
 *      Author: ssscassio
 */

#include <stdio.h>
#include <avr/io.h>
#include "../Headers/uart.h"

void uart_init(void)
{
  UBRR0 = BAUDGEN;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0); /* Enable Reciever and Transmiter*/
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

int uart_putchar(char c, FILE *stream)
{
  while (!(UCSR0A & (1 << UDRE0))) /* Wait until data register empty. */
    ;
  UDR0 = c;
  return 0;
}

unsigned char uart_getchar(void)
{
  while (!(UCSR0A & (1 << RXC0))) /* Wait until data exists. */
    ;
  return UDR0;
}

static FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
//static FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

void printf_init(void)
{
  uart_init();
  stdout = &uart_output;
//  stdin = &uart_input;
}
