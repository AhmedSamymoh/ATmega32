/*
 * GIE_program.c
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedSamy
 */


#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"

#include "GIE_interface.h"

void GIE_voidEnableGlobal(void)
{
	__asm volatile ("SEI");
}

void GIE_voidDisableGlobal(void)
{
	__asm volatile ("CLI");
}
