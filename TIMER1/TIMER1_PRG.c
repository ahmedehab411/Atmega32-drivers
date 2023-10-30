/*
 * TIMER1_PRG.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Ahmed Ehab
 */


#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "TIMER1_INT.h"
#include "TIMER1_REG.h"

static void (*OVFADDR)(void)=NULL;
static void (*CTCAADDR)(void)=NULL;
static void (*CTCBADDR)(void)=NULL;
static void (*ICRADDR)(void)=NULL;

u8 TIMER1_u8Init(TIMER1_MODE_e TimerMode)
{
	u8 Local_u8ErrStatus=RT_OK;
	switch (TimerMode)
	{
	case TIMER1_MODE_e_NORMAL:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_PWM_8bit:
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_PWM_9bit:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_PWM_10bit:
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_CTC_OCR1A:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_FAST_PWM_8bit:
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_FAST_PWM_9bit:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_FAST_PWM_10bit:
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_PWM_FREQUENCY_ICR1:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_PWM_FREQUENCY_OCR1A:
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_PWM_ICR1:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_PWM_OCR1A:
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_CTC_ICR1:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_FAST_PWM_ICR1:
		Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	case TIMER1_MODE_e_FAST_PWM_OCR1A:
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM10);
		Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_WGM11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM12);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_WGM13);
		break;
	default:
		Local_u8ErrStatus-RT_NOK;
		break;
	}
	return Local_u8ErrStatus;
}
u8 TIMER1_u8ClkSelect(TIMER1_CLK_SELECT_e ClkSelect)
{
	u8 Local_u8ErrStatus=RT_OK;
	switch (ClkSelect)
	{
	case TIMER1_CLK_SELECT_e_NO_CLK:
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	case TIMER1_CLK_SELECT_e_NO_PRE:
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	case TIMER1_CLK_SELECT_e_PRE_8:
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	case TIMER1_CLK_SELECT_e_PRE_64:
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	case TIMER1_CLK_SELECT_e_PRE_256:
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	case TIMER1_CLK_SELECT_e_PRE_1024:
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	case TIMER1_CLK_SELECT_e_EXT_FALLING:
		Clr_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	case TIMER1_CLK_SELECT_e_EXT_RISING:
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS10);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS11);
		Set_Bit(TCCR1B_REG,TIMER1_TCCR1B_e_CS12);
		break;
	default:
		Local_u8ErrStatus=RT_NOK;
		break;
	}
	return Local_u8ErrStatus;
}
u8 TIMER1_vidSetPwmMode(TIMER1_PHASE_CORRECT_PWM_COMPARE_e PwmMode, TIMER1_CHANNEL_e Channel)
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Channel==TIMER1_CHANNEL_e_CHANNEL_A)
	{
		switch (PwmMode) {
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_TOGGLE_OC1A:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_CLEAR_ON_UPCOUNTING:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_SET_ON_UPCOUNTING:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else if(Channel==TIMER1_CHANNEL_e_CHANNEL_B)
	{
		switch (PwmMode) {
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_TOGGLE_OC1A:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_CLEAR_ON_UPCOUNTING:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_PHASE_CORRECT_PWM_COMPARE_e_SET_ON_UPCOUNTING:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}

u8 TIMER1_vidSetFastPwmMode(TIMER1_FAST_PWM_COMPARE_e PwmMode, TIMER1_CHANNEL_e Channel)
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Channel==TIMER1_CHANNEL_e_CHANNEL_A)
	{
		switch (PwmMode) {
		case TIMER1_FAST_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_FAST_PWM_COMPARE_e_TOGGLE_OC1A:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_FAST_PWM_COMPARE_e_CLEAR_OC1A_OC1B:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_FAST_PWM_COMPARE_e_SET_OC1A_OC1B:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else if(Channel==TIMER1_CHANNEL_e_CHANNEL_B)
	{
		switch (PwmMode) {
		case TIMER1_FAST_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_FAST_PWM_COMPARE_e_TOGGLE_OC1A:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_FAST_PWM_COMPARE_e_CLEAR_OC1A_OC1B:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_FAST_PWM_COMPARE_e_SET_OC1A_OC1B:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
u8 TIMER1_vidSetFreqPwmMode(TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e PwmMode, TIMER1_CHANNEL_e Channel)
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Channel==TIMER1_CHANNEL_e_CHANNEL_A)
	{
		switch (PwmMode) {
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_TOGGLE_OC1A:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_CLEAR_ON_UPCOUNTING:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_SET_ON_UPCOUNTING:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else if(Channel==TIMER1_CHANNEL_e_CHANNEL_B)
	{
		switch (PwmMode) {
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_TOGGLE_OC1A:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_CLEAR_ON_UPCOUNTING:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_COMPARE_e_SET_ON_UPCOUNTING:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
u8 TIMER1_vidSetNonPwmMode(TIMER1_NON_PWM_COMPARE_e PwmMode, TIMER1_CHANNEL_e Channel)
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Channel==TIMER1_CHANNEL_e_CHANNEL_A)
	{
		switch (PwmMode) {
		case TIMER1_NON_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_NON_PWM_COMPARE_e_TOGGLE_OC1A_OC1B:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_NON_PWM_COMPARE_e_CLEAR_OC1A_OC1B:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		case TIMER1_NON_PWM_COMPARE_e_SET_OC1A_OC1B:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1A1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else if(Channel==TIMER1_CHANNEL_e_CHANNEL_B)
	{
		switch (PwmMode) {
		case TIMER1_NON_PWM_COMPARE_e_NORMAL:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_NON_PWM_COMPARE_e_TOGGLE_OC1A_OC1B:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_NON_PWM_COMPARE_e_CLEAR_OC1A_OC1B:
			Clr_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		case TIMER1_NON_PWM_COMPARE_e_SET_OC1A_OC1B:
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B0);
			Set_Bit(TCCR1A_REG,TIMER1_TCCR1A_e_COM1B1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
void TIMER1_vidStartTimer(void);
void TIMER1_vidStopTimer(void);
void TIMER1_vidSetPreload(u16 Copy_u16Preload)
{
	TCNT1_REG=Copy_u16Preload;
}
void TIMER1_vidSetCTCA(u16 Copy_u16CTC)
{
	OCR1A_REG=Copy_u16CTC;
}
void TIMER1_vidSetCTCB(u16 Copy_u16CTC)
{
	OCR1B_REG=Copy_u16CTC;
}
void TIMER1_vidTovfInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER1_TIMSK_e_TOIE1);
}
void TIMER1_vidTovfInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER1_TIMSK_e_TOIE1);
}
void TIMER1_vidCtcAInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER1_TIMSK_e_OCIE1A);
}
void TIMER1_vidCtcAInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER1_TIMSK_e_OCIE1A);
}
void TIMER1_vidCtcBInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER1_TIMSK_e_OCIE1B);
}
void TIMER1_vidCtcBInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER1_TIMSK_e_OCIE1B);
}
void TIMER1_vidICRInteruptEnable(void)
{
	Set_Bit(TIMSK_REG,TIMER1_TIMSK_e_TICIE1);
}
void TIMER1_vidICRInteruptDisable(void)
{
	Clr_Bit(TIMSK_REG,TIMER1_TIMSK_e_TICIE1);
}
void TIMER1_vidSetPwmADutyCycle(u16 Copy_u16DutyCycle)
{
	OCR1A_REG=Copy_u16DutyCycle;
}
void TIMER1_vidSetPwmBDutyCycle(u16 Copy_u16DutyCycle)
{
	OCR1B_REG=Copy_u16DutyCycle;
}
void TIMER1_vidSetICRValue(u16 Copy_u16ICRValue)
{
	ICR1_REG=Copy_u16ICRValue;
}

u8 TIMER1_u8SetOvfCbf(void(*fptr)(void))
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
u8 TIMER1_u8SetCtcACbf(void(*fptr)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(fptr!=NULL)
	{
		CTCAADDR=fptr;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
u8 TIMER1_u8SetCtcBCbf(void(*fptr)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(fptr!=NULL)
	{
		CTCBADDR=fptr;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
u8 TIMER1_u8SetICRCbf(void(*fptr)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(fptr!=NULL)
	{
		ICRADDR=fptr;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(OVFADDR!=NULL)
	{
		ICRADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_7 (void) __attribute__ ((signal));
void __vector_7 (void)
{
	if(CTCAADDR!=NULL)
	{
		CTCAADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_8 (void) __attribute__ ((signal));
void __vector_8 (void)
{
	if(CTCBADDR!=NULL)
	{
		CTCBADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
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

