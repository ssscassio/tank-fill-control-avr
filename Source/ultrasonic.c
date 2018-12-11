/*
 * ultrasonic.c
 *
 *  Created on: 11 de dez de 2018
 *      Author: ssscassio
 */
#include <avr/io.h>
#include <avr/interrupt.h> /* Interrupt stuff */
#include <util/delay.h>
#include "../Headers/ultrasonic.h"

static volatile int pulse = 0;
static volatile int echoStatus = 0;

void ultrasonic_init(void)
{
  ULTRASONIC_DDR &= ~(1 << ULTRASONIC_ECHO);   // Echo set as input
  ULTRASONIC_DDR |= (1 << ULTRASONIC_TRIGGER); // Trigger set as output

  /* Enable INT0 */
  EIMSK |= (1 << INT0);

  /* Interrupt request at falling edge for INT0 */
  EICRA |= (1 << ISC00);

  /* Enable global interrupt flag */
  sei();
}

int get_ultrassonic_value(void)
{
  ULTRASONIC_PORT |= (1 << ULTRASONIC_TRIGGER);
  _delay_us(15);
  ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIGGER);

  return pulse;
}

ISR(INT0_vect)
{

  if (echoStatus)
  {
    TCCR1B = 0;
    pulse = TCNT1;
    TCNT1 = 0;
    echoStatus = 0;
  }

  if (!echoStatus)
  {
    TCCR1B |= 1 << CS10;
    echoStatus = 1;
  }
}
