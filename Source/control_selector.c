/*
 * control_selector.c
 *
 *  Created on: 19 de dez de 2018
 *      Author: Cássio Santos
 */

#include <avr/io.h>
#include "../Headers/control_selector.h"

volatile static uint8_t button_count = 0;

uint8_t control_selector(uint8_t switch_count)
{
  return button_count % switch_count;
}

/**
 * Initialize interrupt at Control selector Pin
 */
void control_selector_init(void)
{
  /* Sensor selector as input with internal pull-up */
  CONTROL_SELECTOR_DDR &= ~(1 << CONTROL_SELECTOR); // Write 0 in desired DDR register
  CONTROL_SELECTOR_PORT |= (1 << CONTROL_SELECTOR); // Write 1 in desired Port register

  /* Interrupt request at falling edge for INT0(PD2) */
  EICRA |= (1 << ISC01);

  /* Enable INT0 */
  EIMSK |= (1 << INT0);

  /* Enable Interrupts */
  sei();
}

/* Interrupt Service Routine for INT0 */
ISR(INT0_vect)
{
  button_count++;
}
