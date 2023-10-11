/***************************************************
 *  Module : gpio.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/


#include "gpio.h"
#include <avr/io.h>            /* to use i/o register */
#include "common_macros.h"


/******************************************************************************
 *****************           function definition        **********************/

/* Description :
 * this function used to setup the direction of the required pin
 * if the pin or port number is not correct, the function will do nothing
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction){

	if((port_num >= NUM_OF_PORTS)||(pin_num >= NUM_OF_PINS_PER_PORT)){
		/*do nothing because the pin number or the port number is not correct */
	}
	else
	{
		/*setup pin direction*/
		switch(port_num){
		case PORTA_ID :
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break ;
		case PORTB_ID :
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break ;
		case PORTC_ID :
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break ;
		case PORTD_ID :
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break ;
		}

	}

}



/* Description :
 * this function is used to write value to the required pin
 * write the value logic high or low
 * if this pin is input , this function will enable/disable the internal pull-up resistor
 * if the pin or port number is not correct, the function will do nothing
 * */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value){

	if((port_num >= NUM_OF_PORTS)||(pin_num >= NUM_OF_PINS_PER_PORT)){
		/*do nothing because the pin number or the port number is not correct */
	}
	else
	{
		/* write value in the required pin */
		switch(port_num)
		{
		case PORTA_ID :
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break ;
		case PORTB_ID :
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break ;
		case PORTC_ID :
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break ;
		case PORTD_ID :
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break ;

		}

	}

}
/* Description :
 * this function used to setup the direction of the required port
 * if the port number is not correct, the function will do nothing
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num){

	uint8 returned_value= LOGIC_LOW;

	if((port_num >= NUM_OF_PORTS)||(pin_num >= NUM_OF_PINS_PER_PORT)){
		/*do nothing because the pin number or the port number is not correct */
	}
	else{
		/* read value from the required pin */
		switch(port_num){
		case PORTA_ID :
			if (BIT_IS_SET(PINA,pin_num))
			{
				returned_value= LOGIC_HIGH;
			}
			else
			{
				returned_value= LOGIC_LOW;
			}
			break ;
		case PORTB_ID :
			if (BIT_IS_SET(PINB,pin_num))
			{
				returned_value= LOGIC_HIGH;
			}
			else
			{
				returned_value= LOGIC_LOW;
			}
			break ;
		case PORTC_ID :
			if (BIT_IS_SET(PINC,pin_num))
			{
				returned_value= LOGIC_HIGH;
			}
			else
			{
				returned_value= LOGIC_LOW;
			}
			break ;
		case PORTD_ID :
			if (BIT_IS_SET(PIND,pin_num))
			{
				returned_value= LOGIC_HIGH;
			}
			else
			{
				returned_value= LOGIC_LOW;
			}
			break ;
		}

	}
	return returned_value ;
}

/* Description :
 * this function used to setup the direction of the required port
 * if the port number is not correct, the function will do nothing
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction){

	if(port_num >= NUM_OF_PORTS){
		/*do nothing because the pin number or the port number is not correct */
	}
	else
	{
		/*setup port direction*/
		switch(port_num){
		case PORTA_ID :
			DDRA= direction;
			break ;
		case PORTB_ID :
			DDRB= direction;
			break ;
		case PORTC_ID :
			DDRC= direction;
			break ;
		case PORTD_ID :
			DDRD= direction;
			break ;
		}

	}

}
/* Description :
 * this function used to write value of the required port
 * if this port is input , this function will enable/disable the internal pull-up resistor
 * if the port number is not correct, the function will do nothing
 */

void GPIO_writePort(uint8 port_num, uint8 value){
	if(port_num >= NUM_OF_PORTS){
		/*do nothing because the pin number or the port number is not correct */
	}
	else{
		/*write port direction*/
		switch(port_num){
		case PORTA_ID :
			PORTA = value;
			break ;
		case PORTB_ID :
			PORTB = value;
			break ;
		case PORTC_ID :
			PORTC = value;
			break ;
		case PORTD_ID :
			PORTD = value;
			break ;
		}

	}

}
/* Description :
 * this function used to read value of the required port
 * it return logic high or low
 * if this port is input , this function will enable/disable the internal pull-up resistor
 * if the port number is not correct, the function will do nothing
 */
uint8 GPIO_readPort(uint8 port_num){

	uint8 returned_value =LOGIC_LOW ;

	if(port_num >= NUM_OF_PORTS){
		/*do nothing because the pin number or the port number is not correct */
	}
	else{
		/*write port direction*/
		switch(port_num){
		case PORTA_ID :
			returned_value =PINA ;
			break ;
		case PORTB_ID :
			returned_value =PINB ;
			break ;
		case PORTC_ID :
			returned_value =PINC;
			break ;
		case PORTD_ID :
			returned_value =PIND ;
			break ;
		}

	}
	return returned_value;


}
