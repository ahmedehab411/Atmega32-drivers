/*
 * bitmath.h
 *
 *  Created on: Sep 26, 2021
 *      Author: Ahmed Ehab
 *   Version: 2.00
 */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define Set_Bit(Var,BitNo) Var |= (1<<(BitNo))
#define Clr_Bit(Var,BitNo) Var &= (~(1<<(BitNo)))
#define Toggle_Bit(Var,BitNo) Var ^= (1<<(BitNo))
#define Get_Bit(Var,BitNo)     ((Var>>BitNo) & 1)

#endif
