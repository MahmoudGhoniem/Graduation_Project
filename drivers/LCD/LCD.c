/***************************************************
 *  Module : LCD.c
 *
 *  Created on: Oct 16, 2021
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#include "gpio.h"
#include <util/delay.h>
#include "common_macros.h"
#include "LCD.h"

void LCD_init(void)
{

	GPIO_setupPinDirection(LCD_RS_PORT_ID  ,LCD_RS_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_RW_PORT_ID  ,LCD_RW_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID  ,LCD_E_PIN_ID,PIN_OUTPUT);

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_setupPinDirection(LCD_DATA_PORT_ID  ,LCD_FIRST_DATA_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID  ,LCD_FIRST_DATA_PIN_ID+1,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID  ,LCD_FIRST_DATA_PIN_ID+2,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID  ,LCD_FIRST_DATA_PIN_ID+3,PIN_OUTPUT);

	LCD_sendCommand(LCD_GO_TO_HOME);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);



#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_setupPortDirection(LCD_DATA_PORT_ID ,PORT_OUTPUT);
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
#endif

	LCD_sendCommand(LCD_CURSOR_OFF );
	LCD_sendCommand(LCD_CLEAR_COMMAND );


}


void LCD_sendCommand(uint8 command)
{

	GPIO_writePin(LCD_RS_PORT_ID  ,LCD_RS_PIN_ID,LOGIC_LOW);
	GPIO_writePin(LCD_RW_PORT_ID ,LCD_RW_PIN_ID ,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin( LCD_E_PORT_ID ,LCD_E_PIN_ID ,LOGIC_HIGH);
	_delay_ms(1);

#if(LCD_DATA_BITS_MODE == 4)
	uint8 lcd_port_value = 0;
	lcd_port_value=GPIO_readPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value=(lcd_port_value & 0x0F) | (command & 0xF0 );
#else
	lcd_port_value=(lcd_port_value & 0xF0) | ((command & 0xF0)>>4) ;
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);




	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);

	lcd_port_value=GPIO_readPort(LCD_DATA_PORT_ID);

#ifdef LCD_LAST_PORT_PINS
	lcd_port_value=(lcd_port_value & 0x0F) | ((command & 0x0F )<<4);
#else
	lcd_port_value=(lcd_port_value & 0xF0) | (command & 0x0F) ;
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);


#elif(LCD_DATA_BITS_MODE == 8)

	GPIO_writePort(LCD_DATA_PORT_ID ,command);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);

#endif




}


void LCD_displayCharacter(uint8 data)
{

	GPIO_writePin(LCD_RS_PORT_ID  ,LCD_RS_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(LCD_RW_PORT_ID ,LCD_RW_PIN_ID ,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin( LCD_E_PORT_ID ,LCD_E_PIN_ID ,LOGIC_HIGH);
	_delay_ms(1);

#if(LCD_DATA_BITS_MODE == 4)
	uint8 lcd_port_value =0 ;
	lcd_port_value=GPIO_readPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value=(lcd_port_value & 0x0F) | (data & 0xF0 );
#else
	lcd_port_value=(lcd_port_value & 0xF0) | ((data & 0xF0)>>4) ;
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);




	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);

	lcd_port_value=GPIO_readPort(LCD_DATA_PORT_ID);

#ifdef LCD_LAST_PORT_PINS
	lcd_port_value=(lcd_port_value & 0x0F) | ((data & 0x0F )<<4);
#else
	lcd_port_value=(lcd_port_value & 0xF0) | (data & 0x0F) ;
#endif
	GPIO_writePort(LCD_DATA_PORT_ID,lcd_port_value);

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);


#elif(LCD_DATA_BITS_MODE == 8)

	GPIO_writePort(LCD_DATA_PORT_ID ,data);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);

#endif


}


void LCD_displayString(uint8 *str)
{

	uint8 i =0;

	while(str[i]!= '\0')
	{

		LCD_displayCharacter(str[i]);
		i++ ;
	}


}
void LCD_moveCursor(uint8 row ,uint8 col)
{
	uint8 lcd_memory_adress ;

	switch(row)
	{
	case 0 :
		lcd_memory_adress=col ;
		break;
	case  1:
		lcd_memory_adress=col+0x40 ;
		break;
	case 2 :
		lcd_memory_adress=col+0x10 ;
		break;
	case 3 :
		lcd_memory_adress=col+0x50 ;
		break;


	}

	LCD_sendCommand(lcd_memory_adress |LCD_SET_CURSOR_LOCATION);


}

void LCD_displayStringRowColumn(uint8 row ,uint8 col , const char *str)
{

	LCD_moveCursor( row , col);
	LCD_displayString(str);


}

void LCD_intgerToString(int data)
{

	char buff[16];

	itoa(data,buff,10);

	LCD_displayString(buff);



}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND );
}






