/*
 * shift_register.h
 *
 *  Created on: 22 de nov de 2018
 *      Author: ssscassio
 */

#ifndef HEADERS_SHIFT_REGISTER_H_
#define HEADERS_SHIFT_REGISTER_H_

#include <avr/io.h>

// Define Shift Register Pins and Ports
#define SHIFT_REGISTER_PORT PORTC /* Define Shift Register at port C */
#define DS_PIN PC0                /* Serial data input for shift register at pin PC0 */
#define ST_CP_PIN PC1             /* Latch clock at pin PC1 (ST_CP) */
#define SH_CP_PIN PC2             /* Shift clock at pin PC2 (SH_CP) */

// Define Shift Register actions
#define DS_low() SHIFT_REGISTER_PORT &= ~(1 << DS_PIN)
#define DS_high() SHIFT_REGISTER_PORT |= (1 << DS_PIN)
#define ST_CP_low() SHIFT_REGISTER_PORT &= ~(1 << ST_CP_PIN)
#define ST_CP_high() SHIFT_REGISTER_PORT |= (1 << ST_CP_PIN)
#define SH_CP_low() SHIFT_REGISTER_PORT &= ~(1 << SH_CP_PIN)
#define SH_CP_high() SHIFT_REGISTER_PORT |= (1 << SH_CP_PIN)

// Define Shift Register Functions
void shift_register_init(void);

void shift_register_output(unsigned char byte);

#endif /* HEADERS_SHIFT_REGISTER_H_ */
