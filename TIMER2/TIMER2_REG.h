/*
 * TIMER2_REG.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Ahmed Ehab
 */

#ifndef TIMER2_REG_H_
#define TIMER2_REG_H_

#define  TIMSK_REG	(*(volatile u8*) 0x59)
#define  TIFR_REG	(*(volatile u8*) 0x58)
#define  SFIOR_REG	(*(volatile u8*) 0x50)
#define  TCCR2_REG	(*(volatile u8*) 0x45)
#define  TCNT2_REG	(*(volatile u8*) 0x44)
#define  OCR2_REG	(*(volatile u8*) 0x43)
#define  ASSR_REG	(*(volatile u8*) 0x42)


#endif /* TIMER2_REG_H_ */
