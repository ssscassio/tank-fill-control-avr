/*
 * ultrasonic_interrupt.h
 *
 *  Created on: 11 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_ULTRASONIC_H_
#define HEADERS_ULTRASONIC_H_

#include <avr/io.h>
#include <avr/interrupt.h> /* Interrupt stuff */
#include <util/delay.h>

#define ULTRASONIC_DDR DDRD
#define ULTRASONIC_PORT PORTD
#define ULTRASONIC_TRIGGER PD7
#define ULTRASONIC_ECHO PD3
#define ULTRASONIC_PIN PIND

void ultrasonic_init_interrupt(void);

int get_ultrassonic_value_interrupt(void);

#endif /* HEADERS_ULTRASONIC_H_ */
