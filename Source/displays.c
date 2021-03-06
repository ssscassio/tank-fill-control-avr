/*
 * displays.c
 *
 *  Created on: 6 de dez de 2018
 *      Author: Cássio Santos
 */
#include <util/delay.h>
#include "../Headers/displays.h"

void displays_init(void)
{
  shift_register_init();
  /* Configure display control as output */
  DDRB |= (1 << LEFT_DISPLAY) | (1 << RIGHT_DISPLAY) | (1 << LEDS_BAR_DISPLAY);
  /* Set all output pins as low */
  SHIFT_REGISTER_CONTROL = 0x00;
}

/*
 * Multiplex between the two seven segments displays and the leds vector 
 */
void show_displays(unsigned char percent)
{
  leds_bar_output(percent);
  CLEAR_ALL_DISPLAYS();
  SHOW_LEDS_BAR();
  _delay_ms(5);
  seven_left(percent / 10);
  CLEAR_ALL_DISPLAYS();
  SHOW_LEFT();
  _delay_ms(5);
  seven_right(percent % 10);
  CLEAR_ALL_DISPLAYS();
  SHOW_RIGHT();
  _delay_ms(5);
}
