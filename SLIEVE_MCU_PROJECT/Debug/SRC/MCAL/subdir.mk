################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/MCAL/DIO.c \
../SRC/MCAL/SPI.c 

OBJS += \
./SRC/MCAL/DIO.o \
./SRC/MCAL/SPI.o 

C_DEPS += \
./SRC/MCAL/DIO.d \
./SRC/MCAL/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/MCAL/%.o: ../SRC/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


