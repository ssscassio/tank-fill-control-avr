/*
 * motor.c
 *
 *  Created on: 13 de dez de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/motor.h"

typedef enum
{
  filling_state,
  waiting_state
} States;

volatile States state = filling_state; // Initial state of state machine

void filling(uint16_t percent);
void waiting(uint16_t percent);

void motor_init()
{
  /* Declare Motor as ouput */
  MOTOR_DDR |= (1 << MOTOR);
}

void motor_dispatcher(uint16_t percent)
{
  switch (state)
  {
  case filling_state:
    filling(percent);
    break;
  case waiting_state:
    waiting(percent);
    break;
  }
}

void filling(uint16_t percent)
{
  MOTOR_PORT |= (1 << MOTOR);

  if (percent > HIGHER_LIMIAR_MOTOR)
  {
    state = waiting_state;
  }
}

void waiting(uint16_t percent)
{
  MOTOR_PORT &= ~(1 << MOTOR);

  if (percent < LOWER_LIMIAR_MOTOR)
  {
    state = filling_state;
  }
}
