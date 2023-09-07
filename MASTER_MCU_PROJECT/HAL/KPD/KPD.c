/*
 * KBD.c
 *
 *  Created on: Aug 15, 2023
 *      Author: user
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "KPD.h"
#include "../../MCAL/DIO/DIO.h"
#include "avr/delay.h"


void KEYPAD_VoidInit(void)
{
	/*step1 configuring rows direction and pullup ressistor(internal)....	 */
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_R0_PIN,DIO_INPUT);
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_R1_PIN,DIO_INPUT);
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_R2_PIN,DIO_INPUT);
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_R3_PIN,DIO_INPUT);


	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_R0_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_R1_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_R2_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_R3_PIN,DIO_HIGH);


	/*STEP2 CONFIGURING COLUMNS DIRECTION AND INITIALING WITH HIGH...	 */
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_C0_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_C1_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_C2_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_C3_PIN,DIO_OUTPUT);


	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_C0_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_C1_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_C2_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_C3_PIN,DIO_HIGH);

}



u8 KEYPAD_U8GetPressedKey(void)
{


	u8 U8RowLOCAL=0;
	u8 U8ColumnLocal=0;

	u8 KPD_RowPinArr[ROWS_NUMBER]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 KPD_ColumnPinArr[COLUMN_NUMBER]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};

while(1)
{
     for(U8ColumnLocal=0;U8ColumnLocal<COLUMN_NUMBER;U8ColumnLocal++)
     {
 		//active one columne at time ---> low
 		DIO_SetPinValue( KEYPAD_PORT , KPD_ColumnPinArr[U8ColumnLocal] , DIO_LOW);

 		//scan R0 to R3
    	 for(U8RowLOCAL=0;U8RowLOCAL<ROWS_NUMBER;U8RowLOCAL++)
    	 {
    		 u8 u8PinValueLocal = DIO_GetPinValue(KEYPAD_PORT ,KPD_RowPinArr[U8RowLOCAL]);
    		 if(u8PinValueLocal==KEYPAD_PRESSED_KEY)
    		 {
    			 //delay to avoid bouncing
					_delay_ms(50);
					//reread switch pin
						while(u8PinValueLocal==KEYPAD_PRESSED_KEY){
							   u8PinValueLocal = DIO_GetPinValue(KEYPAD_PORT ,KPD_RowPinArr[U8RowLOCAL]);
						}
						u8 KPD_u8Value[ROWS_NUMBER][COLUMN_NUMBER]= KEYPAD_VALUES;
						return KPD_u8Value[U8RowLOCAL][U8ColumnLocal];
					}


    		 }
			   //deactivate column
			   DIO_SetPinValue(KEYPAD_PORT,KPD_ColumnPinArr[U8ColumnLocal],DIO_HIGH);


        }

 }
}








