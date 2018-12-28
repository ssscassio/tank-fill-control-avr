/*
 * shift_register.c
 *
 *  Created on: 22 de nov de 2018
 *      Author: Cássio Santos
 */
#include <avr/io.h>
#include "../Headers/shift_register.h"

void shift_register_init()
{
  /* Define Shift Register pins as Outputs - remaining pins unconfigured */
  DDRC |= (1 << DS_PIN) | (1 << ST_CP_PIN) | (1 << SH_CP_PIN);
  /* DS = SER; ST = RCK; SH = SCK */
}

/**
 * Provides the byte passed as parameter
 * to the output of the shift register
 */
void shift_register_output(unsigned char byte)
{
  SH_CP_low();
  ST_CP_low();
  for (int i = 0; i < 8; i++)
  {
    if ((byte & (1 << i)))
      DS_high();
    else
      DS_low();
    SH_CP_high();
    SH_CP_low();
  }
  ST_CP_high();
}
