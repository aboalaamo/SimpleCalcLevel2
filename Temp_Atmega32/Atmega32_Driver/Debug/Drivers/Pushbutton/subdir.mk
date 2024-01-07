################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Pushbutton/Pushbutton.c 

OBJS += \
./Drivers/Pushbutton/Pushbutton.o 

C_DEPS += \
./Drivers/Pushbutton/Pushbutton.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Pushbutton/%.o: ../Drivers/Pushbutton/%.c Drivers/Pushbutton/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


