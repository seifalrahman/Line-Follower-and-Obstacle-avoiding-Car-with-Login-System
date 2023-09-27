################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prg.c \
../LCD.c \
../Timer1.c \
../UART.c \
../ULTRASONIC.c \
../main.c 

OBJS += \
./DIO_Prg.o \
./LCD.o \
./Timer1.o \
./UART.o \
./ULTRASONIC.o \
./main.o 

C_DEPS += \
./DIO_Prg.d \
./LCD.d \
./Timer1.d \
./UART.d \
./ULTRASONIC.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


