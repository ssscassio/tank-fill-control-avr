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

static volatile unsigned long int pulse = 0;
static volatile int echoStatus = 0;

void ultrasonic_init(void)
{
  ULTRASONIC_DDR &= ~(1 << ULTRASONIC_ECHO);   // Echo set as input
  ULTRASONIC_DDR |= (1 << ULTRASONIC_TRIGGER); // Trigger set as output

  //  /* Enable INT0 */
  //  EIMSK |= (1 << INT0);
  //
  //  /* Interrupt request at falling edge for INT0 */
  //  EICRA |= (1 << ISC00);
  //
  //  /* Enable global interrupt flag */
  sei();
}

int get_ultrassonic_value(void)
{
  echoStatus = 0;
  pulse = 0;

  //  ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIGGER);
  //  _delay_us(2);
  ULTRASONIC_PORT |= (1 << ULTRASONIC_TRIGGER);
  _delay_us(10);
  ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIGGER);
  //  while(!(ULTRASONIC_PIN & (1<< ULTRASONIC_ECHO))){
  //    echoStatus += 1;
  //    _delay_us(1);
  //    if(echoStatus > 10000){
  //      break;
  //    }
  //  }
  //  if(echoStatus <100000){
  while (ULTRASONIC_PIN & (1 << ULTRASONIC_ECHO))
  {
    _delay_us(1);
    pulse += 1;
  }
  //  }
  //
  return pulse;
}

//ISR(INT0_vect)
//{
//
//  if (echoStatus)
//  {
//    TCCR1B = 0;
//    pulse = TCNT1;
//    TCNT1 = 0;
//    echoStatus = 0;
//  }
//
//  if (!echoStatus)
//  {
//    TCCR1B |= 1 << CS10;
//    echoStatus = 1;
//  }
//}
