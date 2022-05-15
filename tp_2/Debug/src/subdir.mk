################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/extras.c \
../src/inform.c \
../src/main.c \
../src/menu.c \
../src/passenger.c \
../src/statusFlight.c \
../src/type.c \
../src/validations.c 

C_DEPS += \
./src/extras.d \
./src/inform.d \
./src/main.d \
./src/menu.d \
./src/passenger.d \
./src/statusFlight.d \
./src/type.d \
./src/validations.d 

OBJS += \
./src/extras.o \
./src/inform.o \
./src/main.o \
./src/menu.o \
./src/passenger.o \
./src/statusFlight.o \
./src/type.o \
./src/validations.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/extras.d ./src/extras.o ./src/inform.d ./src/inform.o ./src/main.d ./src/main.o ./src/menu.d ./src/menu.o ./src/passenger.d ./src/passenger.o ./src/statusFlight.d ./src/statusFlight.o ./src/type.d ./src/type.o ./src/validations.d ./src/validations.o

.PHONY: clean-src

