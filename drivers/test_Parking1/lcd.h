/***************************************************
 *  Module : lcd.h
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"

/*************************************************************************
 * *********************       Definition         ************************/
/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE     8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#if (LCD_DATA_BITS_MODE == 4)

/* if LCD_LAST_PORT_PINS is defined in the code, the LCD driver will use the last 4 pins in the gpio port for for data.
 * To use the first four pins in the gpio port for data just remove LCD_LAST_PORT_PINS */
#define LCD_LAST_PORT_PINS

#ifdef LCD_LAST_PORT_PINS
#define LCD_FIRST_DATA_PIN_ID         PIN4_ID
#else
#define LCD_FIRST_DATA_PIN_ID         PIN0_ID
#endif

#endif

#define LCD_RS_PORT_ID                 PORTB_ID
#define LCD_RS_PIN_ID                  PIN0_ID

#define LCD_RW_PORT_ID                 PORTB_ID
#define LCD_RW_PIN_ID                  PIN1_ID

#define LCD_E_PORT_ID                  PORTB_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTA_ID            /*data bus port */

/*LCD command */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80    /*force cursor to beginning of the 1st line */

/*************************************************************************
 * *********************       function prototype      *******************/
/* Description:
 * initialization function
 * set RS , RW , E and data port as output pins
 * */
void LCD_init(void);

/* Description:
 * this function used to send a command
 * */
void LCD_sendCommand(uint8 command);

/* Description:
 * this function used to send a data
 * */
void LCD_displayCharacter(uint8 data);

/* Description:
 * this function used to move the cursor to specific row and column
 * */
void LCD_moveCursor(uint8 row , uint8 column);

/* Description:
 * this function used to clear the  of LCD
 * */
void LCD_clearScreen(void);

/*Description
 * this function used to display a string on the screen of the LCD
 * */
void LCD_displayString(const char *str);

/*
 * Description :
 * Display the string in the required position on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);



#endif /* LCD_H_ */
