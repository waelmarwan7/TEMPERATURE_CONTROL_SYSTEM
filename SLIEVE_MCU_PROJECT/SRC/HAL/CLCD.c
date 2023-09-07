
#include "../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "../../HEADERS/MCAL/DIO.h"
#include "../../HEADERS/HAL/CLCD.h"
#include "util/delay.h"

void CLCD_voidSendCommand (u8 u8CommandCopy)
{
	//step 1
	//RS=0
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_LOW);
	//RW=0
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);
	//step 2
	DIO_SetPortValue(CLCD_DATA_PORT, u8CommandCopy);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);

	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}
void CLCD_voidSendData (u8 u8DataCopy)
{


	//step 1
	//RS=1
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_HIGH);
	//RW=0
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);
	//step 2
	DIO_SetPortValue(CLCD_DATA_PORT, u8DataCopy);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);

	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}
void CLCD_voidInit(void)
{
	//////Initialize DIO/////
	DIO_SetPortDirection(CLCD_DATA_PORT,0xFF);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_OUTPUT);
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001110);
	CLCD_voidSendCommand(0b00000001);


}
