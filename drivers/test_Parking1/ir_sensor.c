/***************************************************
 *  Module : ir_sensor.c
 *
 *  Details: IR_sensor for ditict obstacle object
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/
#include "ir_sensor.h"
#include <avr/io.h>

/*initiate IR_sensor*/
void IRSensor_init (void)
{

	GPIO_setupPinDirection(IRSensorPORT_ID  , IRSensorPin1_ID ,PIN_INPUT);  /*set sensor out as input to mcu*/
	GPIO_writePin(IRSensorPORT_ID ,IRSensorPin1_ID,LOGIC_HIGH);         		/*activate pull up resistor*/
	GPIO_setupPinDirection(IRSensorPORT_ID  , IRSensorPin2_ID ,PIN_INPUT);  /*set sensor out as input to mcu*/
	GPIO_writePin(IRSensorPORT_ID ,IRSensorPin2_ID,LOGIC_HIGH);         		/*activate pull up resistor*/


}

/*read value of sensor*/
uint8 IR_Read1(void)
{

	if((IRSensorPPin  ) & (1<< IRSensorPin1_ID ) )
	{
		return LOGIC_HIGH ;
	}
	else
	{

		return LOGIC_LOW;

	}
}
	uint8 IR_Read2(void)
	{

		if((IRSensorPPin  ) & (1<< IRSensorPin2_ID ) )
		{
			return LOGIC_HIGH ;
		}
		else
		{

			return LOGIC_LOW;

		}



	}
