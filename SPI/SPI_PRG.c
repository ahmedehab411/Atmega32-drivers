/*
 * SPI_PRG.c
 *
 *  Created on: Oct 4, 2023
 *      Author: Ahmed Ehab
 */

#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "SPI_REG.h"
#include "SPI_INT.h"

u8 SPI_VidMasterInit(SPI_INT_STATUS_e IntStatus,SPI_DATA_ORDER_e Order, SPI_CLK_POL_e Polarity,SPI_CLK_PHASE_e Phase, SPI_CLK_SELECT_e Prescalar)
{
	u8 Local_u8ErrorStatus=RT_OK;

	switch (IntStatus)
	{
	case SPI_INT_STATUS_e_DISABLED:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPIE);
		break;
	case SPI_INT_STATUS_e_ENABLED:
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPIE);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}

	switch (Order)
	{
	case SPI_DATA_ORDER_e_MSB_FIRST:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_DORD);
		break;
	case SPI_DATA_ORDER_e_LSB_FIRST:
		Set_Bit(SPCR_REG,SPI_SPCR_e_DORD);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}

	Set_Bit(SPCR_REG,SPI_SPCR_e_MSTR);

	switch (Polarity)
	{
	case SPI_CLK_POL_e_LOW:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_CPOL);
		break;
	case SPI_CLK_POL_e_HIGH:
		Set_Bit(SPCR_REG,SPI_SPCR_e_CPOL);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}

	switch (Phase)
	{
	case SPI_CLK_PHASE_e_SAMPLE_LEADING:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_CPHA);
		break;
	case SPI_CLK_PHASE_e_SETUP_LEADING:
		Set_Bit(SPCR_REG,SPI_SPCR_e_CPHA);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}

	switch (Prescalar)
	{
	case SPI_CLK_SELECT_e_PRE_4:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	case SPI_CLK_SELECT_e_PRE_16:
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	case SPI_CLK_SELECT_e_PRE_64:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	case SPI_CLK_SELECT_e_PRE_128:
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	case SPI_CLK_SELECT_e_PRE_2:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	case SPI_CLK_SELECT_e_PRE_8:
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	case SPI_CLK_SELECT_e_PRE_32:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	case SPI_CLK_SELECT_e_PRE_64_1:
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
		Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}
	Set_Bit(SPCR_REG,SPI_SPCR_e_SPE);
	return Local_u8ErrorStatus;
}
u8 SPI_VidSlaveInit(SPI_INT_STATUS_e IntStatus,SPI_DATA_ORDER_e Order, SPI_CLK_POL_e Polarity,SPI_CLK_PHASE_e Phase)
{
	u8 Local_u8ErrorStatus=RT_OK;

	switch (IntStatus)
	{
	case SPI_INT_STATUS_e_DISABLED:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_SPIE);
		break;
	case SPI_INT_STATUS_e_ENABLED:
		Set_Bit(SPCR_REG,SPI_SPCR_e_SPIE);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}

	switch (Order)
	{
	case SPI_DATA_ORDER_e_MSB_FIRST:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_DORD);
		break;
	case SPI_DATA_ORDER_e_LSB_FIRST:
		Set_Bit(SPCR_REG,SPI_SPCR_e_DORD);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}

	Clr_Bit(SPCR_REG,SPI_SPCR_e_MSTR);

	switch (Polarity)
	{
	case SPI_CLK_POL_e_LOW:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_CPOL);
		break;
	case SPI_CLK_POL_e_HIGH:
		Set_Bit(SPCR_REG,SPI_SPCR_e_CPOL);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}

	switch (Phase)
	{
	case SPI_CLK_PHASE_e_SAMPLE_LEADING:
		Clr_Bit(SPCR_REG,SPI_SPCR_e_CPHA);
		break;
	case SPI_CLK_PHASE_e_SETUP_LEADING:
		Set_Bit(SPCR_REG,SPI_SPCR_e_CPHA);
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}
	Set_Bit(SPCR_REG,SPI_SPCR_e_SPE);
	return Local_u8ErrorStatus;
}
void SPI_VidTranscieve(u8 Local_u8Data,u8* Recieved)
{
	SPDR_REG=Local_u8Data;
	while(Get_Bit(SPSR_REG,SPI_SPSR_e_SPIF)==0);
	*Recieved=SPDR_REG;
}
u8 SPI_u8SlaveToMaster(SPI_CLK_SELECT_e Prescalar)
{
	u8 Local_u8ErrorStatus=RT_OK;

	Set_Bit(SPCR_REG,SPI_SPCR_e_MSTR);

	switch (Prescalar)
		{
		case SPI_CLK_SELECT_e_PRE_4:
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		case SPI_CLK_SELECT_e_PRE_16:
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		case SPI_CLK_SELECT_e_PRE_64:
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		case SPI_CLK_SELECT_e_PRE_128:
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Clr_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		case SPI_CLK_SELECT_e_PRE_2:
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		case SPI_CLK_SELECT_e_PRE_8:
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		case SPI_CLK_SELECT_e_PRE_32:
			Clr_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		case SPI_CLK_SELECT_e_PRE_64_1:
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR0);
			Set_Bit(SPCR_REG,SPI_SPCR_e_SPR1);
			Set_Bit(SPSR_REG,SPI_SPSR_e_SPI2X);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
			break;
		}
	return Local_u8ErrorStatus;
}
