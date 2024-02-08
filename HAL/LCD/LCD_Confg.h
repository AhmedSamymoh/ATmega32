/*
 * LCD_Confg.h
 *
 *  Created on: Sep 9, 2023
 *      Author: AhmedSamy
 */

#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

/**********************************************************
 * The LCD in 8 bit Configuration
 *********************************************************/
#define LCD_DATA_PORT 		PORT_C
#define LCD_CONTROL_PORT  	PORT_D

#define LCD_RS_PIN	 		PIN_3
#define LCD_RW_PIN 			PIN_1
#define LCD_EN_PIN			PIN_0

/**********************************************************
 * The LCD in 4 bit Configuration
 *********************************************************/
#define LCD_4bit_PORT  		PORT_A

#define LCD_4bit_D7			PIN_1
#define LCD_4bit_D6			PIN_2
#define LCD_4bit_D5			PIN_3
#define LCD_4bit_D4			PIN_4

#define LCD_4bit_EN			PIN_5
#define LCD_4bit_RW 		PIN_6
#define LCD_4bit_RS	 		PIN_7




#endif /* LCD_CONFG_H_ */
