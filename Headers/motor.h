/*
 * motor.h
 *
 *  Created on: 13 de dez de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_MOTOR_H_
#define HEADERS_MOTOR_H_

#include <avr/io.h>
#include <util/delay.h>

#define MOTOR_DDR DDRB
#define MOTOR_PORT PORTB
#define MOTOR PB0

#define LOWER_LIMIAR_MOTOR 10
#define HIGHER_LIMIAR_MOTOR 50

void motor_init(void);

void motor_state_machine(uint16_t percent);

#endif /* HEADERS_MOTOR_H_ */
