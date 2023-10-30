/*
 * TIMER_INT.h
 *
 *  Created on: Nov 9, 2021
 *      Author: Ahmed Ehab
 */

#ifndef TIMER0_INT_H__
#define TIMER0_INT_H_H_

typedef enum
{
	TIMER0_TCCR0_e_CS00,
	TIMER0_TCCR0_e_CS01,
	TIMER0_TCCR0_e_CS02,
	TIMER0_TCCR0_e_WGM01,
	TIMER0_TCCR0_e_COM00,
	TIMER0_TCCR0_e_COM01,
	TIMER0_TCCR0_e_WGM00,
	TIMER0_TCCR0_e_FOC0
}TIMER0_TCCR0_e;

typedef enum
{
	TIMER0_TIMSK_e_TOIE0,
	TIMER0_TIMSK_e_OCIE0
}TIMER0_TIMSK_e;

typedef enum
{
	TIMER0_MODE_e_NORMAL,
	TIMER0_MODE_e_PWM,
	TIMER0_MODE_e_CTC,
	TIMER0_MODE_e_FAST_PWM
}TIMER0_MODE_e;

typedef enum
{
	TIMER0_PWM_COMPARE_e_NORMAL,
	TIMER0_PWM_COMPARE_e_TOGGLE_OC0,
	TIMER0_PWM_COMPARE_e_CLEAR_OC0,
	TIMER0_PWM_COMPARE_e_SET_OC0
}TIMER0_NON_PWM_COMPARE_e;

typedef enum
{
	TIMER0_PHASE_CORRECT_PWM_COMPARE_e_NORMAL,
	TIMER0_PHASE_CORRECT_PWM_COMPARE_e_TOGGLE_OC0,
	TIMER0_PHASE_CORRECT_PWM_COMPARE_e_CLEAR_ON_UPCOUNTING,
	TIMER0_PHASE_CORRECT_PWM_COMPARE_e_SET_ON_UPCOUNTING,
}TIMER0_PHASE_CORRECT_PWM_COMPARE_e;

typedef enum
{
	TIMER0_FAST_PWM_COMPARE_e_NORMAL,
	TIMER0_FAST_PWM_COMPARE_e_RESERVED,
	TIMER0_FAST_PWM_COMPARE_e_CLEAR_OC0,
	TIMER0_FAST_PWM_COMPARE_e_SET_OC0
}TIMER0_FAST_PWM_COMPARE_e;

typedef enum
{
	TIMER0_TIFR_e_TOV0,
	TIMER0_TIFR_e_OCF0
}TIMER0_TIFR_e;

typedef enum
{
	TIMER0_CLK_SELECT_e_NO_CLK,
	TIMER0_CLK_SELECT_e_NO_PRE,
	TIMER0_CLK_SELECT_e_PRE_8,
	TIMER0_CLK_SELECT_e_PRE_64,
	TIMER0_CLK_SELECT_e_PRE_256,
	TIMER0_CLK_SELECT_e_PRE_1024,
	TIMER0_CLK_SELECT_e_EXT_FALLING,
	TIMER0_CLK_SELECT_e_EXT_RISING,
}TIMER0_CLK_SELECT_e;

u8 TIMER0_u8Init(TIMER0_MODE_e TimerMode);
u8 TIMER0_u8ClkSelect(TIMER0_CLK_SELECT_e ClkSelect);
void TIMER0_vidStartTimer(void);
void TIMER0_vidStopTimer(void);
void TIMER0_vidSetPreload(u8 Copy_u8Preload);
void TIMER0_vidSetCTC(u8 Copy_u8CTC);
void TIMER0_vidTovfInteruptEnable(void);
void TIMER0_vidTovfInteruptDisable(void);
void TIMER0_vidCtcInteruptEnable(void);
void TIMER0_vidCtcInteruptDisable(void);
void TIMER0_vidSetPwmDutyCycle(u8 Copy_u8DutyCycle);
u8 TIMER0_u8SetOvfCbf(void(*fptr)(void));
u8 TIMER0_u8SetCtcCbf(void(*fptr)(void));

#endif /TIMER0_INT_H__H_ */