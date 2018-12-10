/*
 * buzzer.h
 *
 *  Created on: 7 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_BUZZER_H_
#define HEADERS_BUZZER_H_

#include <avr/io.h>

// Define Buzzer Pins and Ports
#define BUZZER_DDR DDRB
#define BUZZER_PORT PORTB
#define BUZZER PB2

// Define Buzzer Parameters
#define FULL_THRESHOLD_PERCENT 80
#define EMPTY_THRESHOLD_PERCENT 20

// Define Buzzer Actions
#define BuzzerOn()  BUZZER_PORT |= (1<<BUZZER)
#define BuzzerOff() BUZZER_PORT &= ~(1<<BUZZER)

// Define Buzzer Function
void buzzer_dispatcher(unsigned char percent);

void buzzer_init();

#endif /* HEADERS_BUZZER_H_ */
