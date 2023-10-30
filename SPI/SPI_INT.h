/*
 * SPI_INT.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Ahmed Ehab
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

typedef enum
{
	SPI_SPCR_e_SPR0,
	SPI_SPCR_e_SPR1,
	SPI_SPCR_e_CPHA,
	SPI_SPCR_e_CPOL,
	SPI_SPCR_e_MSTR,
	SPI_SPCR_e_DORD,
	SPI_SPCR_e_SPE,
	SPI_SPCR_e_SPIE
}SPI_SPCR_e;

typedef enum
{
	SPI_SPSR_e_SPI2X,
	SPI_SPSR_e_WCOL=6,
	SPI_SPSR_e_SPIF,
}SPI_SPSR_e;

typedef enum
{
	SPI_DEVICE_SELECT_e_SLAVE,
	SPI_DEVICE_SELECT_e_MASTER
}SPI_DEVICE_SELECT_e;

typedef enum
{
	SPI_CLK_POL_e_LOW,
	SPI_CLK_POL_e_HIGH
}SPI_CLK_POL_e;

typedef enum
{
	SPI_CLK_PHASE_e_SAMPLE_LEADING,
	SPI_CLK_PHASE_e_SETUP_LEADING,
}SPI_CLK_PHASE_e;

typedef enum
{
	SPI_CLK_SELECT_e_PRE_4,
	SPI_CLK_SELECT_e_PRE_16,
	SPI_CLK_SELECT_e_PRE_64,
	SPI_CLK_SELECT_e_PRE_128,
	SPI_CLK_SELECT_e_PRE_2,
	SPI_CLK_SELECT_e_PRE_8,
	SPI_CLK_SELECT_e_PRE_32,
	SPI_CLK_SELECT_e_PRE_64_1
}SPI_CLK_SELECT_e;

typedef enum
{
	SPI_DATA_ORDER_e_MSB_FIRST,
	SPI_DATA_ORDER_e_LSB_FIRST
}SPI_DATA_ORDER_e;

typedef enum
{
	SPI_INT_STATUS_e_DISABLED,
	SPI_INT_STATUS_e_ENABLED
}SPI_INT_STATUS_e;
u8 SPI_VidMasterInit(SPI_INT_STATUS_e IntStatus,SPI_DATA_ORDER_e Order, SPI_CLK_POL_e Polarity,SPI_CLK_PHASE_e Phase, SPI_CLK_SELECT_e Prescalar);
u8 SPI_VidSlaveInit(SPI_INT_STATUS_e IntStatus,SPI_DATA_ORDER_e Order, SPI_CLK_POL_e Polarity,SPI_CLK_PHASE_e Phase);
void SPI_VidTranscieve(u8 Local_u8Data,u8* Recieved);
u8 SPI_u8SlaveToMaster(SPI_CLK_SELECT_e Prescalar);


#endif /* SPI_INT_H_ */
