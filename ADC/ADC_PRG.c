/*
 * ADC_PRG.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed Ehab
 */

#include "LIB\stdtypes.h"
#include "LIB\bitmath.h"

#include "ADC_REG.h"
#include "ADC_INT.h"

u8 ADC_u8Init(ADC_VREF Vref, ADC_LEFT_ADJUST LeftAdjust, ADC_AUTO_TRIGGER AutoTrigger, ADC_PRESCALAR Prescalar, ADC_INT IntStatus)
{
	u8 Local_u8Temp,Local_u8ErrorStatus=RT_OK;
	if(Prescalar>=ADC_PRE_2 && Prescalar<=ADC_PRE_128)
	{
		Local_u8Temp =ADCSRA_REG;
		Local_u8Temp &=ADC_MASK_ADPS;
		Local_u8Temp |=Prescalar;
		ADCSRA_REG = Local_u8Temp;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	if(Vref>=ADC_AREF && Vref<=ADC_INTERNAL && Vref!=ADC_RESERVED)
	{
		Local_u8Temp =ADMUX_REG;
		Local_u8Temp &=ADC_MASK_ADREF;
		Local_u8Temp |= Vref;
		ADMUX_REG= Local_u8Temp;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	switch (LeftAdjust)
	{
		case ADC_LEFT_ADJUST_DIS:
			Clr_Bit(ADMUX_REG,ADC_ADLAR);
			break;
		case ADC_LEFT_ADJUST_EN:
			Set_Bit(ADMUX_REG,ADC_ADLAR);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
	}
	switch (AutoTrigger)
	{
		case ADC_AUTO_TRIGGER_DIS:
			Clr_Bit(ADCSRA_REG,ADC_ADATE);
			break;
		case ADC_AUTO_TRIGGER_EN:
			Set_Bit(ADCSRA_REG,ADC_ADATE);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
	}
	switch (IntStatus)
	{
		case ADC_INT_DIS:
			Clr_Bit(ADCSRA_REG,ADC_ADIE);
			break;
		case ADC_INT_EN:
			Set_Bit(ADCSRA_REG,ADC_ADIE);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
	}
	Set_Bit(ADCSRA_REG,ADC_ADEN);
	return Local_u8ErrorStatus;
}

u8 ADC_u8GetDigitalRead (ADC_MUX Channel, ADC_ADTS TriggerSelect, u16 *DigitalRead)
{
	u8 Local_u8Temp,Local_u8ErrorStatus=RT_OK;
	if(Channel>=ADC_ADC0 && Channel<=ADC_GND)
	{
		Local_u8Temp =ADCSRA_REG;
		Local_u8Temp &=ADC_MASK_MUX;
		Local_u8Temp |=Channel;
		ADCSRA_REG = Local_u8Temp;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	if(TriggerSelect>=ADC_ADTS_FREE_RUNNING && TriggerSelect<=ADC_ADTS_TIMER1_CAPTURE_EVENT && Get_Bit(ADCSRA_REG,ADC_ADATE)==1)
	{
		Local_u8Temp =SFIOR_REG;
		Local_u8Temp &=ADC_MASK_ADTS;
		Local_u8Temp |= TriggerSelect;
		SFIOR_REG =Local_u8Temp;
		Set_Bit(ADCSRA_REG,ADC_ADSC);
	}
	else if(TriggerSelect==ADC_SINGLE_CONVERSION)
	{
		Set_Bit(ADCSRA_REG,ADC_ADSC);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	while((Get_Bit(ADCSRA_REG,ADC_ADSC)==0));
	Set_Bit(ADCSRA_REG,ADC_ADIF);
	*DigitalRead=ADC_REG;
	return Local_u8ErrorStatus;
}
