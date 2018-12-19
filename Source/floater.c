/*
 * floater.c
 *
 *  Created on: 7 de dez de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/floater.h"

uint16_t get_floater_percent(void)
{
  uint16_t adc_floater = adc_read(FLOATER);
  if (adc_floater <= LOWER_LEVEL)
    return 99;
  else if (adc_floater >= HIGHER_LEVEL)
    return 0;
  else
    return 99 - convert_adc_to_percent(adc_floater);
}

void floater_init(void)
{
  adc_init();
}

uint16_t convert_adc_to_percent(uint16_t adc_value)
{
  return 99 - (adc_value - LOWER_LEVEL) * 100 / (HIGHER_LEVEL - LOWER_LEVEL);
}

uint16_t get_floater_value(void)
{
  return adc_read(FLOATER);
}
