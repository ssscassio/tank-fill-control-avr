/*
 * leds_bar.h
 *  Buffer the Leds bar output to the shift register pins
 *  based on the information of the tank's empty percent
 *  Header File
 *  Created on: 11/8/2018
 *      Author: ssscassio
 */

#ifndef HEADERS_LEDS_BAR_H_
#define HEADERS_LEDS_BAR_H_

#include "../Headers/shift_register.h"

void leds_bar_output(unsigned char percent);

#endif /* HEADERS_LEDS_BAR_H_ */
