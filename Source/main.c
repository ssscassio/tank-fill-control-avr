/**
 * Tank Fill Control Project
 * 
 *    Este projeto visa permitir o controle automático de um tanque de enchimento e disponibilizar
 * para o usuário formas de visualização das condições do tanque além de ser informar sobre condições
 * adversas que o tanque pode apresentar.
 *    Para identificar as condições do tanque são utilizados dois tipos de informação, uma provida da
 * boia posicionada no topo do tanque e outra provida de quatro sensores de nível posicionados ao longo
 * da parede do tanque.
 *    - Para a boia, após o condicionamento do sinal de tensão utilizando um amplificador operacional, um
 * nível de tensão entre 0 e 5V é lido por uma das portas ADC do microcontrolador o qual é então convertido
 * para um valor analógico entre 0 e 1023. A este valor são definidos limiares que representam o máximo e o
 * mínimo de água que pode estar presente no tanque.
 *    - Para os sensores de nível são utilizadas quatro portas digitais do microcontrolador as quais são
 * verificadas quantas delas apresentam nível lógico zero. A quantidade de sensores em nível lógico zero
 * é diretamente proporcional ao nível do tanque e é convertido em uma porcentagem de acordo com um dos 
 * seguintes: baseado na porcentagem equivalente da boia, baseado na quantidade de pinos ativos, baseado na
 * altura dos pinos em relação a profundidade total do tanque.
 *    Um dos pinos, configurado como uma interrupção externa é utilizado para selecionar o modo de controle
 * do tanque, o modo selecionado definirá qual será a porcentagem do tanque que será utilizada para fazer
 * o controle e para ser exibido para o usuário. Os modos de operação são: controle com a porcentagem da boia,
 * controle com a porcentagem dos sensores de nível, controle com a média entre a porcentagem da boia e dos 
 * sensores de nível.
 *    Após selecionar uma das porcentagens, é aplicado um filtro no qual este valor de porcentagem deve se 
 * repetir durante uma quantidade de ciclos de programa definida (neste projeto 15 ciclos) para que o 
 * seu valor seja considerado válido para ser exibido ou controlar os atuadores do sistema. Esta solução 
 * serve para suavizar os valores apresentados em medidas de sensores intermédios (flutuante).
 *    A porcentagem é então multiplexada via software entre o display de sete segmentos das dezenas, o display
 * de sete segmentos das unidades e o vetor de oito leds. Para fazer isso, é utilizado um Shift Register que
 * disponibiliza na sua saída o valor correto para cada um dos displays enquanto três pinos de seleção são 
 * comutados ordenadamente em um intervalo de 5 milisegundos para selecionar qual display apresentará os
 * valores da saída do Shift Register no momento. (Devido a persistência retiniana do olho humano 
 * esse intervalo de 5 milisegundos é suficiente para não se veja os leds piscarem)
 *    Por fim os atuadores (bomba e alarme) possuem suas máquinas de estado própias que recebem como entrada 
 * o nível do tanque preenchido (em porcentagem) e, de acordo com os limiares definidos, define o estado de
 * acionamento dos atuadores.
 *    - O alarme atua quando o tanque está demasiado cheio ou demasiado vazio, a partir dos limares definidos
 *    - A bomba começa a encher o tanque quando o nível fica abaixo de um limiar inferior e para quando o nível
 * ultrapassa um limiar superior
 *    Author: Cássio Santos
 */
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
//#define DEBUG 1
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
#ifdef DEBUG
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

    /* Filtering percent: Change display only if the percent value stay 
    equals for FILTER_CYCLE_AMOUNT programs cycles */
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
