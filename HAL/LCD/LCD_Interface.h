/*
 * LCD_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: AhmedSamy
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Section : Includes */
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_Confg.h"


/* Section: Data Type Declarations */


/* Section: Macro Declarations */

#define _LCD_CLEAR                             0x01
#define _LCD_RETURN_HOME                       0x02
#define _LCD_ENTRY_MODE                        0x06

#define _LCD_CURSOR_OFF_DISPLAY_OFF            0x08
#define _LCD_CURSOR_OFF_DISPLAY_ON             0x0C

#define _LCD_CURSOR_ON_BLINK_ON                0x0F
#define _LCD_CURSOR_ON_BLINK_OFF               0x0E

#define _LCD_DISPLAY_SHIFT_RIGHT               0x1C
#define _LCD_DISPLAY_SHIFT_LIFT                0x18

#define _LCD_8BIT_MODE_2_LINE                  0x38
#define _LCD_4BIT_MODE_2_LINE                  0x28

#define _LCD_CGRAM_START                       0x40
#define _LCD_DDRAM_START                       0x80

#define ROW1     1
#define ROW2     2
#define ROW3     3
#define ROW4     4

/* Section: Macro Functions Declarations */


/* Section: Function Declarations */
void LCD_Init();
void LCD_Send_Command(uint8 u8Command);
void LCD_Send_Data(uint8 u8Data);
void LCD_Send_Number(int32_t Copy_s32Num);
void LCD_Write_String(const uint8 *ptr);
void LCD_Set_Cursor(uint8 raw , uint8 column);
void LCD_Write_String_Position(const uint8 *ptr , uint8 ROW , uint8 COL);



void LCD_4Bit_Init(void);
void LCD_4Bit_Send_Command(uint8 u8Command);
void LCD_4Bit_Send_Data(uint8 u8Data);
void LCD_4Bit_Send_Number(int32_t Copy_s32Num);
void LCD_4Bit_Write_String(const uint8 *ptr);
void LCD_4Bit_Set_Cursor( uint8 ROW , uint8 COL );
void LCD_4Bit_Write_String_Position(const uint8 *ptr , uint8 ROW , uint8 COL);


//void LCD_Custom_string();




#endif /* LCD_INTERFACE_H_ */


/*from Data Sheet
 *
 *
 *@Function Set
 * (0 0 1 DL  N F - -)
 * DL: 4/8 bit mode
 * N: 1/2 Line mode
 * F: DotMatrix"5*8/11
 *
 *@Display ON/OFF
 * (0 0 0 0  1 D C B)
 * D: Display
 * C: Cursor
 * B: Blink
*/
