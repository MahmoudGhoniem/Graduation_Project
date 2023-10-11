################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dc_motor.c \
../gpio.c \
../ir_sensor.c \
../lcd.c \
../main.c \
../ultra_sonic.c 

OBJS += \
./dc_motor.o \
./gpio.o \
./ir_sensor.o \
./lcd.o \
./main.o \
./ultra_sonic.o 

C_DEPS += \
./dc_motor.d \
./gpio.d \
./ir_sensor.d \
./lcd.d \
./main.d \
./ultra_sonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


