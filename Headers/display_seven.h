/*
 * display_seven.h
 *  Convert a specific digit to a binary that will be 
 *  input to the shift register 
 *  (less significant bit equals a)
 *  (more significant bit equals dot point)
 *  Header file
 *  Created on: 11/29/2018
 *      Author: ssscassio
 */

#ifndef HEADERS_DISPLAY_SEVEN_H_
#define HEADERS_DISPLAY_SEVEN_H_

#include "../Headers/shift_register.h"

// Define Seven Segments Display numbers combinations
#define a _BV(0)
#define b _BV(1)
#define c _BV(2)
#define d _BV(3)
#define e _BV(4)
#define f _BV(5)
#define g _BV(6)
#define dp _BV(7)

// Define Seven Segments Display numbers combinations
#define zero a | b | c | d | e | f
#define one b | c
#define two a | b | g | e | d
#define three a | b | g | c | d
#define four f | g | b | c
#define five a | f | g | c | d
#define six a | f | e | d | c | g
#define seven a | b | c
#define eight a | b | c | d | e | f | g
#define nine a | b | c | f | g
#define dot dp

// Define Seven Segments Display Functions
unsigned char convert_number(unsigned char number);

void seven_left(unsigned char number);

void seven_right(unsigned char number);

#endif /* HEADERS_DISPLAY_SEVEN_H_ */
