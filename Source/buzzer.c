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

void buzzer_state_machine(uint16_t percent)
{
  if (percent >= UPPER_THRESHOLD_PERCENT || percent <= LOWER_THRESHOLD_PERCENT)
    BuzzerOn();
}
