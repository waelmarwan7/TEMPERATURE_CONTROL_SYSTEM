/*
 * SPI.c

 *
 *  Created on: Aug 29, 2023
 *      Author: marwan wael mahmoud abbas
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SPI.h"
#include "SPI_config.h"
#include "../DIO/DIO.h"
#include "avr/io.h"



void SPI_VoidInit(void)
{

	    //SS : Pullup internally
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);

		//MOSI
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);

		//MISO
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);

		//SCK
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);

	/*Data Order*/
	#if SPI_DATA_ORDER == SPI_DATA_LSB_FIRST
		SET_BIT(SPCR , SPCR_DORD) ;
	#elif SPI_DATA_ORDER == SPI_DATA_MSP_FIRST
		CLR_BIT(SPCR , SPCR_DORD) ;
	#else
		#error "wrong SPI_DATA_ORDER config"
	#endif

	/*Master/Slave Select*/
	#if SPI_MASTER_SLAVE_SELECT == SPI_MASTER
		SET_BIT(SPCR , SPCR_MSTR) ;
	#elif SPI_MASTER_SLAVE_SELECT == SPI_SLAVE
		CLR_BIT(SPCR , SPCR_MSTR) ;
	#else
		#error "wrong SPI_MASTER_SLAVE_SELECT config"
	#endif

	/*Clock Polarity*/
	#if SPI_CLOCK_POLARITY == SPI_RISING_LEADING_FALLING_TRAILING
		CLR_BIT(SPCR , SPCR_CPOL) ;
	#elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
		SET_BIT(SPCR , SPCR_CPOL) ;
	#else
		#error "wrong SPI_CLOCK_POLARITY config"
	#endif

	/*Clock Phase*/
	#if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING
		CLR_BIT(SPCR , SPCR_CPHA) ;

	#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
		SET_BIT(SPCR , SPCR_CPHA) ;
	#else
		#error "wrong SPI_CLOCK_PHASE config"
	#endif

	/*Clock Rate*/
	#if SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_2
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_4
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_8
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_16
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_32
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_64
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_128
		SET_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#else
		#error "wrong SPI_CLOCK_RATE config"
	#endif

	/*SPI Interrupt Enable*/
	#if SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_DISABLE
		CLR_BIT(SPCR , SPCR_SPIE) ;
	#elif SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_ENABLE
		SET_BIT(SPCR , SPCR_SPIE) ;
	#else
		#error "wrong SPI_INTERRUPT_ENABLE_MODE config"
	#endif

	/*SPI Enable*/
	#if SPI_ENABLE_MODE == SPI_DISABLE
		CLR_BIT(SPCR , SPCR_SPE) ;
	#elif SPI_ENABLE_MODE == SPI_ENABLE
		SET_BIT(SPCR , SPCR_SPE) ;
	#else
		#error "wrong SPI_ENABLE_MODE config"
	#endif

}



u8   SPI_transceive(u8 u8Data_copy){

	/*  send the data  */
	SPDR = u8Data_copy;

	/*  Wait (busy wait ) until transfer complete */
	while((GET_BIT(SPSR , SPIF)) == 0 );

	/*  Get  the exchange  data   */
	return SPDR;


}






