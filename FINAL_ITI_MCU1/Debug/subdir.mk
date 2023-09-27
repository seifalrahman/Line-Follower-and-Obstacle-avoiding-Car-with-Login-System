################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prg.c \
../EEPROM.c \
../IIC.c \
../KPD.c \
../LCD.c \
../LINE_FOLLOWER.c \
../MOTOR.c \
../Timer_1.c \
../UART.c \
../ULTRASONIC.c \
../interrupt0.c \
../ir.c \
../main.c 

OBJS += \
./DIO_Prg.o \
./EEPROM.o \
./IIC.o \
./KPD.o \
./LCD.o \
./LINE_FOLLOWER.o \
./MOTOR.o \
./Timer_1.o \
./UART.o \
./ULTRASONIC.o \
./interrupt0.o \
./ir.o \
./main.o 

C_DEPS += \
./DIO_Prg.d \
./EEPROM.d \
./IIC.d \
./KPD.d \
./LCD.d \
./LINE_FOLLOWER.d \
./MOTOR.d \
./Timer_1.d \
./UART.d \
./ULTRASONIC.d \
./interrupt0.d \
./ir.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


