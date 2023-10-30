/*
 * INT_PRG.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Ahmed Ehab
 */

#include "LIB\stdtypes.h"
#include "LIB\bitmath.h"

#include "INT_REG.h"
#include "INT_INT.h"
u8 INT_u8SetGlobalInterruptStatus(GIE_STATUS Status)
{
	u8 Local_u8ErrorStatus=RT_OK;
	switch (Status)
	{
		case GIE_Disable:
			Clr_Bit(SREG_REG,GLOBAL_INT);
			break;
		case GIE_Enable:
			Set_Bit(SREG_REG,GLOBAL_INT);
			break;
		default:
			Local_u8ErrorStatus= RT_NOK;
	}
	return Local_u8ErrorStatus;
}
