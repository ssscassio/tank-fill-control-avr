/*
 * floater.c
 *
 *  Created on: 7 de dez de 2018
 *      Author: Cássio Santos
 */

#include <avr/io.h>
#include "../Headers/floater.h"

void floater_init(void)
{
  adc_init();
}

uint32_t get_floater_percent(void)
{
  uint32_t adc_floater = adc_read(FLOATER);
  if (adc_floater < LOWER_LEVEL)
    return 0;
  else if (adc_floater > HIGHER_LEVEL)
    return 99;
  else
    return convert_adc_to_percent(adc_floater);
}

/**
 * Convert a adc value to a percentage based on the tank's thresholds
 */
uint32_t convert_adc_to_percent(uint32_t adc_value)
{
  return (adc_value - LOWER_LEVEL) * 99 / (HIGHER_LEVEL - LOWER_LEVEL);
}

uint32_t get_floater_value(void)
{
  return adc_read(FLOATER);
}
