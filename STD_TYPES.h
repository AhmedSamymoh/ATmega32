/*
 * STD_TYPES.h
 *
 *  Created on: Sep 1, 2023
 *      Author: AhmedSamy
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

typedef signed char         sint8;
typedef signed short        sint16;
typedef signed int          sint32;
typedef signed long long    sint64;

#define NULL 		(void*)0


typedef unsigned char       bool;


#define E_OK 		1
#define E_NOT_OK 	0

#define TRUE 		0x01U
#define FALSE 		0x00U

#endif /* STD_TYPES_H_ */
