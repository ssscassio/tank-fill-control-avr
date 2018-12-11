/*
 * floater.h
 *
 *  Created on: 7 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_FLOATER_H_
#define HEADERS_FLOATER_H_

#include <avr/io.h>
#include "../Headers/adc.h"

#define FLOATER PC3
#define HIGHER_LEVEL 800
#define LOWER_LEVEL 200

uint16_t convert_adc_to_percent(uint16_t adc_value);

void floater_init(void);

uint16_t get_tank_percent(void);

#endif /* HEADERS_FLOATER_H_ */
