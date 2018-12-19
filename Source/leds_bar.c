/*
 * leds_bar.c
 *
 *  Created on: 22 de nov de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/leds_bar.h"

void leds_bar_output(unsigned char percent)
{
    int leds_count = (99 - percent) * 8 / 99;
    shift_register_output(0b11111111 << leds_count);
}
