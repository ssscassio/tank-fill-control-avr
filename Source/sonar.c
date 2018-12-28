/*
 * sonar.c
 *
 *  Created on: 11 de dez de 2018
 *      Author: Cássio Santos
 */

#include <avr/io.h>
#include "../Headers/sonar.h"

void sonar_init(void)
{
  ultrasonic_init();
}

uint16_t convert_distance_to_percent(int distance)
{
  return (distance - LOWER_DISTANCE) * 100 / (HIGHER_DISTANCE - LOWER_DISTANCE);
}

int get_sonar_percent(void)
{
  {
    uint16_t sonar_distance = get_sonar_distance();
    if (sonar_distance <= LOWER_DISTANCE)
      return 0;
    else if (sonar_distance >= HIGHER_DISTANCE)
      return 99;
    else
      return convert_distance_to_percent(sonar_distance);
  }
}

int get_sonar_distance(void)
{
  return get_ultrassonic_value() * DISTANCE_FACTOR;
}

int get_sonar_value(void)
{
  return get_ultrassonic_value();
}
