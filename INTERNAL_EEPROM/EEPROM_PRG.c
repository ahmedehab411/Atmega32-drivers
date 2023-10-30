/*
 * EEPROM_PRG.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Ahmed Ehab
 */

#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "EEPROM_INT.h"
#include "EEPROM_REG.h"

#include "avr/eeprom.h"
u8 EEPROM_u8ReadByte(u16 Address,u8 *Data)
{
	u8 Local_u8ErrorStatus=RT_OK;
	/*Polling on EEWE bit to know if there is write operation is still running*/
	while(Get_Bit(EECR_REG,EECR_REG_e_EEWE)==1);
	/*Setting up the new Address*/
	if(Address<=1023)
	{
		EEARL_REG= (u8)Address;
		EEARH_REG= (u8)(Address>>8);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	/*Start the Read operation*/
	Set_Bit(EECR_REG,EECR_REG_e_EERE);

	/*Save the byte in the Data pointer*/
	*Data=EEDR_REG;

	return Local_u8ErrorStatus;
}
u8 EEPROM_u8WriteByte(u16 Address,u8 Data);
u8 EEPROM_u8ReadInteger(u16 Address,u32 *Data);
u8 EEPROM_u8WriteInteger(u16 Address,u32 Data);

