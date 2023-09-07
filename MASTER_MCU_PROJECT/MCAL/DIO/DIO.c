/*
 * DIO.c
 *
 *  Created on: Aug 10, 2023
 *      Author: marwan wael
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "DIO.h"
#include  "avr/io.h"
#include  "util/delay.h"



void  DIO_SetPinValue (u8 U8PortIdcopy ,u8 U8PinIdCopy ,u8 U8PinValueCopy)
{
	if((U8PortIdcopy<=DIO_PORTD) && (U8PinIdCopy<=DIO_PIN7))
	{
		if(U8PinValueCopy == DIO_HIGH)
		{
			switch (U8PortIdcopy)
			{
				case DIO_PORTA : SET_BIT(PORTA,U8PinIdCopy); break;
				case DIO_PORTB : SET_BIT(PORTB,U8PinIdCopy); break;
				case DIO_PORTC : SET_BIT(PORTC,U8PinIdCopy); break;
				case DIO_PORTD : SET_BIT(PORTD,U8PinIdCopy); break;
			}
		}
		else if (U8PinValueCopy == DIO_LOW)
		{
			switch (U8PortIdcopy)
			{
				case DIO_PORTA : CLR_BIT(PORTA,U8PinIdCopy); break;
				case DIO_PORTB : CLR_BIT(PORTB,U8PinIdCopy); break;
				case DIO_PORTC : CLR_BIT(PORTC,U8PinIdCopy); break;
				case DIO_PORTD : CLR_BIT(PORTD,U8PinIdCopy); break;
			}
		}
		else
			printf("ERROR SELECT HIGH OR LOW VALUE.. ");

	}else
		printf("ERROR SELECTION PORTS FROM 0--3 AND PIN FROM 0--7..");

}



void  DIO_SetPinDirection (u8 U8PortIdcopy ,u8 U8PinIdCopy ,u8 U8PinDirCopy)
{
	if((U8PortIdcopy<=DIO_PORTD) && (U8PinIdCopy<=DIO_PIN7))
	{
		if(U8PinDirCopy == DIO_OUTPUT)
		{
			switch (U8PortIdcopy)
			{
			case DIO_PORTA : SET_BIT(DDRA,U8PinIdCopy); break;
			case DIO_PORTB : SET_BIT(DDRB,U8PinIdCopy); break;
			case DIO_PORTC : SET_BIT(DDRC,U8PinIdCopy); break;
			case DIO_PORTD : SET_BIT(DDRD,U8PinIdCopy); break;
			}
		}
		else if (U8PinDirCopy == DIO_INPUT)
		{
			switch (U8PortIdcopy)
			{
			case DIO_PORTA : CLR_BIT(DDRA,U8PinIdCopy); break;
			case DIO_PORTB : CLR_BIT(DDRB,U8PinIdCopy); break;
			case DIO_PORTC : CLR_BIT(DDRC,U8PinIdCopy); break;
			case DIO_PORTD : CLR_BIT(DDRD,U8PinIdCopy); break;
			}
		}else
			printf("ERROR SELECT OUTPUT OR INPUT VALUE.. ");

	}else
		printf("ERROR SELECTION PORTS FROM 0--3 AND PIN FROM 0--7..");
}


u8    DIO_GetPinValue  (u8 U8PortIdCopy , u8 U8PinIdCopy)
{
	if((U8PortIdCopy<=DIO_PORTD) && (U8PinIdCopy<=DIO_PIN7))
	{
		u8 PinValue=0;

			switch (U8PortIdCopy)
			{
				case DIO_PORTA : PinValue= GET_BIT(PINA,U8PinIdCopy); break;
				case DIO_PORTB : PinValue= GET_BIT(PINB,U8PinIdCopy); break;
				case DIO_PORTC : PinValue= GET_BIT(PINC,U8PinIdCopy); break;
				case DIO_PORTD : PinValue= GET_BIT(PIND,U8PinIdCopy); break;
			}
		return PinValue;

	}else
	{
	}
	return 0;
}


void  DIO_SetPortValue (u8 U8PortIdcopy ,u8 U8PinValueCopy)
{
	if(U8PortIdcopy<=DIO_PORTD)
	{

			switch (U8PortIdcopy)
			{
				case DIO_PORTA : SET_PORT(PORTA,U8PinValueCopy); break;
				case DIO_PORTB : SET_PORT(PORTB,U8PinValueCopy); break;
				case DIO_PORTC : SET_PORT(PORTC,U8PinValueCopy); break;
				case DIO_PORTD : SET_PORT(PORTD,U8PinValueCopy); break;
			}



	}else
		printf("ERROR SELECTION PORTS FROM 0--3...");


}
void  DIO_SetPortDirection (u8 U8PortIdcopy ,u8 U8PinDirCopy)
{
	if(U8PortIdcopy<=DIO_PORTD)
	{

			switch (U8PortIdcopy)
			{
			case DIO_PORTA : SET_PORT(DDRA,0XFF); break;
			case DIO_PORTB : SET_PORT(DDRB,0XFF); break;
			case DIO_PORTC : SET_PORT(DDRC,0XFF); break;
			case DIO_PORTD : SET_PORT(DDRD,0XFF); break;
			}


	}else
		printf("ERROR SELECTION PORTS FROM 0--3....");

}
