/*
 * control_selector.h
 *
 *  Created on: 19 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_CONTROL_SELECTOR_H_
#define HEADERS_CONTROL_SELECTOR_H_

#include <avr/io.h>
#include <avr/interrupt.h> /* Interrupt stuff */

#define CONTROL_SELECTOR PD2
#define CONTROL_SELECTOR_DDR DDRD
#define CONTROL_SELECTOR_PORT PORTD

int control_selector(int switch_count);

void control_selector_init(void);

#endif /* HEADERS_CONTROL_SELECTOR_H_ */
