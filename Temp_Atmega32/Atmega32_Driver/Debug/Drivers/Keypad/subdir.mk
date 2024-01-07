################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Keypad/Keypad.c 

OBJS += \
./Drivers/Keypad/Keypad.o 

C_DEPS += \
./Drivers/Keypad/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Keypad/%.o: ../Drivers/Keypad/%.c Drivers/Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


