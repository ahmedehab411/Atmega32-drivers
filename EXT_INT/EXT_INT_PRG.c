/*
 * INT_PRG.c
 *
 *  Created on: Oct 8, 2021
 *      Author: Ahmed Ehab
 */
#include"LIB\stdtypes.h"
#include"LIB\bitmath.h"

#include"EXT_INT_REG.h"
#include"EXT_INT_INT.h"

void (*INT0ADDR)(void)=NULL;
void (*INT1ADDR)(void)=NULL;
void (*INT2ADDR)(void)=NULL;

u8 EXT_INT_u8EnableExtInt(INT_NO IntNo)
{
	u8 Local_u8ErrorStatus=RT_OK;
	switch (IntNo)
	{
	case EXT_INT0:
		Set_Bit(GICR_REG,INT0_EN);
		break;
	case EXT_INT1:
		Set_Bit(GICR_REG,INT1_EN);
		break;
	case EXT_INT2:
		Set_Bit(GICR_REG,INT2_EN);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}
	return Local_u8ErrorStatus;
}
u8 EXT_INT_u8SenseControl(INT_NO IntNo,SENSE_TYPE Sense)
{
	u8 Local_u8ErrorStatus=RT_OK;
	switch (IntNo)
	{
	case EXT_INT0:
		switch (Sense)
		{
		case INT_RISING:
			Set_Bit(MCUCR_REG,INT0_ISC0);
			Set_Bit(MCUCR_REG,INT0_ISC1);
			break;
		case INT_FALLING:
			Clr_Bit(MCUCR_REG,INT0_ISC0);
			Set_Bit(MCUCR_REG,INT0_ISC1);
			break;
		case INT_LOW:
			Clr_Bit(MCUCR_REG,INT0_ISC0);
			Clr_Bit(MCUCR_REG,INT0_ISC1);
			break;
		case INT_CHANGE:
			Set_Bit(MCUCR_REG,INT0_ISC0);
			Clr_Bit(MCUCR_REG,INT0_ISC1);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
		break;
		case EXT_INT1:
			switch (Sense)
			{
			case INT_RISING:
				Set_Bit(MCUCR_REG,INT1_ISC0);
				Set_Bit(MCUCR_REG,INT1_ISC1);
				break;
			case INT_FALLING:
				Clr_Bit(MCUCR_REG,INT1_ISC0);
				Set_Bit(MCUCR_REG,INT1_ISC1);
				break;
			case INT_LOW:
				Clr_Bit(MCUCR_REG,INT1_ISC0);
				Clr_Bit(MCUCR_REG,INT1_ISC1);
				break;
			case INT_CHANGE:
				Set_Bit(MCUCR_REG,INT1_ISC0);
				Clr_Bit(MCUCR_REG,INT1_ISC1);
				break;
			default:
				Local_u8ErrorStatus=RT_NOK;
				break;
			}
			break;
			case EXT_INT2:
				switch (Sense)
				{
				case INT_RISING:
					Set_Bit(MCUCSR_REG,INT2_ISC);
					break;
				case INT_FALLING:
					Clr_Bit(MCUCSR_REG,INT2_ISC);
					break;
				default:
					Local_u8ErrorStatus=RT_NOK;
					break;
				}
				break;
				default:
					Local_u8ErrorStatus=RT_NOK;
					break;
	}
	return Local_u8ErrorStatus;
}

u8 EXT_INT_u8SetIntCallback(INT_NO IntNo,void (*FPTR)())
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(FPTR!=NULL)
	{
		switch (IntNo)
		{
		case EXT_INT0:
			INT0ADDR=FPTR;
			break;
		case EXT_INT1:
			INT1ADDR=FPTR;
			break;
		case EXT_INT2:
			INT2ADDR=FPTR;
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

void __vector_1(void) __attribute__((Signal));
void __vector_1(void)
{
	if(INT0ADDR!=NULL)
	{
		INT0ADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}
void __vector_2(void) __attribute__((Signal));
void __vector_2(void)
{
	if(INT1ADDR!=NULL)
	{
		INT1ADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}
void __vector_3(void) __attribute__((Signal));
void __vector_3(void)
{
	if(INT2ADDR!=NULL)
	{
		INT2ADDR();
	}
	else
	{
		/*Do Nothing*/
	}
}
