################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER/Watch_Dog/Watch_Dog.c 

OBJS += \
./MCAL/TIMER/Watch_Dog/Watch_Dog.o 

C_DEPS += \
./MCAL/TIMER/Watch_Dog/Watch_Dog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER/Watch_Dog/%.o: ../MCAL/TIMER/Watch_Dog/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


