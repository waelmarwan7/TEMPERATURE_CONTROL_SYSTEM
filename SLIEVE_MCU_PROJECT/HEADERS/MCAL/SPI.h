/*
 * SPI.h
 *
 *  Created on: Aug 26, 2023
 *      Author: abdoy
 */

#ifndef SPI_H_
#define SPI_H_

/*SPCR*/
#define SPIE 	 7
#define SPE 	 6
#define DORD	 5
#define MSTR	 4
#define CPOL 	 3
#define CPHA	 2
#define SPR1	 1
#define SPR0	 0

/*SPSR*/
#define SPIF	 7
#define WCOL	 6
#define SPI2X	 0

/*fUNCTIONS*/

void SPI_InitMaster();
void SPI_InitSlave();
u8 SPI_TransRecieve(u8 u8Data_Copy);


#endif /* SPI_H_ */
