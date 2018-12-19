/*
 * ultrasonic.c
 *
 *  Created on: 19 de dez de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/ultrasonic.h"

static volatile unsigned long int pulse = 0;
static volatile int aux = 0;

void ultrasonic_init(void)
{
  ULTRASONIC_DDR &= ~(1 << ULTRASONIC_ECHO);   // Echo set as input
  ULTRASONIC_DDR |= (1 << ULTRASONIC_TRIGGER); // Trigger set as output
}

int get_ultrassonic_value(void)
{
  pulse = 0;
  aux = 0;
  ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIGGER);
  _delay_us(2);
  ULTRASONIC_PORT |= (1 << ULTRASONIC_TRIGGER);
  _delay_us(10);
  ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIGGER);
  while (!(ULTRASONIC_PIN & (1 << ULTRASONIC_ECHO)) && aux < 100000)
  {
    _delay_us(1);
    aux++;
  }
  pulse += aux;
  while (ULTRASONIC_PIN & (1 << ULTRASONIC_ECHO))
  {
    _delay_us(1);
    pulse += 1;
  }
  return pulse;
}
