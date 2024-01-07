################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CalculatorL1/CalcL1.c 

OBJS += \
./Drivers/CalculatorL1/CalcL1.o 

C_DEPS += \
./Drivers/CalculatorL1/CalcL1.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CalculatorL1/%.o: ../Drivers/CalculatorL1/%.c Drivers/CalculatorL1/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


