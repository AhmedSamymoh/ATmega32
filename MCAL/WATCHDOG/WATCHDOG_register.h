/*
 * WATCHDOG_register.h
 *
 *  Created on: Nov 3, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_WATCHDOG_WATCHDOG_REGISTER_H_
#define MCAL_WATCHDOG_WATCHDOG_REGISTER_H_

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"

#define WDTCR				( *(volatile uint8*)(0x41) )

#define WDTCR_WDTOE			4
#define WDTCR_WDE			3
#define WDTCR_WDP2			2
#define WDTCR_WDP1			1
#define WDTCR_WDP0			0

void WDT_Enable(void);
void WDT_Disable(void);
void WDT_Sleep(uint8 time);


#endif /* MCAL_WATCHDOG_WATCHDOG_REGISTER_H_ */
