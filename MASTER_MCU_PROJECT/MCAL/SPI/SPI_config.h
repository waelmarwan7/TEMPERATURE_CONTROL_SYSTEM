/*
 * SPI_config.h
 *
 *  Created on: Aug 29, 2023
 *      Author: user
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#define SPI_DATA_ORDER						SPI_DATA_MSP_FIRST

/*Select Master/Slave
 * choose between
 * 1. SPI_MASTER
 * 2. SPI_SLAVE
 */
#define SPI_MASTER_SLAVE_SELECT			SPI_MASTER

/*Set Clock Polarity
 * choose between
 * 1. SPI_RISING_LEADING_FALLING_TRAILING
 * 2. SPI_FALLING_LEADING_RISING_TRAILING
 */
#define SPI_CLOCK_POLARITY				SPI_RISING_LEADING_FALLING_TRAILING

/*Set Clock Phase
 * choose between
 * 1. SPI_SAMPLE_LEADING_SETUP_TRAILING
 * 2. SPI_SETUP_LEADING_SAMPLE_TRAILING
 */
#define SPI_CLOCK_PHASE					SPI_SAMPLE_LEADING_SETUP_TRAILING

/*Set Clock Rate Divide
 * 1. SPI_FREQ_DIVIDED_BY_2
 * 2. SPI_FREQ_DIVIDED_BY_4
 * 3. SPI_FREQ_DIVIDED_BY_8
 * 4. SPI_FREQ_DIVIDED_BY_16
 * 5. SPI_FREQ_DIVIDED_BY_32
 * 6. SPI_FREQ_DIVIDED_BY_64
 * 7. SPI_FREQ_DIVIDED_BY_128
 */
#define SPI_CLOCK_RATE					SPI_FREQ_DIVIDED_BY_16

/*Set SPI Interrupt Enable
 * choose between
 * 1. SPI_INTERRUPT_DISABLE
 * 2. SPI_INTERRUPT_ENABLE
 */
#define SPI_INTERRUPT_ENABLE_MODE			SPI_INTERRUPT_DISABLE

/*Set SPI Enable
 * choose between
 * 1. SPI_DISABLE
 * 2. SPI_ENABLE
 */
#define SPI_ENABLE_MODE						SPI_ENABLE


#endif /* MCAL_SPI_SPI_CONFIG_H_ */
