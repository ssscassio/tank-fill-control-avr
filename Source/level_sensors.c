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

uint16_t get_pins_percent_based_on_amount(void)
{
  return (99 * get_pins_amount() / 4);
}

uint16_t get_pins_percent_based_on_floater(void)
{
  switch (get_pins_amount())
  {
  case 0:
    return 0;
  case 1:
    return 10;
  case 2:
    return 22;
  case 3:
    return 60;
  case 4:
    return 80;
  }
}

uint16_t get_pins_percent_based_on_height(void)
{
  switch (get_pins_amount())
  {
  case 0:
    return 0;
  case 1:
    return 100 * PINS_HEIGHT_1 / TANK_FILLED_HEIGHT;
  case 2:
    return 100 * PINS_HEIGHT_2 / TANK_FILLED_HEIGHT;
  case 3:
    return 100 * PINS_HEIGHT_3 / TANK_FILLED_HEIGHT;
  case 4:
    return 100 * PINS_HEIGHT_4 / TANK_FILLED_HEIGHT;
  }
}

uint16_t get_pins_percent(int mode)
{
  /* Select PINS MODE */
  switch (mode)
  {
  case PINS_MODE_AMOUNT:
    return get_pins_percent_based_on_amount();
  case PINS_MODE_FLOATER:
    return get_pins_percent_based_on_floater();
  case PINS_MODE_HEIGHT:
    return get_pins_percent_based_on_height();
  default:
    return get_pins_percent_based_on_amount();
  }
}