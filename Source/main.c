#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/serial_printf.h"
#include "../Headers/displays.h"
#include "../Headers/floater.h"

/* Define Functions*/
void hardware_init(void);

int main (void) {
  hardware_init(); //Setup IO pins and defaults

  uint16_t tank_percent;
  while(1) {
    tank_percent = get_tank_percent();
    show_displays(99-tank_percent);
  }
}

void hardware_init (void) {
  displays_init();
  printf_init();
  floater_init();
}

