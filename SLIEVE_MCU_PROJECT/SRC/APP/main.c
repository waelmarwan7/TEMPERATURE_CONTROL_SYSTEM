/*
 * main.c
 *
 *  Created on: Sep 5, 2023
 *      Author: abdoy
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../HEADERS/MCAL/DIO.h"
#include "../../HEADERS/HAL/Tempreture_System.h"
#include "avr/io.h"

void main (void)
{

	SPI_InitSlave();

	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);

	DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);// Disable cooler
	DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_LOW);// Disable heater



	while (((SPSR >> SPIF) & 1) == 0); // interrupt flag => data received
	u8 optimum_temperature=SPDR;

	while(1)
	{
		while (((SPSR >> SPIF) & 1) == 0); // interrupt flag => data received
		u8 ACTUAL_TEMPERATURE=SPDR;


		Adjust_Duty_Cycle(ACTUAL_TEMPERATURE,optimum_temperature);
	}
}
