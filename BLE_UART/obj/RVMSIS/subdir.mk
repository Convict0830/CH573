################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/SRC/RVMSIS/core_riscv.c 

OBJS += \
./RVMSIS/core_riscv.o 

C_DEPS += \
./RVMSIS/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
RVMSIS/core_riscv.o: E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/SRC/RVMSIS/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DDEBUG=1 -DCH573 -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Startup" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Ld" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\LIB" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

