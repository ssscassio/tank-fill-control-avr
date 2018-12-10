/*
 * leds_bar.c
 *
 *  Created on: 22 de nov de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/leds_bar.h"

void leds_bar_output(unsigned char emptyPercent) {
    int leds_count = emptyPercent*8/100;
    shift_register_output(0b11111111 << leds_count);
}
