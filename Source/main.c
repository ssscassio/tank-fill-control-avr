#include <avr/io.h>
#include <util/delay.h>
#include "../Headers/uart.h"
#include "../Headers/displays.h"
#include "../Headers/floater.h"
#include "../Headers/buzzer.h"
#include "../Headers/motor.h"
#include "../Headers/level_sensors.h"
#include "../Headers/control_selector.h"

#define FILTER_CYCLE_AMOUNT 15 /* Filter cycles */
#define NULL_PERCENT -100      /* Percent initial value*/
//#define _DEBUG_ 1
#define NUMBER_OF_CONTROLS 3
#define CONTROL_WITH_FLOATER 0
#define CONTROL_WITH_PINS 1
#define CONTROL_WITH_MEAN 2

/* Functions Declarations */
void hardware_init(void);
void print_values(uint16_t tank_percent_floater, uint16_t tank_percent_pins, uint16_t control_mode);

int main(void)
{
  hardware_init(); // Setup IO pins and defaults

  uint32_t tank_percent_floater, tank_percent_pins;
  uint16_t control_mode = 0, last_control_mode = 0;
  uint16_t tank_percent_selected, tank_percent_from_previous_cycle = NULL_PERCENT, tank_percent_filtered = NULL_PERCENT;
  uint8_t filter_count = 0;

  while (1)
  {
    /* Read Sensors*/
    tank_percent_floater = get_floater_percent();
    tank_percent_pins = get_pins_percent(PINS_MODE_AMOUNT);
#ifdef _DEBUG_
    printf("Floater percent: %d%% Value: %d\n ", tank_percent_floater, get_floater_value());
#endif
    /* Control mode selection */
    last_control_mode = control_mode;
    control_mode = control_selector(NUMBER_OF_CONTROLS);
    switch (control_mode)
    {
    case CONTROL_WITH_FLOATER:
      tank_percent_selected = tank_percent_floater;
      break;
    case CONTROL_WITH_PINS:
      tank_percent_selected = tank_percent_pins;
      break;
    case CONTROL_WITH_MEAN:
    default:
      tank_percent_selected = (tank_percent_floater + tank_percent_pins) / 2;
      break;
    }
    /* End of Control mode selection */

    /* Filtering percent: Change display only if the percent value stay equals for FILTER_CYCLE_AMOUNT programs cycles */
    if (tank_percent_from_previous_cycle != tank_percent_selected)
      filter_count = 0;
    else
      filter_count++;

    tank_percent_from_previous_cycle = tank_percent_selected;

    if (tank_percent_filtered == -1 || filter_count > FILTER_CYCLE_AMOUNT)
      tank_percent_filtered = tank_percent_selected;
    /* End of filtering */

    /* User interface */
    if (tank_percent_filtered != tank_percent_from_previous_cycle || last_control_mode != control_mode)
    {
      print_values(tank_percent_floater, tank_percent_pins, control_mode);
    }

    /* Displays and actuators */
    show_displays(tank_percent_filtered);
    buzzer_state_machine(tank_percent_filtered);
    motor_state_machine(tank_percent_filtered);
  }
}

/**
 * User interface display
 * 
 * - Show to the user the actual value of some sensors and changes at Control Mode
 */
void print_values(uint16_t tank_percent_floater, uint16_t tank_percent_pins, uint16_t control_mode)
{
  printf("Floater: %d%%\n", tank_percent_floater);
  printf("Pins: %d%% \n", tank_percent_pins);
  switch (control_mode)
  {
  case CONTROL_WITH_FLOATER:
    printf("Control Mode: Floater \n");
    break;
  case CONTROL_WITH_PINS:
    printf("Control Mode: Pins \n");
    break;
  case CONTROL_WITH_MEAN:
    printf("Control Mode: Mean \n");
    break;
  }
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/**
 * Hardware initialization
 *
 * - Initialize Sensors Pins and configurations
 * - Initialize Actuators Pins and configuration
 * - Enable printf to console
 */
void hardware_init(void)
{
  displays_init();
  printf_init();
  floater_init();
  buzzer_init();
  motor_init();
  level_sensors_init();
  control_selector_init();
}
