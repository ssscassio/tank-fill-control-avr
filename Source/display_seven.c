/*
 * display_seven.c
 *
 *  Created on: 29 de nov de 2018
 *      Author: ssscassio
 */

#include <avr/io.h>
#include "../Headers/display_seven.h"

void seven_left(unsigned char number)
{
  shift_register_output(convert_number(number));
}

void seven_right(unsigned char number)
{
  shift_register_output(convert_number(number));
}

unsigned char convert_number(unsigned char number)
{
  switch (number)
  {
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
