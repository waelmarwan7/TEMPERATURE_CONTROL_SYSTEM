/*
 * KBD.h
 *
 *  Created on: Aug 15, 2023
 *      Author: user
 */

#ifndef HAL_KPD_KPD_H_
#define HAL_KPD_KPD_H_

#include "../../LIB/STD_TYPES.h"


// DEFINE KPD PORT
#define KEYPAD_PORT     DIO_PORTD

// DEFINE ROW PINS
#define KEYPAD_R0_PIN   DIO_PIN0
#define KEYPAD_R1_PIN   DIO_PIN1
#define KEYPAD_R2_PIN   DIO_PIN2
#define KEYPAD_R3_PIN   DIO_PIN3

// DEFINE CLOUMN PINS
#define KEYPAD_C0_PIN   DIO_PIN4
#define KEYPAD_C1_PIN   DIO_PIN5
#define KEYPAD_C2_PIN   DIO_PIN6
#define KEYPAD_C3_PIN   DIO_PIN7


#define KEYPAD_PRESSED_KEY  DIO_LOW
#define KEYPAD_NOT_PRESSED_KEY  0XFF


#define ROWS_NUMBER  4
#define COLUMN_NUMBER  4


#define KEYPAD_VALUES  { {'7','8','9','/'},\
						 {'4','5','6','*'},\
						 {'1','2','3','-'},\
						 {'C','0','=','+'}}



// KEYPAD FUNCTIONS ....
void KEYPAD_VoidInit(void);
u8 KEYPAD_U8GetPressedKey(void);


#endif /* HAL_KPD_KPD_H_ */
