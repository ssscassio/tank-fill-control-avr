#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/uart.h"
#include "../Headers/displays.h"
#include "../Headers/floater.h"
#include "../Headers/buzzer.h"
#include "../Headers/motor.h"
#include "../Headers/level_sensors.h"
#include "../Headers/control_selector.h"

// #define SONAR 1

#ifdef SONAR
#include "../Headers/sonar.h"
#endif

#define FILTER_CYCLE_AMOUNT 15
#define NULL_PERCENT -100

#ifdef SONAR
#define NUMBER_OF_CONTROLS 4
#else
#define NUMBER_OF_CONTROLS 3
#endif

/* Define Functions*/
void hardware_init(void);
#ifdef SONAR
void print_values(uint16_t tank_percent_floater, uint16_t tank_percent_pins, uint16_t tank_percent_sonar, uint16_t control_mode);
#else
void print_values(uint16_t tank_percent_floater, uint16_t tank_percent_pins, uint16_t control_mode);
#endif

int main(void)
{
  hardware_init(); // Setup IO pins and defaults

  uint16_t tank_percent_floater, tank_percent_pins;
  uint16_t control_mode = 0, last_control_mode = 0;
#ifdef SONAR
  uint16_t tank_percent_sonar;
#endif
  uint16_t tank_percent_selected, tank_percent_from_previous_cycle = NULL_PERCENT, tank_percent_filtered = NULL_PERCENT;
  uint8_t filter_count = 0;
  while (1)
  {
    tank_percent_floater = get_floater_percent();
    tank_percent_pins = get_pins_percent(PINS_MODE_AMOUNT);
#ifdef SONAR
    // tank_percent_sonar = get_sonar_percent();
#endif

    /* Control mode selection */
    last_control_mode = control_mode;
    control_mode = control_selector(NUMBER_OF_CONTROLS);
    switch (control_mode)
    {
    case 0:
      tank_percent_selected = tank_percent_floater;
      break;
    case 1:
      tank_percent_selected = tank_percent_pins;
      break;
    case 2:
#ifdef SONAR
      tank_percent_selected = tank_percent_sonar;
      break;
    case 3:
#endif
    default:
#ifdef SONAR
      tank_percent_selected = (tank_percent_floater + tank_percent_pins + tank_percent_sonar) / 3;
#else
      tank_percent_selected = (tank_percent_floater + tank_percent_pins) / 2;
#endif
      break;
    }
    /* End of Control mode selection */

    /* Filtering percent: Change display only if the percent value stay equals for FILTER_CYCLE_AMOUNT programs cycles */
    if (tank_percent_from_previous_cycle != tank_percent_selected)
      filter_count = 0;
    else
      filter_count++;

    /*User interface*/
    if (tank_percent_filtered != tank_percent_from_previous_cycle || last_control_mode != control_mode)
    {
#ifdef SONAR
      print_values(tank_percent_floater, tank_percent_pins, tank_percent_sonar, control_mode);
#else
      print_values(tank_percent_floater, tank_percent_pins, control_mode);
#endif
    }

    tank_percent_from_previous_cycle = tank_percent_selected;

    if (tank_percent_filtered == -1 || filter_count > FILTER_CYCLE_AMOUNT)
      tank_percent_filtered = tank_percent_selected;
    /* End of filtering */

    show_displays(tank_percent_filtered);
    buzzer_state_machine(tank_percent_filtered);
    motor_state_machine(tank_percent_filtered);
  }
}

#ifdef SONAR
void print_values(uint16_t tank_percent_floater, uint16_t tank_percent_pins, uint16_t tank_percent_sonar, uint16_t control_mode)
#else
void print_values(uint16_t tank_percent_floater, uint16_t tank_percent_pins, uint16_t control_mode)
#endif
{
  printf("Floater: %d%%\n", tank_percent_floater);
  printf("Pins: %d%% \n", tank_percent_pins);
#ifdef SONAR
  printf("Ultrasonic: %d%% %d \n", tank_percent_sonar, get_sonar_value());
#endif
  printf("Control Mode: %d \n", control_mode);
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void hardware_init(void)
{
  displays_init();
  printf_init();
  floater_init();
  buzzer_init();
  motor_init();
  level_sensors_init();
  control_selector_init();
#ifdef SONAR
  sonar_init();
#endif
}
