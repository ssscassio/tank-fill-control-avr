#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/shift_register.h"
#include "../Headers/uart.h"
#include "../Headers/leds_bar.h"
#include "../Headers/display_seven.h"

#define SHIFT_REGISTER_CONTROL PORTB
#define LEFT_DISPLAY      PB5
#define RIGHT_DISPLAY     PB4
#define LEDS_BAR_DISPLAY  PB3

#define CLEAR_ALL_DISPLAYS()   SHIFT_REGISTER_CONTROL &=  ~((1<<LEFT_DISPLAY) | (1<<RIGHT_DISPLAY) | (1<<LEDS_BAR_DISPLAY))
#define SHOW_LEDS_BAR()   SHIFT_REGISTER_CONTROL |= (1<<LEDS_BAR_DISPLAY)
#define SHOW_RIGHT()   SHIFT_REGISTER_CONTROL |= (1<<RIGHT_DISPLAY)
#define SHOW_LEFT()   SHIFT_REGISTER_CONTROL |= (1<<LEFT_DISPLAY)

/* Define Functions*/
void hardware_init(void);

int main (void) {
  hardware_init(); //Setup IO pins and defaults
  while(1) {
    for(int i=0; i<100; i++){
      leds_bar_output(100-i);
      _delay_ms(500);
    }
  }
}

void hardware_init (void) {
  shift_register_init();
  uart_init();
  DDRB  |= (1<<LEFT_DISPLAY) /* Configure display control as output */
        | (1<<RIGHT_DISPLAY)
        | (1<<LEDS_BAR_DISPLAY);
  /* Set all output pins as low */
  SHIFT_REGISTER_CONTROL = 0x00;
}
