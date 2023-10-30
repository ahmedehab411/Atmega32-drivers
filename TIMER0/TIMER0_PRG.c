/*
 * TIMER_PRG.h
 *
 *  Created on: Nov 9, 2021
 *      Author: Ahmed Ehab
 */

#include "LIB\stdtypes.h"
#include "LIB\bitmath.h"

#include "TIMER0_REG.h"
#include "TIMER0_INT.h"

static void (*OVFADDR)(void)=NULL;
static void (*CTCADDR)(void)=NULL;

u8 TIMER0_u8Init(TIMER0_MODE_e TimerMode)
{
	u8 Local_u8ErrStatus=RT_OK;
	switch (TimerMode)
	{
	case TIMER0_MODE_e_NORMAL:
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM00);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM01);
		break;
	case TIMER0_MODE_e_CTC:
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM00);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM01);
		break;
	case TIMER0_MODE_e_PWM:
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM00);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM01);
		break;
	case TIMER0_MODE_e_FAST_PWM:
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM00);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_WGM01);
		break;
	default:
		Local_u8ErrStatus=RT_NOK;
		break;
	}
	return Local_u8ErrStatus;
}
u8 TIMER0_u8ClkSelect(TIMER0_CLK_SELECT_e ClkSelect)
{
	u8 Local_u8ErrStatus=RT_OK;
	switch(ClkSelect)
	{
	case TIMER0_CLK_SELECT_e_NO_CLK:
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	case TIMER0_CLK_SELECT_e_NO_PRE:
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	case TIMER0_CLK_SELECT_e_PRE_8:
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	case TIMER0_CLK_SELECT_e_PRE_64:
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	case TIMER0_CLK_SELECT_e_PRE_256:
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	case TIMER0_CLK_SELECT_e_PRE_1024:
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	case TIMER0_CLK_SELECT_e_EXT_FALLING:
		Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	case TIMER0_CLK_SELECT_e_EXT_RISING:
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
		Set_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
		break;
	default:
		Local_u8ErrStatus=RT_NOK;
		break;
	}
	return Local_u8ErrStatus;
}
/*void TIMER0_vidStartTimer(void)
{
	TCCR0_REG|=(OCR0_REG<<5);
}
void TIMER0_vidStopTimer(void)
{
	OCR0_REG=TCCR0_REG;
	Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS00);
	Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS01);
	Clr_Bit(TCCR0_REG,TIMER0_TCCR0_e_CS02);
}*/
void TIMER0_vidSetPreload(u8 Copy_u8Preload)
{
	TCNT0_REG=Copy_u8Preload;
}
void TIMER0_vidSetCTC(u8 Copy_u8CTC)
{
	OCR0_REG=Copy_u8CTC;
}
void TIMER0_vidTovfInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER0_TIMSK_e_TOIE0);
}
void TIMER0_vidTovfInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER0_TIMSK_e_TOIE0);
}
void TIMER0_vidCtcInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER0_TIMSK_e_OCIE0);
}
void TIMER0_vidCtcInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER0_TIMSK_e_OCIE0);
}
void TIMER0_vidSetPwmDutyCycle(u8 Copy_u8DutyCycle)
{
	OCR0_REG=Copy_u8DutyCycle;
}
u8 TIMER0_u8SetOvfCbf(void(*fptr)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(fptr!=NULL)
	{
		OVFADDR=fptr;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
u8 TIMER0_u8SetCtcCbf(void(*fptr)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(fptr!=NULL)
	{
		CTCADDR=fptr;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void)
{
	if(CTCADDR!=NULL)
	{
		CTCADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(OVFADDR!=NULL)
	{
		OVFADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}
