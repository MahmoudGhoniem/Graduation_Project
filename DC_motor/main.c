/***************************************************
 *  Module : main.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/
#include "dc_motor.h"
#include <util/delay.h>

int main (void)
{

	 DcMotor_Init();

	 while (1)
	 {
		 DcMotor_Rotate(CLOCKWISE);
		 _delay_ms(5000);
		 DcMotor_Rotate(A_CLOCKWISE);
		 _delay_ms(5000);
		 DcMotor_Rotate(STOP);
		 _delay_ms(5000);



	 }




}
