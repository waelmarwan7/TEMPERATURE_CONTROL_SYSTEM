/*
 * ADC_config.h
 *
 *  Created on: Sep 4, 2023
 *      Author: user
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*
 Options:-
 	 1-ADC_ENABLE
 	 2-ADC_DISABLE

 */

#define ADC_STATUS   ADC_ENABLE

/*
 Options:-
 	 1-INT_ENABLE
 	 2-INT_DISABLE

 */

#define INT_STATUS   INT_DISABLE


/*
 Options:-
 	 1-AREF
 	 2-AVCC
 	 3-INTERNAL_2_56

 */

#define ADC_VREF  AVCC

/*
  Options :
 	 1-RIGHT_ADJUSTMENT
 	 2-LEFT_ADJUSTMENT

  */

#define ADC_ADJUSTMENT RIGHT_ADJUSTMENT


/*
 Options:-
 	 1-ADC_PRE_2
 	 2-ADC_PRE_4
 	 3-ADC_PRE_8
 	 4-ADC_PRE_16
 	 5-ADC_PRE_32
 	 6-ADC_PRE_64
 	 7-ADC_PRE_128

 */

#define  ADC_PRESCALLER   ADC_PRE_128



#endif /* MCAL_ADC_ADC_CONFIG_H_ */
