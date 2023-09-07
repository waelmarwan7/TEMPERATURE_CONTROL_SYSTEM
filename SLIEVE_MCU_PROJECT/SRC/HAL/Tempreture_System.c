/*
 * Tempreture_System.c
 *
 *  Created on: Sep 5, 2023
 *      Author: abdoy
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "avr/io.h"
#include "../../HEADERS/MCAL/DIO.h"
#include "../../HEADERS/HAL/Tempreture_System.h"

u8 duty_Cycle= 50;

void Fast_PWN_Init_Cooler(void)
{
	//TCCR0=0xff;
	// set OC0 (Timer0)
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);

	TCCR0=0x00;
	// Fast PWM mode
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);

	// Clear OC0 on compare match, set OC0 at TOP
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);

	// (256 prescaling)
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

	//OCR0 = (duty_Cycle/100)*255; // dutyCycle

}
void Fast_PWN_Init_Heater(void)
{
	// set OC2 (Timer2)
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);

	// clear TCCR2
	TCCR2 = 0x00;

	//Fast PWM mode
	SET_BIT(TCCR2,WGM21);
	SET_BIT(TCCR2,WGM20);

	//  Clear OC2 on compare match, set OC2 at TOP
	SET_BIT(TCCR2,COM21);
	SET_BIT(TCCR2,COM20);

	// (256 prescaling)
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

	OCR2 = (duty_Cycle/100)*255; // dutyCycle

}

void Adjust_Duty_Cycle(u8 temperature,u8 optimum)
{

	DIO_SetPinValue(DIO_PORTD,DIO_PIN0,DIO_LOW);

	// Adjust the duty cycle based on temperature
	if (temperature < (optimum-5))
	{
		OCR0 = 0; // Turn off cooler
		OCR2 = 0; // Turn off heater
		// Turn on the heater
		//DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);//Enable heater

		DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_LOW);// Disable cooler

		Fast_PWN_Init_Heater();
	}

	else if (temperature >= (optimum+5) && temperature<(optimum+10)) // cooler only
	{
		OCR0 = 0; // Turn off cooler
		OCR2 = 0; // Turn off heater

		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);//  Disable HEATER

		DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_HIGH);// ENABLE cooler


		// Turn on the cooler
		Fast_PWN_Init_Cooler();

		/*  Calculate duty cycle based on the temperature range ()
		 *  turn on the cooler motor for temperatures between 25 and 55 degrees
		 *  (starting with a duty cycle of 50% plus 10% for every additional 5 degrees)
		 */
		duty_Cycle = 50 + ((temperature - (optimum-10)) / 5) * 10;

		// Ensure duty cycle stays within the valid range (0-100)
		if (duty_Cycle > 100)
		{
			duty_Cycle = 100;
		}

		OCR0 = (duty_Cycle / 100) * 255;

	}
	else if (temperature >= (optimum+10)) // THE DANGER AREA ....
	{
		OCR0 = 0; // Turn off cooler
		OCR2 = 0; // Turn off heater
		// Activate the warning LED


		LED_Blink();

		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);//DISABLE HEATER

		DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_HIGH);// ENABLE COOLER


		// Turn on the cooler
		Fast_PWN_Init_Cooler();

		/*  Calculate duty cycle based on the temperature range ()
		 *  turn on the cooler motor for temperatures between 25 and 55 degrees
		 *  (starting with a duty cycle of 50% plus 10% for every additional 5 degrees)
		 */
		duty_Cycle = 50 + ((temperature - (optimum-10)) / 5) * 10;

		// Ensure duty cycle stays within the valid range (0-100)
		if (duty_Cycle > 100)
		{
			duty_Cycle = 100;
		}

		OCR0 = (duty_Cycle / 100) * 255;

   }
	 else // the optimum area....
	{
		// Default case: Turn off both cooler and heater
		OCR0 = 0; // Turn off cooler
		OCR2 = 0; // Turn off heater
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);// Disable cooler

		DIO_SetPinValue(DIO_PORTA,DIO_PIN1,DIO_LOW);// Disable heater
	}

}

void LED_Blink (void)
{
	//portd pin0
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);

	DIO_SetPinValue(DIO_PORTD,DIO_PIN0,DIO_HIGH);

}
