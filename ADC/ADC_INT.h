/*
 * ADC_INT.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed Ehab
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

typedef enum
{
	ADC_AREF,
	ADC_VCC,
	ADC_RESERVED,
	ADC_INTERNAL
}ADC_VREF;

typedef enum
{
	ADC_ADC0 = 0b00000,
	ADC_ADC1 = 0b00001,
	ADC_ADC2 = 0b00010,
	ADC_ADC3 = 0b00011,
	ADC_ADC4 = 0b00100,
	ADC_ADC5 = 0b00101,
	ADC_ADC6 = 0b00110,
	ADC_ADC7 = 0b00111,
	ADC_ADC0_ADC0_10 = 0b01000,
	ADC_ADC1_ADC0_10 = 0b01001,
	ADC_ADC0_ADC0_200 = 0b01010,
	ADC_ADC1_ADC0_200 = 0b01011,
	ADC_ADC2_ADC2_10 = 0b01100,
	ADC_ADC3_ADC2_10 = 0b01101,
	ADC_ADC2_ADC2_200 = 0b01110,
	ADC_ADC3_ADC2_200 = 0b01111,
	ADC_ADC0_ADC1 = 0b10000,
	ADC_ADC1_ADC1 = 0b10001,
	ADC_ADC2_ADC1 = 0b10010,
	ADC_ADC3_ADC1 = 0b10011,
	ADC_ADC4_ADC1 = 0b10100,
	ADC_ADC5_ADC1 = 0b10101,
	ADC_ADC6_ADC1 = 0b10110,
	ADC_ADC7_ADC1 = 0b10111,
	ADC_ADC0_ADC2 = 0b11000,
	ADC_ADC1_ADC2 = 0b11001,
	ADC_ADC2_ADC2 = 0b11010,
	ADC_ADC3_ADC2 = 0b11011,
	ADC_ADC4_ADC2 = 0b11100,
	ADC_ADC5_ADC2 = 0b11101,
	ADC_Vbg = 0b11110,
	ADC_GND = 0b11111,
}ADC_MUX;

typedef enum
{
	ADC_ADREF1=7,
	ADC_ADREF0=6,
	ADC_ADLAR=5,
	ADC_ADEN=7,
	ADC_ADSC=6,
	ADC_ADATE=5,
	ADC_ADIF=4,
	ADC_ADIE=3,
	ADC_ADPS2=2,
	ADC_ADPS1=1,
	ADC_ADPS0=0,
	ADC_ADTS0=5,
	ADC_ADTS1=6,
	ADC_ADTS2=7
}ADC_CONFIG;

typedef enum
{
	ADC_PRE_2,
	ADC_PRE_2_1,
	ADC_PRE_4,
	ADC_PRE_8,
	ADC_PRE_16,
	ADC_PRE_32,
	ADC_PRE_64,
	ADC_PRE_128,
}ADC_PRESCALAR;

typedef enum
{
	ADC_ADTS_FREE_RUNNING,
	ADC_ADTS_ANALOG_COMPARATOR,
	ADC_ADTS_EXT_INT0,
	ADC_ADTS_TIMER0_COMPARE_MATCH,
	ADC_ADTS_TIMER0_COMPARE_OVERFLOW,
	ADC_ADTS_TIMER_COMPARE_MATCH_B,
	ADC_ADTS_TIMER1_COMPARE_OVERFLOW,
	ADC_ADTS_TIMER1_CAPTURE_EVENT,
	ADC_SINGLE_CONVERSION
}ADC_ADTS;

typedef enum
{
	ADC_LEFT_ADJUST_DIS,
	ADC_LEFT_ADJUST_EN
}ADC_LEFT_ADJUST;

typedef enum
{
	ADC_AUTO_TRIGGER_DIS,
	ADC_AUTO_TRIGGER_EN
}ADC_AUTO_TRIGGER;

typedef enum
{
	ADC_MASK_ADTS=0b00011111,
	ADC_MASK_ADPS=0b11111000,
	ADC_MASK_ADREF=0b00111111,
	ADC_MASK_MUX=0b11100000
}ADC_MASK;

typedef enum
{
	ADC_INT_DIS,
	ADC_INT_EN
}ADC_INT;

u8 ADC_u8Init(ADC_VREF Vref, ADC_LEFT_ADJUST LeftAdjust, ADC_AUTO_TRIGGER AutoTrigger, ADC_PRESCALAR Prescalar, ADC_INT IntStatus);
u8 ADC_u8GetDigitalRead (ADC_MUX Channel, ADC_ADTS TriggerSelect, u16 *DigitalRead);
#endif /* ADC_INT_H_ */
