################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CalculatorL2/CalcL2.c \
../Drivers/CalculatorL2/MathCalc.c 

OBJS += \
./Drivers/CalculatorL2/CalcL2.o \
./Drivers/CalculatorL2/MathCalc.o 

C_DEPS += \
./Drivers/CalculatorL2/CalcL2.d \
./Drivers/CalculatorL2/MathCalc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CalculatorL2/%.o: ../Drivers/CalculatorL2/%.c Drivers/CalculatorL2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


