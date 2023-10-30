/*
 * USART_PRG.c
 *
 *  Created on: Nov 13, 2021
 *      Author: Ahmed Ehab
 */

#include"LIB/stdtypes.h"
#include"LIB/bitmath.h"

#include "USART_INT.h"
#include "USART_REG.h"

void USART_Init(void)
{
	u8 Local_u8UCSRB=0;
	u8 Local_u8UCSRC=0;

	Set_Bit(Local_u8UCSRB,USART_UCSRB_e_RXEN);
	Set_Bit(Local_u8UCSRB,USART_UCSRB_e_TXEN);

	Set_Bit(Local_u8UCSRC,USART_UCSRC_e_URSEL);
	Set_Bit(Local_u8UCSRC,USART_UCSRC_e_UCSZ1);
	Set_Bit(Local_u8UCSRC,USART_UCSRC_e_UCSZ0);

	UCSRB_REG=Local_u8UCSRB;
	UCSRC_REG=Local_u8UCSRC;

	UBRRL_REG=51;
	UBRRH_REG=0;
}
void USART_SendData(u8 Data)
{
	UDR_REG=Data;
	while(Get_Bit(UCSRA_REG,USART_UCSRA_e_UDRE)==0);
}
u8 USART_RecieveData(void)
{
	u8 Recieved;
	while(Get_Bit(UCSRA_REG,USART_UCSRA_e_RXC)==0);
	Recieved=UDR_REG;
	return Recieved;
}

