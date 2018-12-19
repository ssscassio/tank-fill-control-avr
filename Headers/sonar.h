/*
 * sonar.h
 *
 *  Created on: 11 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_SONAR_H_
#define HEADERS_SONAR_H_

#include "../Headers/ultrasonic.h"

#define DISTANCE_FACTOR 21.5/712
#define HIGHER_DISTANCE 712*DISTANCE_FACTOR
#define LOWER_DISTANCE 404*DISTANCE_FACTOR

void sonar_init(void);

int get_sonar_percent(void);

int get_sonar_distance(void);

int get_sonar_value(void);

uint16_t convert_distance_to_percent(int distance);

#endif /* HEADERS_SONAR_H_ */
