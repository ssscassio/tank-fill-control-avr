#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/shift_register.h"
#include "../Headers/uart.h"

#define LEDS_BAR_PORT PORTC /* Define LEDs bar at port C */

//Define functions
//======================
void hardware_init(void);

int main (void) {
  hardware_init(); //Setup IO pins and defaults
  while(1) {
    for(int i=0; i<256; i++){
      shift_register_output(i);
      _delay_ms(500);
    }
  }
}


void hardware_init (void) {
  shift_register_init();
  uart_init();
  LEDS_BAR_PORT = 0x00; // Set all output pins as low
}
