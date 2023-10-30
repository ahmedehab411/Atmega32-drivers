/*
 * EEPROM_INT.h
 *
 *  Created on: Oct 5, 2023
 *      Author: Ahmed Ehab
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

typedef enum
{
	EECR_REG_e_EERE,
	EECR_REG_e_EEWE,
	EECR_REG_e_EEMWE,
	EECR_REG_e_EERIE
}EECR_REG_e;

u8 EEPROM_u8ReadByte(u16 Address,u8 *Data);
u8 EEPROM_u8WriteByte(u16 Address,u8 Data);
u8 EEPROM_u8ReadInteger(u16 Address,u32 *Data);
u8 EEPROM_u8WriteInteger(u16 Address,u32 Data);

#endif /* EEPROM_INT_H_ */
