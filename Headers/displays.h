/*
 * displays.h
 *  Selection between the outputs from the shift register
 *  Show all displays with a frequency that will be not perceive
 *  by human
 *  Header file
 *  Created on: 12/6/2018
 *      Author: ssscassio
 */

#ifndef HEADERS_DISPLAYS_H_
#define HEADERS_DISPLAYS_H_

#include <avr/io.h>
#include "../Headers/shift_register.h"
#include "../Headers/leds_bar.h"
#include "../Headers/display_seven.h"

// Define Multiplexer Displays Pins and Ports
#define SHIFT_REGISTER_CONTROL PORTB
#define LEFT_DISPLAY PB5
#define RIGHT_DISPLAY PB4
#define LEDS_BAR_DISPLAY PB3

// Define Multiplexer Displays Actions
#define CLEAR_ALL_DISPLAYS() SHIFT_REGISTER_CONTROL &= ~((1 << LEFT_DISPLAY) | (1 << RIGHT_DISPLAY) | (1 << LEDS_BAR_DISPLAY))
#define SHOW_LEFT() SHIFT_REGISTER_CONTROL |= (1 << LEFT_DISPLAY)
#define SHOW_RIGHT() SHIFT_REGISTER_CONTROL |= (1 << RIGHT_DISPLAY)
#define SHOW_LEDS_BAR() SHIFT_REGISTER_CONTROL |= (1 << LEDS_BAR_DISPLAY)

// Define Multiplexer Displays Functions
void displays_init(void);

void show_displays(unsigned char percent);

#endif /* HEADERS_DISPLAYS_H_ */
