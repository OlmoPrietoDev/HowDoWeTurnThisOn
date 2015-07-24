################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Battalion.cpp \
../src/Box.cpp \
../src/GameLoop.cpp \
../src/HowDoWeTurnThisOn.cpp \
../src/Map.cpp \
../src/MouseConverter.cpp 

OBJS += \
./src/Battalion.o \
./src/Box.o \
./src/GameLoop.o \
./src/HowDoWeTurnThisOn.o \
./src/Map.o \
./src/MouseConverter.o 

CPP_DEPS += \
./src/Battalion.d \
./src/Box.d \
./src/GameLoop.d \
./src/HowDoWeTurnThisOn.d \
./src/Map.d \
./src/MouseConverter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/guillermo/SFML-2.3.1/include -I/home/guillermo/Documents/libjpeg/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


