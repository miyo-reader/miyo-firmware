##########################################################################
cmake_minimum_required(VERSION 3.16)
##########################################################################
project(miyo-reader)
##########################################################################
set(MIYO_READER ${PROJECT_NAME}-firmware)
##########################################################################
enable_language(ASM)
##########################################################################
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(CMAKE_SIZE arm-none-eabi-size)
set(CMAKE_DEBUGGER arm-none-eabi-gdb)
set(CMAKE_CPPFILT arm-none-eabi-c++filt)
##########################################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
##########################################################################
add_executable(${MIYO_READER} "")
##########################################################################
target_include_directories(${MIYO_READER} PUBLIC include)
target_include_directories(${MIYO_READER} PUBLIC external/cmsis/current/Include)
target_include_directories(${MIYO_READER} PUBLIC external/cmsis_device_l4/current/Include)
target_include_directories(${MIYO_READER} PUBLIC external/stm32l4xx_hal_driver/current/Inc)
##########################################################################
set(STM32L4xx_HAL_DRIVER_SRC_PATH external/stm32l4xx_hal_driver/current/Src)
target_sources(${MIYO_READER}
  PUBLIC
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dma2d.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_irda.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_pka.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_smartcard_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_adc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_rcc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_adc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dma.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_iwdg.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_pssi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_smbus.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_comp.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_rng.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_adc_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dma_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_lcd.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_pwr.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_smbus_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_crc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_rtc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dsi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_lptim.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_pwr_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_spi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_crs.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_sdmmc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_can.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_exti.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_ltdc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_qspi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_spi_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_dac.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_spi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_comp.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_firewall.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_ltdc_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_rcc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_sram.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_dma2d.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_swpmi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_cortex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_flash.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_mmc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_rcc_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_swpmi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_dma.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_tim.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_crc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_flash_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_mmc_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_rng.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_tim.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_exti.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_usart.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_crc_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_flash_ramfunc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_rng_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_timebase_tim_template.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_fmc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_usb.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_cryp.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_gfxmmu.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_nand.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_rtc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_tim_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_gpio.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_utils.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_cryp_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_gpio.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_nor.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_rtc_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_tsc.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_i2c.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dac.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_hash.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_opamp.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_sai.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_uart.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_lptim.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dac_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_hash_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_opamp_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_sai_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_uart_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_lpuart.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dcmi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_hcd.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_ospi.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_sd.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_usart.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_opamp.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dfsdm.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_i2c.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_pcd.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_sd_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_usart_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_pka.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_dfsdm_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_i2c_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_pcd_ex.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_smartcard.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_hal_wwdg.c
  ${STM32L4xx_HAL_DRIVER_SRC_PATH}/stm32l4xx_ll_pwr.c

  src/main.c
  src/stm32l4s5i_iot01.c
  src/stm32l4xx_hal_msp.c
  src/stm32l4xx_it.c
  src/system_stm32l4xx.c

  startup/startup_stm32l4s5aiix.s
)
##########################################################################
target_compile_definitions(${MIYO_READER} PUBLIC USE_HAL_DRIVER)
target_compile_definitions(${MIYO_READER} PUBLIC DEBUG)
target_compile_definitions(${MIYO_READER} PUBLIC STM32L4S5xx)
##########################################################################
target_compile_features(${MIYO_READER} PUBLIC cxx_std_17)
##########################################################################
target_compile_options(${MIYO_READER} PUBLIC
  -mcpu=cortex-m4 
  -mthumb 
  -mfloat-abi=hard 
  -mfpu=fpv4-sp-d16
  -fstack-usage
  -Wall
)
##########################################################################
set_target_properties(
  ${MIYO_READER}
  PROPERTIES 
  LINK_FLAGS 
  "-T ../ldscript/STM32L4S5AIIX_FLASH.ld \
   -mthumb \
   -mcpu=cortex-m4 \
   -mfloat-abi=hard \
   -mfpu=fpv4-sp-d16 \
   -Wl,--gc-sections")
##########################################################################
