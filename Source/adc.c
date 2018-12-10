/*
 * adc.c
 *
 *  Created on: 7 de dez de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/adc.h"

void adc_init (void) {
  /* AVCC with external capacitor at AREF pin */
  ADMUX = (1<<REFS0);
  /* ADEN: 1 => ADC enable; ADPS: 111 => Prescaler 128*/
  ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16_t adc_read(uint8_t ch) {
  ch &= 0b00000111;// AND operation with 7 to keep value between 0-7
  ADMUX = (ADMUX & 0xF8)|ch; // Clears the bottom 3 bits before ORing

  // Start ADC convertion writing '1' to ADSC
  ADCSRA |= (1<<ADSC);

  // Wait conversion to complete.
  // Conversion complete when ADSC is back to 0
  while(ADCSRA & (1<<ADSC));

  return (ADC);
}
