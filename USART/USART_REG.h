/*
 * USART_REG.h
 *
 *  Created on: Nov 13, 2021
 *      Author: Ahmed Ehab
 */

#ifndef USART_REG_H_
#define USART_REG_H_

#define UCSRB_REG 	(*(volatile u8*)0x2A)
#define	UCSRC_REG	(*(volatile u8*)0x40)
#define UBRRL_REG	(*(volatile u8*)0x29)
#define UBRRH_REG	(*(volatile u8*)0x40)
#define UDR_REG		(*(volatile u8*)0x2C)
#define UCSRA_REG	(*(volatile u8*)0x2B)

#endif /* USART_REG_H_ */
