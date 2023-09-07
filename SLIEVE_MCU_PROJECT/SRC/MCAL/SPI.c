/*
 * SPI.c
 *
 *  Created on: Aug 26, 2023
 *      Author: abdoy
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../HEADERS/MCAL/DIO.h"
#include "../../HEADERS/MCAL/SPI.h"
#include "avr/io.h"


void SPI_InitMaster()
{
	//Enable Master
	SET_BIT(SPCR,MSTR);

	//CLK Prescaler
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPSR,SPI2X);

	//Enable SPI
	SET_BIT(SPCR,SPE);

}
void SPI_InitSlave()
{
   //SS : Pullup internally
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_INPUT);

	//MOSI
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_INPUT);

	//MISO
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);

	//SCK
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_INPUT);

	//Enable Slave
	CLR_BIT(SPCR,MSTR);

	//Enable SPI
	SET_BIT(SPCR,SPE);

}

u8 SPI_TransRecieve(u8 u8Data_Copy)
{
	//start send data
	SPDR=u8Data_Copy;
	//wait(bust wait)
	while(GET_BIT(SPSR, SPIF)==0);

	return SPDR;
}

