/*
 * adc.h
 *  Initialize ADC conversor and read from a specific channel
 *  Header file
 *  Created on: 12/07/2018
 *      Author: ssscassio
 */

#ifndef HEADERS_ADC_H_
#define HEADERS_ADC_H_

uint16_t adc_read(uint8_t ch);
void adc_init(void);

#endif /* HEADERS_ADC_H_ */
