/*
 * floater.h
 *
 *  Created on: 12/7/2018
 *      Author: Cássio Santos
 */

#ifndef HEADERS_FLOATER_H_
#define HEADERS_FLOATER_H_

#include <avr/io.h>
#include "../Headers/adc.h"

// Define floater Pin
#define FLOATER PC3

// Define floater Maximum and minimum range
#define HIGHER_LEVEL 900
#define LOWER_LEVEL 0

// Declare floater Functions
uint32_t get_floater_percent(void);

void floater_init(void);

uint32_t convert_adc_to_percent(uint32_t adc_value);

uint32_t get_floater_value(void);

#endif /* HEADERS_FLOATER_H_ */
