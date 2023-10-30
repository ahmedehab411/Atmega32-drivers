/*
 * DIO_INT.h
 *
 *  Created on: Sep 26, 2021
 *      Author: Ahmed Ehab
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_PORT;

typedef enum
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}DIO_PIN;

typedef enum
{
	LOW=0,
	HIGH=1,
	FULL_LOW=0x00,
	FULL_HIGH=0xFF
}SIGNAL;

typedef enum
{
	INPUT=0,
	OUTPUT=1,
	FULL_INPUT=0x00,
	FULL_OUTPUT=0xFF
}DIRECTION;

u8 DIO_u8SetPortDir(DIO_PORT PortNo,u8 Copy_u8Dir);
u8 DIO_u8SetPortVal(DIO_PORT PortNo,u8 Copy_u8Val);
u8 DIO_u8GetPortVal(DIO_PORT PortNo,u8* Copy_u8PVal);
u8 DIO_u8SetPinDir(DIO_PORT PortNo,DIO_PIN PinNo,u8 Copy_u8Dir);
u8 DIO_u8SetPinVal(DIO_PORT PortNo,DIO_PIN PinNo,u8 Copy_u8Val);
u8 DIO_u8GetPinVal(DIO_PORT PortNo,DIO_PIN PinNo,u8* Copy_u8PVal);
#endif /* DIO_INT_H_ */
