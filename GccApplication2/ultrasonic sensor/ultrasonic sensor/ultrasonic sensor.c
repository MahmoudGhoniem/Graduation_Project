#include <avr/io.h>
#include "LCD.h"
#define  F_CPU 1000000UL
#include <util/delay.h>
#include "std_macros.h"
int main(void)
{
	LCD_vInit();
	unsigned short a,b,high,distance;
	DIO_vsetPINDir('D',7,1);
	DIO_vsetPINDir('D',0,1);
	DIO_vsetPINDir('D',1,1);
    DIO_vsetPINDir('D',4,1);
	 DIO_vsetPINDir('D',3,1);
	  DIO_vsetPINDir('D',2,1);
	
	DDRC=0XFF;
	PORTC=0;
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
    while(1)
	
    {	
		TCCR1A = 0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
		DIO_write('D',7,1);
		_delay_us(50);
		DIO_write('D',7,0);
	
	    TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	    while ((TIFR&(1<<ICF1)) == 0);
	    a = ICR1;  		/* Take value of capture register */
	    TIFR = (1<<ICF1);  	/* Clear ICF flag */
	    TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	    while ((TIFR&(1<<ICF1)) == 0);
	    b = ICR1;  		/* Take value of capture register */
	    TIFR = (1<<ICF1);  	/* Clear ICF flag */
		TCNT1=0;
	    TCCR1B = 0;  		/* Stop the timer */
		high=b-a;
		distance=((high*34600)/(F_CPU*20)) ;
		if (distance>=25)
		{
			LCD_clearscreen();
			LCD_vSend_string("no object");
			_delay_ms(500);
			CLR_BIT(PORTD,0);
			CLR_BIT(PORTC,1);
			CLR_BIT(PORTD,1);
			CLR_BIT(PORTC,0);
			_delay_ms(1000);
		}
		else
		{
		LCD_clearscreen();
		LCD_vSend_string("distance=");
		LCD_vSend_char((distance/10)+48);
		LCD_vSend_char((distance%10)+48);
	    LCD_vSend_string("cm");
		_delay_ms(500);
		CLR_BIT(PORTD,1);
		CLR_BIT(PORTC,0);
		SET_BIT(PORTD,0);
		SET_BIT(PORTC,1);
		_delay_ms(1000);
		}		
	}
}

