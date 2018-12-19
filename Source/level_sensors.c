/*
 * level_sensors.c
 *
 *  Created on: 15 de dez de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/level_sensors.h"

void level_sensors_init(void)
{
  // Level Pins as Input
  LEVEL_SENSOR_DDR &= ~((1 << LEVEL_SENSOR_1) | (1 << LEVEL_SENSOR_2) | (1 << LEVEL_SENSOR_3) | (1 << LEVEL_SENSOR_4));
}

uint16_t get_pins_amount(void)
{
  uint16_t pinsAmount = 0;

  // Check if Pin is low (with water)
  if (!(LEVEL_SENSOR_PIN & (1 << LEVEL_SENSOR_1)))
    pinsAmount++;
  if (!(LEVEL_SENSOR_PIN & (1 << LEVEL_SENSOR_2)))
    pinsAmount++;
  if (!(LEVEL_SENSOR_PIN & (1 << LEVEL_SENSOR_3)))
    pinsAmount++;
  if (!(LEVEL_SENSOR_PIN & (1 << LEVEL_SENSOR_4)))
    pinsAmount++;
  return pinsAmount;
}

uint16_t get_pins_percent(void)
{
  return 100 * get_pins_amount() / 4;
}
