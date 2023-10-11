/***************************************************
 *  Module : lcd.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/


#include <util/delay.h>
#include "lcd.h"

#include "common_macros.h"
#include "gpio.h"
/**************************************************************************
 * ***********      Functions Definitions         ************************/
/* Description:
 * initialization function
 * set RS , RW , E and data port as output pins
 * */
void LCD_init(void){
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_RW_PORT_ID, LCD_RW_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);
#if (LCD_DATA_BITS_MODE == 4)

	/* Configure 4 pins in the data port as output pins */
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID+1,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID+2,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID+3,PIN_OUTPUT);

	LCD_sendCommand(LCD_GO_TO_HOME);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */

#elif (LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
#endif	  /* 2lines- 8bits data*/
	LCD_sendCommand(LCD_CURSOR_OFF);        /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND);        /* clear the screen*/


}

/* Description:
 * this function used to send a command
 * */
void LCD_sendCommand(uint8 command){
	uint8 lcd_port_value = 0;
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW); /* RS = 0 */
	GPIO_writePin(LCD_RW_PORT_ID, LCD_RW_PIN_ID, LOGIC_LOW); /* R/W = 0*/
	_delay_ms(1);                                            /* for tas = 50ns*/
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);  /* Data enable E=0 */
	_delay_ms(1);                                            /* for tpw - tdsw = 19ns */

#if (LCD_DATA_BITS_MODE == 4)
	/* out the last 4 bits of the required command to the data bus D4 --> D7 */
	lcd_port_value = GPIO_readPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | (command & 0xF0);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | ((command & 0xF0) >> 4);
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);  /* send commend */
	_delay_ms(1);   /* tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(1);  /*  th = 13ns */

	/*repeat for second nibble */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the first 4 bits of the required command to the data bus D4 --> D7 */
	lcd_port_value = GPIO_readPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | ((command & 0x0F) << 4);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | (command & 0x0F);
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif (LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif


}

/* Description:
 * this function used to send a data
 * */
void LCD_displayCharacter(uint8 data){
	uint8 lcd_port_value = 0;
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH); /* RS = 1 */
	GPIO_writePin(LCD_RW_PORT_ID, LCD_RW_PIN_ID, LOGIC_LOW); /* R/W = 0*/
	_delay_ms(1);                                            /* for tas = 50ns*/
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);  /* Data enable E=0 */
	_delay_ms(1);                                            /* for tpw - tdsw = 19ns */

#if (LCD_DATA_BITS_MODE == 4)
	/* out the last 4 bits of the required command to the data bus D4 --> D7 */
	lcd_port_value = GPIO_readPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | (data & 0xF0);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | ((data & 0xF0) >> 4);
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);  /* send data */
	_delay_ms(1);   /* tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(1);  /*  th = 13ns */

	/*repeat for second nibble */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	lcd_port_value = GPIO_readPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | ((data & 0x0F) << 4);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | (data & 0x0F);
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif (LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,data);
	_delay_ms(1);                                          /* delay for  Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);   /* Disable LCD E=0 */
	_delay_ms(1);                                          /* delay for Th = 13ns */
#endif


}

/* Description:
 * this function used to move the cursor to specific row and column
 * */
void LCD_moveCursor(uint8 row , uint8 column){
	uint8 address;

	switch(row)
	{
	case 0 :
		address= column ;
		break;
	case 1 :
		address= 0x40 + column ;
		break;
	case 2 :
		address= 0x10 + column ;
		break;
	case 3 :
		address= 0x50 + column ;
		break;
	}
	LCD_sendCommand(LCD_SET_CURSOR_LOCATION | address);

}

/* Description:
 * this function used to clear the  of LCD
 * */
void LCD_clearScreen(void){
	LCD_sendCommand(LCD_CLEAR_COMMAND);        /* clear the screen*/

}

/*Description
 * this function used to display a string on the screen of the LCD
 * */
void LCD_displayString(const char *str){
	uint8 i = 0 ;
	while(str[i] != '\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}

/*
 * Description :
 * Display the string in the required position on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str){

	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}
/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data)
{
	char buffer[16]; /* String to hold the ascii result */
	itoa(data,buffer,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buffer); /* Display the string */
}
