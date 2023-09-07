/***************************************/



/***************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"
#include "util/delay.h"






void LCD_VoidSendChar(u8 U8DataCopy)
{
	// DEFINE THE DIRECTIONS OF LCD PINS.....
	DIO_SetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,DIO_OUTPUT);


	//reset RS AND RW ...
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);

	// SEND COMMOND
	DIO_SetPortValue(LCD_DATA_PORT,U8DataCopy);

	// SET ENABLE AND WAIT FOR IMS THEN RESET IT ...
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(20);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);


}
void LCD_VoidSendCommand(u8 U8CommandCopy)
{
	// DEFINE THE DIRECTIONS OF LCD PINS.....
	DIO_SetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,DIO_OUTPUT);


	//reset RS AND RW ...
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);

	// SEND COMMOND
	DIO_SetPortValue(LCD_DATA_PORT,U8CommandCopy);

	// SET ENABLE AND WAIT FOR IMS THEN RESET IT ...
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(20);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);


}
void LCD_voidSendData(const char* Copy_pcString)
{     u8 Local_u8Counter=0;
      while  ( Copy_pcString[Local_u8Counter] != '\0' ){
    	  LCD_VoidSendChar(Copy_pcString[Local_u8Counter]);
    	  Local_u8Counter ++;
      }
}
void LCD_Voidinit(void)
{
	// DEFINE THE DIRECTIONS OF LCD PINS.....
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);


	//reset RS AND RW ...
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);

	_delay_ms(40);

	/*Function set command: 2 lines(N = 1), 5*8 Font size (F = 0 )*/
	LCD_VoidSendCommand(FUNCTION_SET);
	_delay_ms(1);
	/*Display on off control: display enable, disable cursor, no blink cursor*/
	LCD_VoidSendCommand(DISPLAY_SET);
	_delay_ms(1);
	/*Clear display*/
	LCD_VoidSendCommand(CLEAR);
	_delay_ms(1);

}


