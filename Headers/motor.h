/*
 * motor.h
 *
 *  Header file
 *  Created on: 13 de dez de 2018
 *      Author: Cássio Santos
 */

#ifndef HEADERS_MOTOR_H_
#define HEADERS_MOTOR_H_

#include <avr/io.h>
#include <util/delay.h>

// Define Motor Pins and Ports
#define MOTOR_DDR DDRB
#define MOTOR_PORT PORTB
#define MOTOR PB0

// Define Threshold to activate and desactivate the Motor
#define LOWER_LIMIAR_MOTOR 10  // Motor activate if tank percentage is under this value
#define HIGHER_LIMIAR_MOTOR 50 // Motor desactivate if tank percentage is above this value

// Declare Motor Functions
void motor_init(void);

void motor_state_machine(uint16_t percent);

#endif /* HEADERS_MOTOR_H_ */
