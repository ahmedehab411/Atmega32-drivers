/*
 * INT_INT.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Ahmed Ehab
 */

#ifndef INT_INT_H_
#define INT_INT_H_

#include "LIB/stdtypes.h"

typedef enum
{
	GLOBAL_INT=7,
}INTERRUPT;

typedef enum
{
	GIE_Disable,
	GIE_Enable
}GIE_STATUS;


u8 INT_u8SetGlobalInterruptStatus(GIE_STATUS Status);

#endif /* INT_INT_H_ */
