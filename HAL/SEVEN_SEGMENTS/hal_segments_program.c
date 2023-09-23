/*
 * hal_segments_program.c
 *
 *  Created on: Sep 8, 2023
 *      Author: AhmedSamy
 */

#include "hal_segmenets_interface.h"

uint8 Segments_Arr[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};


void SEGMENT_Init(uint8 DataPort ,uint8 ControlPort , uint8 ControlPin , uint8 SegType){
	if(COMMON_CATHODE == SegType)
	{
		DIO_SetPinDirection( ControlPort, ControlPin, PIN_OUTPUT);
		DIO_SetPortDirection( DataPort, PORT_OUTPUT);
	}else if(COMMON_ANODE == SegType)
	{
		DIO_SetPinDirection( ControlPort, ControlPin, PIN_OUTPUT);
		DIO_SetPortDirection( DataPort, PORT_OUTPUT);
	}
	else{

	}
}
void SEGMENT_Enable(uint8 ControlPort , uint8 ControlPin , uint8 SegType){
	if(COMMON_CATHODE == SegType)
	{
		DIO_SetPinValue( ControlPort, ControlPin, ENABLE_COMMON_CATHODE);

	}else if(COMMON_ANODE == SegType)
	{
		DIO_SetPinValue( ControlPort, ControlPin, ENABLE_COMMON_ANODE);
	}
	else{

	}
}
void SEGMENT_Disable(uint8 ControlPort , uint8 ControlPin , uint8 SegType){
	if(COMMON_CATHODE == SegType)
	{
		DIO_SetPinValue( ControlPort, ControlPin, DISABLE_COMMON_CATHODE);

	}else if(COMMON_ANODE == SegType)
	{
		DIO_SetPinValue( ControlPort, ControlPin, DISABLE_COMMON_ANODE);
	}
	else{

	}
}
void SEGMENT_Display(uint8 DataPort ,uint8 SegType , uint8 Number){


	if(COMMON_CATHODE == SegType)
	{
		DIO_SetPortValue( DataPort, Segments_Arr[Number]);

	}else if(COMMON_ANODE == SegType)
	{
		DIO_SetPortValue( DataPort , ~Segments_Arr[Number]);
	}
	else{

	}
}

