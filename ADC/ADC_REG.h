/*
 * ADC_REG.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed Ehab
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX_REG (*(volatile u8*)0x27)
#define ADCSRA_REG (*(volatile u8*)0x26)
#define SFIOR_REG (*(volatile u8*)0x50)
#define ADCL_REG (*(volatile u8*)0x24)
#define ADCH_REG (*(volatile u8*)0x25)
#define ADC_REG (*(volatile u16*)0x24)

#endif /* ADC_REG_H_ */
