/*
 * display_seven.c
 *
 *  Created on: 29 de nov de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/shift_register.h"

#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define dp 7

#define zero  _BV(a) | _BV(b) | _BV(c) | _BV(d) | _BV(e) | _BV(f)
#define one   _BV(b) | _BV(c)
#define two   _BV(a) | _BV(b) | _BV(g) | _BV(e) | _BV(d)
#define three _BV(a) | _BV(b) | _BV(g) | _BV(c) | _BV(d)
#define four  _BV(f) | _BV(g) | _BV(b) | _BV(c)
#define five  _BV(a) | _BV(f) | _BV(g) | _BV(c) | _BV(d)
#define six   _BV(a) | _BV(f) | _BV(e) | _BV(d) | _BV(c) | _BV(g)
#define seven _BV(a) | _BV(b) | _BV(c)
#define eight _BV(a) | _BV(b) | _BV(c) | _BV(d) | _BV(e) | _BV(f) | _BV(g)
#define nine  _BV(a) | _BV(b) | _BV(c) | _BV(f) | _BV(g)
#define dot   _BV(dp)

unsigned char convert_number(unsigned char number);

void seven_left(unsigned char number) {
  shift_register_output(convert_number(number));
}


void seven_right(unsigned char number) {
  shift_register_output(convert_number(number));
}

unsigned char convert_number(unsigned char number) {
  switch(number) {
    case 0:
      return zero;
    case 1:
      return one;
    case 2:
      return two;
    case 3:
      return three;
    case 4:
      return four;
    case 5:
      return five;
    case 6:
      return six;
    case 7:
      return seven;
    case 8:
      return eight;
    case 9:
      return nine;
    default:
      return dot;
  }
}
