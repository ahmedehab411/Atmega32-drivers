/*
 * TIMER2_PRG.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Ahmed Ehab
 */


#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "TIMER2_INT.h"
#include "TIMER2_REG.h"

static void (*OVFADDR)(void)=NULL;
static void (*CTCADDR)(void)=NULL;

u8 TIMER2_u8Init(TIMER2_MODE_e TimerMode)
{
	u8 Local_u8ErrStatus=RT_OK;
	switch (TimerMode)
	{
	case TIMER2_MODE_e_NORMAL:
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM20);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM21);
		break;
	case TIMER2_MODE_e_CTC:
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM20);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM21);
		break;
	case TIMER2_MODE_e_PWM:
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM20);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM21);
		break;
	case TIMER2_MODE_e_FAST_PWM:
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM20);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_WGM21);
		break;
	default:
		Local_u8ErrStatus=RT_NOK;
		break;
	}
	return Local_u8ErrStatus;
}


u8 TIMER2_u8ClkSelect(TIMER2_CLK_SRC_e ClkSrc,TIMER2_CLK_SELECT_e ClkSelect)
{
	u8 Local_u8ErrStatus=RT_OK;
	switch (ClkSrc)
	{
	case TIMER2_CLK_SRC_e_SYNC:
		Clr_Bit(ASSR_REG,TIMER2_ASSR_e_AS2);
		break;
	case TIMER2_CLK_SRC_e_ASYNC:
		Set_Bit(ASSR_REG,TIMER2_ASSR_e_AS2);
		break;
	default:
		break;
	}
	switch(ClkSelect)
	{
	case TIMER2_CLK_SELECT_e_NO_CLK:
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	case TIMER2_CLK_SELECT_e_NO_PRE:
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	case TIMER2_CLK_SELECT_e_PRE_8:
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	case TIMER2_CLK_SELECT_e_PRE_32:
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	case TIMER2_CLK_SELECT_e_PRE_64:
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	case TIMER2_CLK_SELECT_e_PRE_128:
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	case TIMER2_CLK_SELECT_e_PRE_256:
		Clr_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	case TIMER2_CLK_SELECT_e_PRE_1024:
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS20);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS21);
		Set_Bit(TCCR2_REG,TIMER2_TCCR2_e_CS22);
		break;
	default:
		Local_u8ErrStatus=RT_NOK;
		break;
	}
	return Local_u8ErrStatus;
}
void TIMER2_vidSetPreload(u8 Copy_u8Preload)
{
	TCNT2_REG=Copy_u8Preload;
}
void TIMER2_vidSetCTC(u8 Copy_u8CTC)
{
	OCR2_REG=Copy_u8CTC;
}
void TIMER2_vidTovfInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER2_TIMSK_e_TOIE2);
}
void TIMER2_vidTovfInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER2_TIMSK_e_TOIE2);
}
void TIMER2_vidCtcInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER2_TIMSK_e_OCIE2);
}
void TIMER2_vidCtcInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER2_TIMSK_e_OCIE2);
}
void TIMER2_vidSetPwmDutyCycle(u8 Copy_u8DutyCycle)
{
	OCR2_REG=Copy_u8DutyCycle;
}
u8 TIMER2_u8SetOvfCbf(void(*fptr)(void))
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
u8 TIMER2_u8SetCtcCbf(void(*fptr)(void))
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
void __vector_4 (void) __attribute__ ((signal));
void __vector_4 (void)
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

void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
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

u8 TIMER2_u8SwitchSyncAndAsync()
{
	u8 Local_u8ErrStatus=RT_OK;
	TIMER2_vidTovfInteruptDisable();
	TIMER2_vidCtcInteruptDisable();
	Toggle_Bit(ASSR_REG,TIMER2_ASSR_e_AS2);
	while(Get_Bit(ASSR_REG,TIMER2_ASSR_e_TCN2UB)||Get_Bit(ASSR_REG,TIMER2_ASSR_e_OCR2UB)||Get_Bit(ASSR_REG,TIMER2_ASSR_e_TCR2UB));
	Clr_Bit(TIFR_REG,TIMER2_TIFR_e_OCF0);
	Clr_Bit(TIFR_REG,TIMER2_TIFR_e_TOV0);
}
