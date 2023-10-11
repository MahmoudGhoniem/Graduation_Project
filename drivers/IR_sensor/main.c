/***************************************************
 *  Module : main.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/


#include "ir_sensor.h"



int main(void)
{


	IRSensor_init ();

	GPIO_setupPinDirection(PORTC_ID , PIN0_ID ,PIN_OUTPUT);
	GPIO_writePin(PORTC_ID  , PIN0_ID ,LOGIC_LOW);

	while(1)
	{
	if(IR_Read() == 1)
	{
		GPIO_writePin(PORTC_ID  , PIN0_ID ,LOGIC_HIGH);
	}
	else
	{
		GPIO_writePin(PORTC_ID  , PIN0_ID ,LOGIC_LOW);
	}

	}


}
