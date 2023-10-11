/***************************************************
 *  Module : main.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/
#include "dc_motor.h"
#include "lcd.h"
#include "gpio.h"
#include "ultra_sonic.h"
#include <util/delay.h>



int main (void)
{

	LCD_init();
	DcMotor_Init();
	IRSensor_init();
	uint16 distance =0 ;
	LCD_displayString(" Distance=    cm");


	while (1)
	{
				Ultrasonic_init();
				distance =Ultrasonic_readDistance()/8;
				LCD_moveCursor(0,11);
				if(distance >= 100)
				{
					LCD_intgerToString(distance);
				}
				else
				{
					LCD_intgerToString(distance);
					/* In case the digital value is two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');

				}
				_delay_ms(200);

				if (distance >= 25)
				{

					if ( !(IR_Read1() && IR_Read2()) )
					{
						DcMotor_Rotate(CLOCKWISE);
						LCD_moveCursor(1,0);
						LCD_displayString("THERE IS OBSTACLE");
						_delay_ms(500);

					}

					else
					{
						DcMotor_Rotate(A_CLOCKWISE);
						LCD_moveCursor(1,0);
						LCD_displayString("   NO OBSTACLE    ");

						_delay_ms(500);

					}


				}

				else
				{
						DcMotor_Rotate(CLOCKWISE);
						LCD_moveCursor(1,0);
						LCD_displayString("    NO Width       ");

						_delay_ms(500);
				}



	}




}

