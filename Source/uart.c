/*
 * uart.c
 *
 *  Created on: 17 de nov de 2018
 *      Author: ssscassio
 */
#define BAUD 9600
#include <avr/io.h>
#include <util/setbaud.h>
#include <stdio.h>


void uart_init(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
}

char uart_get_char(void) {
    loop_until_bit_is_set(UCSR0A, RXC0); /* Wait until data exists. */
    return UDR0;
}

void uart_send_char(uint8_t byte) { 
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = byte; 
} 

void uart_send_string(char * str, unsigned int len) { 
  while (len--) { 
    uart_send_char(*str++); 
  } 
} 


