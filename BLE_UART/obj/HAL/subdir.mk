################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/BLE/HAL/MCU.c \
E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/BLE/HAL/RTC.c \
E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/BLE/HAL/SLEEP.c 

OBJS += \
./HAL/MCU.o \
./HAL/RTC.o \
./HAL/SLEEP.o 

C_DEPS += \
./HAL/MCU.d \
./HAL/RTC.d \
./HAL/SLEEP.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/MCU.o: E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/BLE/HAL/MCU.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DDEBUG=1 -DCH573 -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Startup" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Ld" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\LIB" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/RTC.o: E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/BLE/HAL/RTC.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DDEBUG=1 -DCH573 -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Startup" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Ld" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\LIB" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/SLEEP.o: E:/VV_application/BLE单片机/CH573EVT/EVT/EXAM/BLE/HAL/SLEEP.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DDEBUG=1 -DCH573 -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Startup" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\Ld" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\LIB" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"E:\VV_application\BLE单片机\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

