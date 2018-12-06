#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/serial_printf.h"
#include "../Headers/displays.h"

#define ANALOGIC_PORT     PORTC
#define FLOATER           PC3

/* Define Functions*/
void hardware_init(void);

int main (void) {
  hardware_init(); //Setup IO pins and defaults
  while(1) {
    for (unsigned char i = 0; i<100 ; i++){
      for(int j=0; j<10; j++){
        printf("Test\n");
        show_displays(i);
      }
    }
  }
}

void hardware_init (void) {
  displays_init();
  printf_init();
}
