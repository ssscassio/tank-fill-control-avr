/*
 * floater.h
 *
 *  Created on: 12/7/2018
 *      Author: ssscassio
 */

#ifndef HEADERS_FLOATER_H_
#define HEADERS_FLOATER_H_

#include <avr/io.h>
#include "../Headers/adc.h"

// Define floater Pin
#define FLOATER PC3

// Define floater Maximum and minimum range
#define HIGHER_LEVEL 720
#define LOWER_LEVEL 0

// Declare floater Functions
uint16_t get_floater_percent(void);

void floater_init(void);

uint16_t convert_adc_to_percent(uint16_t adc_value);

uint16_t get_floater_value(void);

#endif /* HEADERS_FLOATER_H_ */
