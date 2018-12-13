#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/serial_printf.h"
#include "../Headers/displays.h"
#include "../Headers/floater.h"
#include "../Headers/buzzer.h"
#include "../Headers/sonar.h"
#include "../Headers/motor.h"

/* Define Functions*/
void hardware_init(void);

int main(void)
{
  hardware_init(); //Setup IO pins and defaults

  uint16_t tank_percent;
  while (1)
  {
    tank_percent = get_floater_percent();
    show_displays(99 - tank_percent);
    buzzer_dispatcher(99 - tank_percent);
    printf("%d\n", get_sonar_value());
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
}
