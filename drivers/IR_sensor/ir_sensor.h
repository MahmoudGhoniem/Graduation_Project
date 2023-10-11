/***************************************************
 *  Module : ir_sensor.h
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_


#include "std_types.h"
#include "gpio.h"
#include "common_macros.h"


#define IRSensorPORT_ID      PORTA_ID
#define IRSensorPin_ID       PIN0_ID
#define IRSensorPPin         PINA


void IRSensor_init (void);
uint8 IR_Read(void);

#endif /* IR_SENSOR_H_ */
