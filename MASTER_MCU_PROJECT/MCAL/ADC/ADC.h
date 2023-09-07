/*
 * ADC.h
 *
 *  Created on: Aug 17, 2023
 *      Author: user
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

// ADMUX   :  ADC multiplexer selection register
#define ADMUX_REFS1          7                         //Reference selection bitl
#define ADMUX_REFS0          6                         //Reference selection bit0
#define ADMUX_ADLAR          5                         //ADC left adjust result
#define ADMUX_MUX4           4
#define ADMUX_MUX3           3
#define ADMUX_MUX2           2
#define ADMUX_MUX1           1
#define ADMUX_MUX0           0

//ADCSRA   :  ADC control and status register A
#define ADCSRA_ADEN          7                        //ADC enable
#define ADCSRA_ADSC          6                        //Start conversion
#define ADCSRA_ADATE         5                        //Auto trigger enable
#define ADCSRA_ADIF          4                        //Interrupt flag
#define ADCSRA_ADIE          3                        //Interrupt enable
#define ADCSRA_ADPS2         2                        //Prescaler bit2
#define ADCSRA_ADPS1         1                        //Prescaler bitl
#define ADCSRA_ADPS0         0                        //Prescaler bit0

// ADCH_Reg 	 ADC High Register
// ADCL_Reg      ADC Low Register

// CONFIG....
#define ADC_DISABLE             0
#define ADC_ENABLE              1

#define INT_DISABLE             0
#define INT_ENABLE              1

#define AREF                    0
#define AVCC                    1
#define INTERNAL_2_56           3
#define ADC_PRE_MASK				0b11111000
#define ADC_CH_MASK				    0b11100000

#define RIGHT_ADJUSTMENT        0
#define LEFT_ADJUSTMENT         1

#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7


#define ADC_PRE_2               0
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7





void ADC_voidInit(void);   // ADC Initialization And Enable

u16 ADC_u8GetChannelReading (u8 ADC_CHANNELS);  // Read From The ADC Channel



#endif /* MCAL_ADC_ADC_H_ */
