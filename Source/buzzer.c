/*
 * buzzer.c
 *
 *  Created on: 7 de dez de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>

#define BUZZER_DDR DDRB
#define BUZZER_PORT PORTB
#define BUZZER PB2
#define FULL_THRESHOLD_PERCENT 80
#define EMPTY_THRESHOLD_PERCENT 20

#define BuzzerOn()  BUZZER_PORT |= (1<<BUZZER)
#define BuzzerOff() BUZZER_PORT &= ~(1<<BUZZER)

void buzzer_init(){
  BUZZER_DDR |= (1<<BUZZER);
  /* Set Buzzer to low */
  BUZZER_PORT &= ~(1<<BUZZER);
}

void buzzer_dispatcher(unsigned char percent){
  if(percent >= FULL_THRESHOLD_PERCENT || percent <= EMPTY_THRESHOLD_PERCENT){
    BuzzerOn();
  } else {
    BuzzerOff();
  }
}

