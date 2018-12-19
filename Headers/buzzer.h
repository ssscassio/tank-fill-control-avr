/*
 * buzzer.h
 *  Dispatcher for the state machine of
 *  the Buzzer and alert situations 
 *  Header file
 *  Created on: 12/7/2018
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
#define UPPER_THRESHOLD_PERCENT 80
#define LOWER_THRESHOLD_PERCENT 25

// Define Buzzer Actions
#define BuzzerOn() BUZZER_PORT ^= (1 << BUZZER)

// Define Buzzer Function
void buzzer_state_machine(uint16_t percent);

void buzzer_init();

#endif /* HEADERS_BUZZER_H_ */
