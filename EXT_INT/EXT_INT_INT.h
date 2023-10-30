/*
 * INT_INT.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Ahmed Ehab
 */

#ifndef EXT_INT_INT_H_
#define EXT_INT_INT_H_


typedef enum
{
	INT0_ISC0=0,
	INT0_ISC1=1,
	INT1_ISC0=2,
	INT1_ISC1=3,
	INT2_ISC=6
}INT_SENSE;

typedef enum
{
	INT0_FLAG=6,
	INT1_FLAG=7,
	INT2_FLAG=5
}INT_FLAG;

typedef enum
{
	INT_RISING,
	INT_FALLING,
	INT_LOW,
	INT_CHANGE
}SENSE_TYPE;

typedef enum
{
	INT0_EN=6,
	INT1_EN=7,
	INT2_EN=5,
}INT_EN;

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2,
}INT_NO;


u8 EXT_INT_u8EnableExtInt(INT_NO IntNo);
u8 EXT_INT_u8SenseControl(INT_NO IntNo,SENSE_TYPE Sense);
u8 EXT_INT_u8SoftwareIntEn(INT_NO Intno);
u8 EXT_INT_u8SetIntCallback(INT_NO IntNo,void (*FPTR)());
#endif /* EXT_INT_INT_H_ */
