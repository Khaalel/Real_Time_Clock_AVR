################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SEVENSEGMENTS/SEVENSEGMENT.c \
../HAL/SEVENSEGMENTS/SEVENSEGMENT_cfg.c 

OBJS += \
./HAL/SEVENSEGMENTS/SEVENSEGMENT.o \
./HAL/SEVENSEGMENTS/SEVENSEGMENT_cfg.o 

C_DEPS += \
./HAL/SEVENSEGMENTS/SEVENSEGMENT.d \
./HAL/SEVENSEGMENTS/SEVENSEGMENT_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SEVENSEGMENTS/%.o: ../HAL/SEVENSEGMENTS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


