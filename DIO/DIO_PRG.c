/*
 * DIO_PRG.c
 *
 *  Created on: Sep 26, 2021
 *      Author: Ahmed Ehab
 *   Version: 1.00
 */

#include "LIB\stdtypes.h"
#include "LIB\bitmath.h"

#include "DIO_REG.h"
#include"DIO_INT.h"

u8 DIO_u8SetPortDir(DIO_PORT PortNo,u8 Copy_u8Dir)
{
	u8 Local_u8ErrStatus=RT_OK;
	if(PortNo>=DIO_PORTA && PortNo<=DIO_PORTD)
	{
		switch (PortNo)
		{
			case DIO_PORTA:
				DDRA_REG=Copy_u8Dir;
				break;
			case DIO_PORTB:
				DDRB_REG=Copy_u8Dir;
				break;
			case DIO_PORTC:
				DDRC_REG=Copy_u8Dir;
				break;
			case DIO_PORTD:
				DDRD_REG=Copy_u8Dir;
				break;
			default:
				Local_u8ErrStatus=RT_NOK;
				break;
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}
u8 DIO_u8SetPortVal(DIO_PORT PortNo,u8 Copy_u8Val)
{
	u8 Local_u8ErrStatus=RT_OK;
	if(PortNo>=DIO_PORTA && PortNo<=DIO_PORTD)
	{
		switch (PortNo)
		{
			case DIO_PORTA:
				PORTA_REG=Copy_u8Val;
				break;
			case DIO_PORTB:
				PORTB_REG=Copy_u8Val;
				break;
			case DIO_PORTC:
				PORTC_REG=Copy_u8Val;
				break;
			case DIO_PORTD:
				PORTD_REG=Copy_u8Val;
				break;
			default:
				Local_u8ErrStatus=RT_NOK;
				break;
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}
u8 DIO_u8GetPortVal(DIO_PORT PortNo,u8* Copy_u8PVal)
{
	u8 Local_u8ErrStatus=RT_OK;
	if(PortNo>=DIO_PORTA && PortNo<=DIO_PORTD)
	{
		switch (PortNo)
		{
			case DIO_PORTA:
				*Copy_u8PVal=PINA_REG;
				break;
			case DIO_PORTB:
				*Copy_u8PVal=PINB_REG;
				break;
			case DIO_PORTC:
				*Copy_u8PVal=PINC_REG;
				break;
			case DIO_PORTD:
				*Copy_u8PVal=PIND_REG;
				break;
			default:
				Local_u8ErrStatus=RT_NOK;
				break;
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}
u8 DIO_u8SetPinDir(DIO_PORT PortNo,DIO_PIN PinNo,u8 Copy_u8Dir)
{
	u8 Local_u8ErrStatus=RT_OK;
	if(PinNo<=DIO_PIN7 && PinNo>=DIO_PIN0)
	{
		if(Copy_u8Dir==LOW)
		{
			switch(PortNo)
			{
				case DIO_PORTA:
					Clr_Bit(DDRA_REG,PinNo);
					break;
				case DIO_PORTB:
					Clr_Bit(DDRB_REG,PinNo);
					break;
				case DIO_PORTC:
					Clr_Bit(DDRC_REG,PinNo);
					break;
				case DIO_PORTD:
					Clr_Bit(DDRD_REG,PinNo);
					break;
				default:
					Local_u8ErrStatus=RT_NOK;
					break;
			}
		}
		else if(Copy_u8Dir==HIGH)
		{
			switch(PortNo)
			{
				case DIO_PORTA:
					Set_Bit(DDRA_REG,PinNo);
					break;
				case DIO_PORTB:
					Set_Bit(DDRB_REG,PinNo);
					break;
				case DIO_PORTC:
					Set_Bit(DDRC_REG,PinNo);
					break;
				case DIO_PORTD:
					Set_Bit(DDRD_REG,PinNo);
					break;
				default:
					Local_u8ErrStatus=RT_NOK;
					break;
			}
		}
		else
		{
			Local_u8ErrStatus=RT_NOK;
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}
u8 DIO_u8SetPinVal(DIO_PORT PortNo,DIO_PIN PinNo,u8 Copy_u8Val)
{
	u8 Local_u8ErrStatus=RT_OK;
	if(PinNo<=DIO_PIN7 && PinNo>=DIO_PIN0)
	{
		if(Copy_u8Val==LOW)
		{
			switch(PortNo)
			{
				case DIO_PORTA:
					Clr_Bit(PORTA_REG,PinNo);
					break;
				case DIO_PORTB:
					Clr_Bit(PORTB_REG,PinNo);
					break;
				case DIO_PORTC:
					Clr_Bit(PORTC_REG,PinNo);
					break;
				case DIO_PORTD:
					Clr_Bit(PORTD_REG,PinNo);
					break;
				default:
					Local_u8ErrStatus=RT_NOK;
					break;
			}
		}
		else if(Copy_u8Val==HIGH)
		{
			switch(PortNo)
			{
				case DIO_PORTA:
					Set_Bit(PORTA_REG,PinNo);
					break;
				case DIO_PORTB:
					Set_Bit(PORTB_REG,PinNo);
					break;
				case DIO_PORTC:
					Set_Bit(PORTC_REG,PinNo);
					break;
				case DIO_PORTD:
					Set_Bit(PORTD_REG,PinNo);
					break;
				default:
					Local_u8ErrStatus=RT_NOK;
					break;
			}
		}
		else
		{
			Local_u8ErrStatus=RT_NOK;
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}
u8 DIO_u8GetPinVal(DIO_PORT PortNo,DIO_PIN PinNo,u8* Copy_u8PVal)
{
	u8 Local_u8ErrStatus=RT_OK;
	if(PinNo<=DIO_PIN7 && PinNo>=DIO_PIN0)
	{
		switch(PortNo)
		{
			case DIO_PORTA:
				*Copy_u8PVal=Get_Bit(PINA_REG,PinNo);
				break;
			case DIO_PORTB:
				*Copy_u8PVal=Get_Bit(PINB_REG,PinNo);
				break;
			case DIO_PORTC:
				*Copy_u8PVal=Get_Bit(PINC_REG,PinNo);
				break;
			case DIO_PORTD:
				*Copy_u8PVal=Get_Bit(PIND_REG,PinNo);
				break;
			default:
				Local_u8ErrStatus=RT_NOK;
				break;
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}
