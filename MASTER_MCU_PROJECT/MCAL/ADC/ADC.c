/*
 * ADC.c

 *
 *  Created on: Aug 17, 2023
 *      Author: MARWAN WAEL
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO.h"
#include "ADC.h"
#include "ADC_config.h"
#include "avr/io.h"
#include "util/delay.h"

void ADC_voidInit (void)
{
	/*Select the voltage reference*/
		#if ADC_VREF == AREF
			CLR_BIT(ADMUX , ADMUX_REFS0) ;
			CLR_BIT(ADMUX , ADMUX_REFS1) ;

		#elif ADC_VREF == AVCC
			SET_BIT(ADMUX , ADMUX_REFS0) ;
			CLR_BIT(ADMUX , ADMUX_REFS1) ;

		#elif ADC_VREF == INTERNAL_2_56
			SET_BIT(ADMUX , ADMUX_REFS0) ;
			SET_BIT(ADMUX , ADMUX_REFS1) ;

		#else
			#error "Wrong ADC_VREF config"

		#endif


		/*Set Left Adjust Result*/
		#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
				CLR_BIT(ADMUX , ADMUX_ADLAR) ;

		#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
				SET_BIT(ADMUX , ADMUX_ADLAR) ;

		#else
			#error "Wrong ADC_ADJUSTMENT config"

		#endif

		/*Set Prescaler Value*/
		ADCSRA &= ADC_PRE_MASK ;
		ADCSRA |= ADC_PRESCALLER ;

		/* ENABLE The Peripheral & Interrupt  */

		/*Enable ADC Peripheral*/
		#if ADC_STATUS == ADC_DISABLE
			CLR_BIT(ADCSRA , ADCSRA_ADEN) ;
		#elif ADC_STATUS == ADC_ENABLE
			SET_BIT(ADCSRA , ADCSRA_ADEN) ;
		#else
		#error "Wrong ADC_STATUS config"
		#endif

		/*Enable ADC Interrupt*/
		#if INT_STATUS == INT_DISABLE
			CLR_BIT(ADCSRA , ADCSRA_ADIE) ;
		#elif INT_STATUS == INT_ENABLE
			SET_BIT(ADCSRA , ADCSRA_ADIE) ;
		#else
		#error "Wrong INT_STATUS config"
		#endif
}

u16 ADC_u8GetChannelReading (u8 ADC_CHANNELS)
{
	u16 ADC_L=0; // ADC VALUE OF high register and low register
	u16 ADC_H=0;

		#if ADC_CHANNELS == ADC_CHANNEL0
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT) ;

		#elif ADC_CHANNELS == ADC_CHANNEL1
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_INPUT) ;
		#elif ADC_CHANNELS == ADC_CHANNEL2
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_INPUT) ;
		#elif ADC_CHANNELS == ADC_CHANNEL3
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_INPUT) ;
		#elif ADC_CHANNELS == ADC_CHANNEL4
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_INPUT) ;
		#elif ADC_CHANNELS == ADC_CHANNEL5
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_INPUT) ;
		#elif ADC_CHANNELS == ADC_CHANNEL6
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_INPUT) ;
		#elif ADC_CHANNELS == ADC_CHANNEL7
		     DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_INPUT) ;

		#endif


	//step 1 : Clear MUX bits in ADMUX
	ADMUX   &= ADC_CH_MASK;

	//Step 2 : Set the required  ADC Channel Selection into the MUX bits
	ADMUX   |=ADC_CHANNELS;


	// Step 3 : Start Single Converstion
	SET_BIT(ADCSRA , ADCSRA_ADSC );


	// Step 4 :  Polling (busy wait ) until the conversion complete flag is set
	while((GET_BIT(ADCSRA , ADCSRA_ADIF)) == 0);

	_delay_us(10);
	/* Step 5 :  Clear Conversion Complete Flag
	SET_BIT(ADCSRA,ADCSRA_ADIF);
    */
	// Step 7 :   return value in ADCH & ADCL (RIGHT adjustment result 10 bits)

	    ADC_L = (u16)ADCL;		/* Read lower byte*/
	    ADC_H = (u16)ADCH*256;		/* Read higher 2 bits and
						Multiply with weight */
	    ADC_H = ADC_H + ADC_L;

	// Step 8 :   return value in ADCL (RIGHT adjustment result 8 bits)  BECUASE WE ONLY NEED LOWEST 8 BITS.. (HIGHEST TEMPERATURE NEEDED IS ONLY < 250 C).....

	return ADC_H;
}
