#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/serial_printf.h"
#include "../Headers/displays.h"
#include "../Headers/floater.h"
#include "../Headers/buzzer.h"
#include "../Headers/sonar.h"
#include "../Headers/motor.h"
#include "../Headers/level_sensors.h"
#include "../Headers/control_selector.h"

#define FILTER_CYCLE_AMOUNT 15
#define NULL_PERCENT -100
#define NUMBER_OF_CONTROLS 4

/* Define Functions*/
void hardware_init(void);

int main(void)
{
  hardware_init(); // Setup IO pins and defaults

  uint16_t tank_percent_floater, tank_percent_pins, tank_percent_sonar;
  uint16_t tank_percent_selected, tank_percent_from_previous_cycle = NULL_PERCENT, tank_percent_filtered = NULL_PERCENT;
  uint8_t filter_count = 0;

  while (1)
  {
    tank_percent_floater = get_floater_percent();
    tank_percent_pins = get_pins_percent();
    tank_percent_sonar = get_sonar_percent();

    switch (control_selector(NUMBER_OF_CONTROLS))
    {
    case 0:
      tank_percent_selected = tank_percent_floater;
      break;
    case 1:
      tank_percent_selected = tank_percent_pins;
      break;
    case 2:
      tank_percent_selected = tank_percent_sonar;
      break;
    case 3:
    default:
      tank_percent_selected = (tank_percent_floater + tank_percent_pins + tank_percent_sonar) / 3;
      break;
    }

    /* Filtering percent: Change display only if the percent value stay equals for FILTER_CYCLE_AMOUNT programs cycles */
    if (tank_percent_from_previous_cycle != tank_percent_selected)
      filter_count = 0;
    else
      filter_count++;

    tank_percent_from_previous_cycle = tank_percent_selected;

    if (tank_percent_filtered == -1 || filter_count > FILTER_CYCLE_AMOUNT)
      tank_percent_filtered = tank_percent_selected;
    /* End of filtering */

    show_displays(99 - tank_percent_filtered);
    buzzer_dispatcher(99 - tank_percent_filtered);
    motor_dispatcher(99 - tank_percent_filtered);
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
  control_selector_init();
}
