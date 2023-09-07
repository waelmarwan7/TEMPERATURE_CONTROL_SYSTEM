/*
 * MAIN.C


 *
 *  Created on: Aug 13, 2023
 *      Author: MARWAN WAEL
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/KPD/KPD.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/ADC/ADC.h"
#include "util/delay.h"

#define F_CPU 8000000UL
#define SENSOR_GAIN  150/307.2



u8 SETUP_config (void);
void SIGNAL_COND_CIRCUIT (u16*AT,u16*CB);
void print_INT_output(u16 num);

void main (void)
{
	u16 Actual_Temperature;
	u16 CONVERTED_BITS;


/* the initialization of needed prepherals....*/
	LCD_Voidinit();
	KEYPAD_VoidInit();
	SPI_VoidInit();
	ADC_voidInit();



	u8 Optimum_Temperature= SETUP_config();

	 DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_LOW);// SELECT SLAVE
    u8 GARBAGE_VALUE=SPI_transceive(Optimum_Temperature);
    DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH); // DESELECT SLAVE









	while(1)
		{
		     CONVERTED_BITS= ADC_u8GetChannelReading(ADC_CHANNEL0);

		     SIGNAL_COND_CIRCUIT(&Actual_Temperature,&CONVERTED_BITS);


		     DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_LOW); // SELECT SLAVE
		     GARBAGE_VALUE= SPI_transceive((u8)Actual_Temperature);
		     DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH); // DESELECT SLAVE


		     print_INT_output(Actual_Temperature);

		}
}

/**
 * starting setup configuration of lcd to choose best temperature for your system ..
 * @return optimum temperature that sends to sleive to configure the hysteresis levels...
 */
u8 SETUP_config (void)
{
	LCD_voidSendData("WELCOME...");
	_delay_ms(1000);
	LCD_VoidSendCommand(CLEAR);
	LCD_voidSendData("Setup Config..");
	_delay_ms(1000);
	LCD_VoidSendCommand(CLEAR);
	LCD_voidSendData("Enter Optimum...");
	LCD_VoidSendCommand(second_row);
	LCD_voidSendData("Temperature:");
	u8 TENS_DIGIT= KEYPAD_U8GetPressedKey();
	LCD_VoidSendChar(TENS_DIGIT);
	u8 UNITS_DIGIT= KEYPAD_U8GetPressedKey();
	LCD_VoidSendChar(UNITS_DIGIT);
	LCD_VoidSendChar('C');
	_delay_ms(1000);
	LCD_VoidSendCommand(CLEAR);

	// MODIFY THE TEMPERATURE NUMBER...
	TENS_DIGIT-=48;
	TENS_DIGIT*=10;

	UNITS_DIGIT-=48;

	return TENS_DIGIT+UNITS_DIGIT; // temperature number ....


}

/**
 * signal conditioning circuit for temperature sensor...
 * @param AT address of actual temperature that modified..
 * @param CB address of converted bits that used in equation ..
 */
void SIGNAL_COND_CIRCUIT (u16*AT,u16*CB)
{


    (*AT) = (*CB) * SENSOR_GAIN ;
    /* there is no need for approximation  because of the suitable gain but for confirmation of accuracy ...*/
    if(((*AT)*10)%10 != 0)
    {

   	   (*AT)++;
    }


}


/**
 * Print the Temperature digital value on LCD
 * @param num Number that wants to show on LCD
 */
void print_INT_output(u16 num){
  u16 remaining;
  remaining = num/10;

  LCD_voidSendData("Temperature is :");
  LCD_VoidSendCommand(second_row);
  LCD_VoidSendChar((remaining/10) + 48);
  LCD_VoidSendChar((remaining%10) + 48);
  LCD_VoidSendChar((num%10) + 48);
  LCD_VoidSendChar('C');
  _delay_ms(1000);
  LCD_VoidSendCommand(CLEAR);

}

