/*
 * main.c
 *
 *  Created on: Nov 13, 2021
 *      Author: Ahmed Ehab
 */
#include "avr/io.h"

#include"LIB/stdtypes.h"
#include"LIB/bitmath.h"

#include "USART_INT.h"

void main (void)
{
	DDRA=0xFF;
	u8 character;
	USART_Init();
	while(1)
	{
		character=USART_RecieveData();
		if(character=='1')
		{
			PORTA=0xFF;
			USART_SendData('D');
		}
		else
		{
			PORTA=0x00;
		}
	}
}
