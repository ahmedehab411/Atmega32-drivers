/*
 * SPI_REG.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Ahmed Ehab
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPCR_REG	(*(volatile u8*)0x2D)
#define SPSR_REG	(*(volatile u8*)0x2E)
#define SPDR_REG	(*(volatile u8*)0x2F)

#endif /* SPI_REG_H_ */
