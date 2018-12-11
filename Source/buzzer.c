/*
 * buzzer.c
 *
 *  Created on: 7 de dez de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/buzzer.h"

void buzzer_init()
{
  BUZZER_DDR |= (1 << BUZZER);
}

void buzzer_dispatcher(unsigned char percent)
{
  if (percent >= FULL_THRESHOLD_PERCENT || percent <= EMPTY_THRESHOLD_PERCENT)
    BuzzerOn();
}
