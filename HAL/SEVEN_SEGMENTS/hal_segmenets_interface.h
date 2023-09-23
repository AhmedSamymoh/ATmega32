/*
 * hal_segmenets_interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: AhmedSamy
 */

#ifndef HAL_SEVEN_SEGMENTS_HAL_SEGMENETS_INTERFACE_H_
#define HAL_SEVEN_SEGMENTS_HAL_SEGMENETS_INTERFACE_H_



/* Section : Includes */
#include"../../MCAL/DIO/DIO_interface.h"

/* Section: Data Type Declarations */

// Seven-segment codes for digits 0-9
extern uint8 Segments_Arr[10];

/* Section: Macro Declarations */
#define COMMON_CATHODE					0
#define COMMON_ANODE					1

#define ENABLE_COMMON_CATHODE			0
#define ENABLE_COMMON_ANODE				1

#define DISABLE_COMMON_CATHODE			1
#define DISABLE_COMMON_ANODE			0


/* Section: Macro Functions Declarations */

/* Section: Function Declarations */
void SEGMENT_Init(uint8 DataPort ,uint8 ControlPort , uint8 ControlPin , uint8 SegType);
void SEGMENT_Enable(uint8 ControlPort , uint8 ControlPin , uint8 SegType);
void SEGMENT_Disable(uint8 ControlPort , uint8 ControlPin , uint8 SegType);
void SEGMENT_Display(uint8 DataPort ,uint8 SegType , uint8 Number);







#endif /* HAL_SEVEN_SEGMENTS_HAL_SEGMENETS_INTERFACE_H_ */
