#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/serial_printf.h"
#include "../Headers/displays.h"
#include "../Headers/floater.h"
#include "../Headers/buzzer.h"
#include "../Headers/sonar.h"
#include "../Headers/motor.h"
#include "../Headers/level_sensors.h"

/* Define Functions*/
void hardware_init(void);

int main(void)
{
  hardware_init(); //Setup IO pins and defaults

  uint16_t tank_percent, tank_percent_floater, tank_percent_pins, tank_percent_sonar;

  while (1)
  {
    tank_percent_floater = get_floater_percent();
    tank_percent_sonar = get_sonar_percent();
    tank_percent_pins = get_pins_percent();
    tank_percent = tank_percent_pins;
    show_displays(99 - tank_percent);
    buzzer_dispatcher(99 - tank_percent);
    motor_dispatcher(99 - tank_percent);
  }
}

void hardware_init(void)
{
  displays_init();
  printf_init();
  floater_init();
  buzzer_init();
  sonar_init();
  motor_init();
  level_sensors_init();
}
