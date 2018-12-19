/*
 * level_sensors.h
 *
 *  Created on: 15 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_LEVEL_SENSOR_H_
#define HEADERS_LEVEL_SENSOR_H_

#define LEVEL_SENSOR_DDR DDRD
#define LEVEL_SENSOR_PORT PORTD
#define LEVEL_SENSOR_1 PD3
#define LEVEL_SENSOR_2 PD4
#define LEVEL_SENSOR_3 PD5
#define LEVEL_SENSOR_4 PD6
#define LEVEL_SENSOR_PIN PIND

void level_sensors_init(void);

uint16_t get_pins_amount(void);

uint16_t get_pins_percent(void);

#endif /* HEADERS_LEVEL_SENSOR_H_ */
