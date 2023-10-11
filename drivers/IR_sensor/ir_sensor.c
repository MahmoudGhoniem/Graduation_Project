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

	GPIO_setupPinDirection(IRSensorPORT_ID  , IRSensorPin_ID ,PIN_INPUT);  /*set sensor out as input to mcu*/
	GPIO_writePin(IRSensorPORT_ID ,IRSensorPin_ID,LOGIC_HIGH);         		/*activate pull up resistor*/

}

/*read value of sensor*/
uint8 IR_Read(void)
{

	if((IRSensorPPin  ) & (1<< IRSensorPin_ID ) )
	{
		return LOGIC_HIGH ;
	}
	else
	{

		return LOGIC_LOW;

	}


}
