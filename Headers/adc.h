/*
 * adc.h
 *  Initialize ADC conversor and read from a specific channel
 *  Header File
 *  Created on: 12/07/2018
 *      Author: Cássio Santos
 */

#ifndef HEADERS_ADC_H_
#define HEADERS_ADC_H_

// Declare Adc reader Functions
uint16_t adc_read(uint8_t ch);

void adc_init(void);

#endif /* HEADERS_ADC_H_ */
