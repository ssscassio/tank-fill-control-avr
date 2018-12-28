/*
 * control_selector.h
 *
 *  Header File
 *  Created on: 19 de dez de 2018
 *      Author: Cássio Santos
 */

#ifndef HEADERS_CONTROL_SELECTOR_H_
#define HEADERS_CONTROL_SELECTOR_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define CONTROL_SELECTOR PD2
#define CONTROL_SELECTOR_DDR DDRD
#define CONTROL_SELECTOR_PORT PORTD

// Declare control selector Functions
uint8_t control_selector(uint8_t switch_count);

void control_selector_init(void);

#endif /* HEADERS_CONTROL_SELECTOR_H_ */
