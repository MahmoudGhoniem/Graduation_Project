/***************************************************
 *  Module : LCD.h
 *
 *  Created on: Oct 16, 2021
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"



#define LCD_DATA_BITS_MODE        8

#if((LCD_DATA_BITS_MODE != 4 )&&  (LCD_DATA_BITS_MODE != 8) )

#error ("Number of Data bits should be 4 or 8")
#endif

#if(LCD_DATA_BITS_MODE ==4)

#define LCD_LAST_PORT_PINS   /*default from Pin4 ----> Pin7 */

#ifdef LCD_LAST_PORT_PINS
#define LCD_FIRST_DATA_PIN_ID  PIN4_ID
#else
#define LCD_FIRST_DATA_PIN_ID  PIN0_ID
#endif

#endif







#define LCD_RS_PORT_ID                 PORTD_ID
#define LCD_RS_PIN_ID                  PIN4_ID

#define LCD_RW_PORT_ID                 PORTD_ID
#define LCD_RW_PIN_ID                  PIN5_ID

#define LCD_E_PORT_ID                  PORTD_ID
#define LCD_E_PIN_ID                   PIN6_ID

#define LCD_DATA_PORT_ID               PORTC_ID



#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80












void LCD_sendCommand(uint8 command);
void LCD_init(void);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(uint8 *str);
void LCD_moveCursor(uint8 row ,uint8 col);
void LCD_displayStringRowColumn(uint8 row ,uint8 col , const char *str);
void LCD_intgerToString(int data);
void LCD_clearScreen(void);


#endif /* LCD_H_ */
