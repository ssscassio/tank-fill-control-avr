/*
 * sonar.h
 *
 *  Created on: 11 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_SONAR_H_
#define HEADERS_SONAR_H_

#include "../Headers/ultrasonic.h"

#define DISTANCE_FACTOR 1 / 58 //TODO : Calcular valor
#define HIGHER_DISTANCE 100 //TODO : Calcular valor
#define LOWER_DISTANCE 5 //TODO : Calcular valor

void sonar_init(void);

int get_sonar_percent(void);

int get_sonar_distance(void);

int get_sonar_value(void);

uint16_t convert_distance_to_percent(int distance);

#endif /* HEADERS_SONAR_H_ */
