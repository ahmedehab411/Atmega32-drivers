/*
	Author: Ahmed Ehab Atif
	Date: 13Aug,2021
	version: 1.0
*/
#ifndef _STDTYPES_H_
#define _STDTYPES_H_

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;
typedef double f64;

typedef enum
{
	RT_OK,
	RT_NOK
}ERROR_STATUS;

#define NULL ((void*)0)

#endif
