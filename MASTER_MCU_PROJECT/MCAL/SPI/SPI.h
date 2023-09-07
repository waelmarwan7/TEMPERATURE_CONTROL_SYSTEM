/*
 * SPI.h
 *
 *  Created on: Aug 29, 2023
 *      Author: user
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_



/* SPI Control Register SPCR */#define SPCR_SPIE			7
#define SPCR_SPE			6
#define SPCR_DORD			5
#define SPCR_MSTR			4
#define SPCR_CPOL			3
#define SPCR_CPHA			2
#define SPCR_SPR1			1
#define SPCR_SPR0			0



/* SPI Status Register SPSR  */
#define SPSR_SPIF			7
#define SPSR_WCOL			6
#define SPSR_SPI2X			0


/* SPI I/O Data Register SPDR */


/*SPI CONFIG.....*/

#define SPI_INTERRUPT_DISABLE					0
#define SPI_INTERRUPT_ENABLE 					1

#define SPI_DISABLE								0
#define SPI_ENABLE 								1

#define SPI_DATA_LSB_FIRST 						0
#define SPI_DATA_MSP_FIRST 						1

#define SPI_MASTER								0
#define SPI_SLAVE 								1

#define SPI_RISING_LEADING_FALLING_TRAILING 	0
#define SPI_FALLING_LEADING_RISING_TRAILING		1

#define SPI_SAMPLE_LEADING_SETUP_TRAILING 		0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING		1

#define SPI_FREQ_DIVIDED_BY_2					0
#define SPI_FREQ_DIVIDED_BY_4					1
#define SPI_FREQ_DIVIDED_BY_8					2
#define SPI_FREQ_DIVIDED_BY_16					3
#define SPI_FREQ_DIVIDED_BY_32					4
#define SPI_FREQ_DIVIDED_BY_64					5
#define SPI_FREQ_DIVIDED_BY_128					6




//ProtoTypes :
void SPI_VoidInit(void);
u8   SPI_transceive(u8 u8Data_copy);



#endif /* MCAL_SPI_SPI_H_ */
