/*
 * ultrasonic_interrupt.c
 *
 *  Created on: 11 de dez de 2018
 *      Author: Cássio Santos
 */
#include <avr/io.h>
#include <avr/interrupt.h> /* Interrupt stuff */
#include <util/delay.h>
#include "../Headers/ultrasonic_interrupt.h"

static volatile unsigned long int pulse = 0;
static volatile int echoStatus = 0;

void ultrasonic_init_interrupt(void)
{
  ULTRASONIC_DDR &= ~(1 << ULTRASONIC_ECHO);   // Echo set as input
  ULTRASONIC_DDR |= (1 << ULTRASONIC_TRIGGER); // Trigger set as output

  /* Interrupt request at any edge for INT1 */
  EICRA |= (1 << ISC10);

  /* Enable INT0 */
  EIMSK |= (1 << INT1);

  /* Enable global interrupt flag */
  sei();
}

int get_ultrassonic_value_interrupt(void)
{
  //  ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIGGER);
  //  _delay_us(2);
  ULTRASONIC_PORT |= (1 << ULTRASONIC_TRIGGER);
  _delay_us(10);
  ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIGGER);

  return pulse;
}

ISR(INT1_vect)
{
  if (echoStatus == 1)
  {
    TCCR1B &= ~(1 << CS10);
    pulse = TCNT1;
    TCNT1 = 0;
    echoStatus = 0;
  }

  if (echoStatus == 0)
  {
    TCCR1B |= (1 << CS10);
    echoStatus = 1;
  }
}
