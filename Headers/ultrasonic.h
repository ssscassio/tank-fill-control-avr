/*
 * ultrasonic.h
 *
 *  Header File
 *  Created on: 19 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_ULTRASONIC_H_
#define HEADERS_ULTRASONIC_H_

#include <avr/io.h>
#include <util/delay.h>

#define ULTRASONIC_DDR DDRC
#define ULTRASONIC_PORT PORTC
#define ULTRASONIC_TRIGGER PC4
#define ULTRASONIC_ECHO PC5
#define ULTRASONIC_PIN PINC

void ultrasonic_init(void);

int get_ultrassonic_value(void);

#endif /* HEADERS_ULTRASONIC_H_ */
