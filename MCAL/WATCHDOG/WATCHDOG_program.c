/*
 * WATCHDOG_program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: AhmedSamy
 */

#include "WATCHDOG_register.h"


void WDT_Enable(void){
	SET_BIT(WDTCR , WDTCR_WDE);

}

void WDT_Sleep(uint8 time){

	WDTCR &= 0b11111000;
	WDTCR |= time;
}

void WDT_Disable(void){
	/*procedure to Disable The WatchDog Timer
	 * write a logic one to WDTOE and WDE. A logic one must be written
	 *to WDE even though it is set to one before the disable operation starts.*/
	WDTCR |= 0b00011000;
	WDTCR = 0;
	//CLR_BIT( WDTCR ,WDTCR_WDE);
}

