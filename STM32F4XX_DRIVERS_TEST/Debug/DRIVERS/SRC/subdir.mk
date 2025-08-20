################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVERS/SRC/STM32F446XX_GPIO_DRIVER.c 

OBJS += \
./DRIVERS/SRC/STM32F446XX_GPIO_DRIVER.o 

C_DEPS += \
./DRIVERS/SRC/STM32F446XX_GPIO_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVERS/SRC/%.o DRIVERS/SRC/%.su DRIVERS/SRC/%.cyclo: ../DRIVERS/SRC/%.c DRIVERS/SRC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"D:/MCU1_Driver_Development/STM32F4XX_DRIVERS_TEST/DRIVERS/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DRIVERS-2f-SRC

clean-DRIVERS-2f-SRC:
	-$(RM) ./DRIVERS/SRC/STM32F446XX_GPIO_DRIVER.cyclo ./DRIVERS/SRC/STM32F446XX_GPIO_DRIVER.d ./DRIVERS/SRC/STM32F446XX_GPIO_DRIVER.o ./DRIVERS/SRC/STM32F446XX_GPIO_DRIVER.su

.PHONY: clean-DRIVERS-2f-SRC

