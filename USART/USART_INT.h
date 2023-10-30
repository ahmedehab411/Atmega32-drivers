/*
 * USART_INT.h
 *
 *  Created on: Nov 13, 2021
 *      Author: Ahmed Ehab
 */

#ifndef USART_INT_H_
#define USART_INT_H_

typedef enum
{
	USART_UCSRA_e_MPCM,
	USART_UCSRA_e_U2X,
	USART_UCSRA_e_PE,
	USART_UCSRA_e_DOR,
	USART_UCSRA_e_FE,
	USART_UCSRA_e_UDRE,
	USART_UCSRA_e_TXC,
	USART_UCSRA_e_RXC
}USART_UCSRA_e;

typedef enum
{
	USART_UCSRB_e_TXB8,
	USART_UCSRB_e_RXB8,
	USART_UCSRB_e_UCSZ2,
	USART_UCSRB_e_TXEN,
	USART_UCSRB_e_RXEN,
	USART_UCSRB_e_UDRIE,
	USART_UCSRB_e_TXCIE,
	USART_UCSRB_e_RXCIE
}USART_UCSRB_e;

typedef enum
{
	USART_UCSRC_e_UCPOL,
	USART_UCSRC_e_UCSZ0,
	USART_UCSRC_e_UCSZ1,
	USART_UCSRC_e_USBS,
	USART_UCSRC_e_UPM0,
	USART_UCSRC_e_UPM1,
	USART_UCSRC_e_UMSEL,
	USART_UCSRC_e_URSEL
}USART_UCSRC_e;



void USART_Init(void);
void USART_SendData(u8 Data);
u8 USART_RecieveData(void);

#endif /* USART_INT_H_ */
