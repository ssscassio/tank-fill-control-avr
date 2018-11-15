/*
 * led_array.c
 *
 *  Created on: 8 de nov de 2018
 *      Author: ssscassio
 */
#include <avr/io.h>

#define LEDS_BAR_PORT PORTC /* Define LEDs bar at port C */
#define DS_PIN PC0          /* Serial data input for shift register at pin PC0 */
#define ST_CP_PIN PC1       /* Latch clock at pin PC1 (ST_CP) */
#define SH_CP_PIN PC2       /* Shift clock at pin PC2 (SH_CP) */


// Define Shift Register actions
#define DS_low()  LEDS_BAR_PORT&=~(1<<DS_PIN)
#define DS_high() LEDS_BAR_PORT|=(1<<DS_PIN)
#define ST_CP_low()  LEDS_BAR_PORT&=~(1<<ST_CP_PIN)
#define ST_CP_high() LEDS_BAR_PORT|=(1<<ST_CP_PIN)
#define SH_CP_low()  LEDS_BAR_PORT&=~(1<<SH_CP_PIN)
#define SH_CP_high() LEDS_BAR_PORT|=(1<<SH_CP_PIN)

void leds_bar_init() {
  /* Define Shift Register pins as Outputs - remaining pins unconfigured */
  DDRC  |= (1<<DS_PIN)
    | (1<<ST_CP_PIN)
    | (1<<SH_CP_PIN);
}

void leds_bar_output(int number_of_leds) {
  SH_CP_low();
  ST_CP_low();
  for (int i=0;i<8; i++) {
      if (i < number_of_leds) {
        DS_high();
      } else{
        DS_low();
      }
      SH_CP_high();
      SH_CP_low();
  }
  ST_CP_high();
}
