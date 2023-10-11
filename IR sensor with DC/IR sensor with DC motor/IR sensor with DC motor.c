/*
 * IR_sensor_with_DC_motor.c
 *
 * Created: 02-Jan-22 9:40:32 PM
 *  Author: IbrahimElmekawy
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "altrasonic.h"
#include "std_macros.h"
#define F_CPU 1000000UL
#include <util/delay.h>
int main(void)
{
	DDRD=0XFF;
	DDRB=0;
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
	LCD_vInit();

	unsigned short z ;
	while(1)
	{
		 altrasonic_init();
		 z =altrasonic_read()/8 ;
		 LCD_clearscreen();
		 LCD_vSend_string("distance=");
		 LCD_vSend_char((z/10)+48);
		 LCD_vSend_char((z%10)+48);
		 LCD_vSend_string("cm");
		 _delay_ms(5000);;
		
		
		if (z >= 25)
		{
			
		
		if(DIO_u8read('B',3)==0 || DIO_u8read('B',4)==0 )//there is obstacle
		
			{
				CLR_BIT(PORTD,1);
				CLR_BIT(PORTD,5);
				SET_BIT(PORTD,0);
				SET_BIT(PORTD,4);
				LCD_clearscreen();
				LCD_vSend_string("there is");
				LCD_movecursor(2,1);
				LCD_vSend_string("obstacle");
				_delay_ms(500);
				
			}		
		else//No obstacles
		{
			CLR_BIT(PORTD,0);
			CLR_BIT(PORTD,4);
			SET_BIT(PORTD,1);
			SET_BIT(PORTD,5);
			LCD_clearscreen();
			LCD_vSend_string("No obstacles");
			_delay_ms(500);
		}
			}
			else 
			{
				LCD_clearscreen();
				LCD_vSend_string("No distance");
				_delay_ms(500);
			}				
			}		
		

}
	
