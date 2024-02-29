/*
 * USART_interface.h
 *
 *  Created on: Feb 28, 2024
 *      Author: AhmedSamy
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_


/* Section : Includes */
#include "USART_register.h"

/* Section: Data Type Declarations */


/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */


/* Section: Function Declarations */

void USART_Init();
uint8 USART_u8ReceiveData();
void USART_voidSendData(uint8 Data);

void USART_RX_InterruptEnable();
void USART_RX_InterruptDisable();
void USART_TX_InterruptEnable();
void USART_TX_InterruptDisable();

void USART_SetCallBack_RX( void (*Ptr2Fun)(void) );
void USART_SetCallBack_TX( void (*Ptr2Fun)(void) );





#endif /* MCAL_USART_USART_INTERFACE_H_ */
