################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/a2ms2.c \
../src/contactHelpers.c \
../src/contacts.c 

OBJS += \
./src/a2ms2.o \
./src/contactHelpers.o \
./src/contacts.o 

C_DEPS += \
./src/a2ms2.d \
./src/contactHelpers.d \
./src/contacts.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


