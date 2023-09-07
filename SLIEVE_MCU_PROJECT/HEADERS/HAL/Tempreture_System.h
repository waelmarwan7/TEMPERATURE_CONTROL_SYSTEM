/*
 * Tempreture_System.h
 *
 *  Created on: Sep 5, 2023
 *      Author: abdoy
 */

#ifndef TEMPRETURE_SYSTEM_H_
#define TEMPRETURE_SYSTEM_H_
//#define temperature 25


/*Functions*/
void Fast_PWN_Init_Cooler(void);
void Fast_PWN_Init_Heater(void);
void Adjust_Duty_Cycle(u8 temperature,u8 optimum);
u8 Toggle_Pin( u8 *port, u8 pin);
void LED_Blink (void);
#endif /* TEMPRETURE_SYSTEM_H_ */
