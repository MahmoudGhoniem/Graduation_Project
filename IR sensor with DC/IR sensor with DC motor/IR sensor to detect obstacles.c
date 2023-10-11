
#include <avr/io.h>
#include "LCD.h"
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	DDRD=0XFF;
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
	LCD_vInit();
    while(1)
    {
		if(DIO_u8read('B',3)==1)
		{
			CLR_BIT(PORTD,1);
			CLR_BIT(PORTD,5);
			SET_BIT(PORTD,0);
			SET_BIT(PORTD,4);
			LCD_clearscreen();
			LCD_vSend_string("there is");
			LCD_movecursor(2,1);
			LCD_vSend_string("obstacle");
			
		}
		else
		{
			CLR_BIT(PORTD,0);
			CLR_BIT(PORTD,4);
			SET_BIT(PORTD,1);
			SET_BIT(PORTD,5);
			LCD_clearscreen();
			LCD_vSend_string("No obstacles");
		}
		_delay_ms(500);
    }
}

