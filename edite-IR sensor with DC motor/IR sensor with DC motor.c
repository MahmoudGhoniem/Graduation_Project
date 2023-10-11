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
	DDRC=0XFF;
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
		DDRD |= (1<<PD5);	/* Make OC1A pin as output */
		TCNT1 = 0;		/* Set timer1 count zero */
		ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

		/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
		TCCR1A = (1<<WGM11)|(1<<COM1A1);
		TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	while(1)
	{			
		if(DIO_u8read('B',3)==0 || DIO_u8read('B',4)==0 )//there is obstacle and go forward
		
			{
				CLR_BIT(PORTD,1);
				CLR_BIT(PORTC,0);
				SET_BIT(PORTD,0);
				SET_BIT(PORTD,4);
				while(DIO_u8read('B',3)==0 || DIO_u8read('B',4)==0 );
				
			}		
		else//No obstacles and  stop
		{
			CLR_BIT(PORTD,0);
			CLR_BIT(PORTD,4);
			CLR_BIT(PORTD,1);
			CLR_BIT(PORTC,0);
			_delay_ms(10000);
			//OCR1A = 156;	/* Set servo shaft at -30° position */
			//_delay_ms(2000);
			//OCR1A = 188;	/* Set servo shaft at 0° position */
			//_delay_ms(2000);
			//OCR1A = 219;	/* Set servo shaft at 30 position */
			OCR1A = 215;	/* Set servo shaft at 45 position */
			_delay_ms(200);
			//go back with angle 45 
			CLR_BIT(PORTD,0);
			CLR_BIT(PORTD,4);
			SET_BIT(PORTD,1);
			SET_BIT(PORTC,0);
			_delay_ms(5000);
			
			OCR1A = 188;	/* Set servo shaft at 0° position */
			_delay_ms(2000);
			//stop
			CLR_BIT(PORTD,0);
			CLR_BIT(PORTD,4);
			CLR_BIT(PORTD,1);
			CLR_BIT(PORTC,0);
			while(DIO_u8read('B',3)==1 && DIO_u8read('B',4)==1 ); ///// stay stop 
			
		}
			}
							
			}		
		


	
