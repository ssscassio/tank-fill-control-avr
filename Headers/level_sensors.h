/*
 * level_sensors.h
 *
 *  Header file
 *  Created on: 15 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_LEVEL_SENSOR_H_
#define HEADERS_LEVEL_SENSOR_H_

#include <avr/io.h>

#define LEVEL_SENSOR_DDR DDRD
#define LEVEL_SENSOR_PORT PORTD
#define LEVEL_SENSOR_1 PD3
#define LEVEL_SENSOR_2 PD4
#define LEVEL_SENSOR_3 PD5
#define LEVEL_SENSOR_4 PD6
#define LEVEL_SENSOR_PIN PIND

// Heights of Pins in centimeters
#define TANK_FILLED_HEIGHT 13.5
#define PINS_HEIGHT_4 11.5
#define PINS_HEIGHT_3 8
#define PINS_HEIGHT_2 4.3
#define PINS_HEIGHT_1 1.2

// Pins Modes
#define PINS_MODE_AMOUNT 0
#define PINS_MODE_FLOATER 1
#define PINS_MODE_HEIGHT 2

// Declare Level sensors Functions
void level_sensors_init(void);

uint16_t get_pins_amount(void);

uint16_t get_pins_percent(int mode);

uint16_t get_pins_percent_based_on_amount(void);

uint16_t get_pins_percent_based_on_floater(void);

uint16_t get_pins_percent_based_on_height(void);

#endif /* HEADERS_LEVEL_SENSOR_H_ */
