/*
 * INT_REG.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Ahmed Ehab
 */

#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_

#define MCUCR_REG (*(volatile u8*)0x55)
#define MCUCSR_REG (*(volatile u8*)0x54)
#define GICR_REG (*(volatile u8*)0x5B)
#define GIFR_REG (*(volatile u8*)0x5A)

#endif /* EXT_INT_REG_H_ */

