##########################################################################
cmake_minimum_required(VERSION 3.16)
##########################################################################
set(STM32L4_HAL_TARGET "miyo-stm32hal")
##########################################################################
add_library(${STM32L4_HAL_TARGET} STATIC "")
##########################################################################
target_compile_definitions(${STM32L4_HAL_TARGET} PRIVATE USE_HAL_DRIVER)
target_compile_definitions(${STM32L4_HAL_TARGET} PRIVATE DEBUG)
target_compile_definitions(${STM32L4_HAL_TARGET} PUBLIC  STM32L4S5xx)
##########################################################################
target_include_directories(${STM32L4_HAL_TARGET} PUBLIC  current/Inc)
target_include_directories(${STM32L4_HAL_TARGET} PRIVATE ../../include)
target_include_directories(${STM32L4_HAL_TARGET} PRIVATE ../cmsis/current/Include)
target_include_directories(${STM32L4_HAL_TARGET} PRIVATE ../cmsis_device_l4/current/Include)
##########################################################################
target_compile_options(${STM32L4_HAL_TARGET} PUBLIC
  -mcpu=cortex-m4
  -mthumb
  -mfloat-abi=hard
  -mfpu=fpv4-sp-d16
  -fstack-usage
  -Wall
)
##########################################################################
target_sources(${STM32L4_HAL_TARGET}
  PRIVATE
  current/Src/stm32l4xx_hal_dma2d.c
  current/Src/stm32l4xx_hal_irda.c
  current/Src/stm32l4xx_hal_pka.c
  current/Src/stm32l4xx_hal_smartcard_ex.c
  current/Src/stm32l4xx_ll_adc.c
  current/Src/stm32l4xx_ll_rcc.c
  current/Src/stm32l4xx_hal_adc.c
  current/Src/stm32l4xx_hal_dma.c
  current/Src/stm32l4xx_hal_iwdg.c
  current/Src/stm32l4xx_hal_pssi.c
  current/Src/stm32l4xx_hal_smbus.c
  current/Src/stm32l4xx_ll_comp.c
  current/Src/stm32l4xx_ll_rng.c
  current/Src/stm32l4xx_hal_adc_ex.c
  current/Src/stm32l4xx_hal_dma_ex.c
  current/Src/stm32l4xx_hal_lcd.c
  current/Src/stm32l4xx_hal_pwr.c
  current/Src/stm32l4xx_hal_smbus_ex.c
  current/Src/stm32l4xx_ll_crc.c
  current/Src/stm32l4xx_ll_rtc.c
  current/Src/stm32l4xx_hal.c
  current/Src/stm32l4xx_hal_dsi.c
  current/Src/stm32l4xx_hal_lptim.c
  current/Src/stm32l4xx_hal_pwr_ex.c
  current/Src/stm32l4xx_hal_spi.c
  current/Src/stm32l4xx_ll_crs.c
  current/Src/stm32l4xx_ll_sdmmc.c
  current/Src/stm32l4xx_hal_can.c
  current/Src/stm32l4xx_hal_exti.c
  current/Src/stm32l4xx_hal_ltdc.c
  current/Src/stm32l4xx_hal_qspi.c
  current/Src/stm32l4xx_hal_spi_ex.c
  current/Src/stm32l4xx_ll_dac.c
  current/Src/stm32l4xx_ll_spi.c
  current/Src/stm32l4xx_hal_comp.c
  current/Src/stm32l4xx_hal_firewall.c
  current/Src/stm32l4xx_hal_ltdc_ex.c
  current/Src/stm32l4xx_hal_rcc.c
  current/Src/stm32l4xx_hal_sram.c
  current/Src/stm32l4xx_ll_dma2d.c
  current/Src/stm32l4xx_ll_swpmi.c
  current/Src/stm32l4xx_hal_cortex.c
  current/Src/stm32l4xx_hal_flash.c
  current/Src/stm32l4xx_hal_mmc.c
  current/Src/stm32l4xx_hal_rcc_ex.c
  current/Src/stm32l4xx_hal_swpmi.c
  current/Src/stm32l4xx_ll_dma.c
  current/Src/stm32l4xx_ll_tim.c
  current/Src/stm32l4xx_hal_crc.c
  current/Src/stm32l4xx_hal_flash_ex.c
  current/Src/stm32l4xx_hal_mmc_ex.c
  current/Src/stm32l4xx_hal_rng.c
  current/Src/stm32l4xx_hal_tim.c
  current/Src/stm32l4xx_ll_exti.c
  current/Src/stm32l4xx_ll_usart.c
  current/Src/stm32l4xx_hal_crc_ex.c
  current/Src/stm32l4xx_hal_flash_ramfunc.c
  current/Src/stm32l4xx_hal_rng_ex.c
  current/Src/stm32l4xx_hal_timebase_tim_template.c
  current/Src/stm32l4xx_ll_fmc.c
  current/Src/stm32l4xx_ll_usb.c
  current/Src/stm32l4xx_hal_cryp.c
  current/Src/stm32l4xx_hal_gfxmmu.c
  current/Src/stm32l4xx_hal_nand.c
  current/Src/stm32l4xx_hal_rtc.c
  current/Src/stm32l4xx_hal_tim_ex.c
  current/Src/stm32l4xx_ll_gpio.c
  current/Src/stm32l4xx_ll_utils.c
  current/Src/stm32l4xx_hal_cryp_ex.c
  current/Src/stm32l4xx_hal_gpio.c
  current/Src/stm32l4xx_hal_nor.c
  current/Src/stm32l4xx_hal_rtc_ex.c
  current/Src/stm32l4xx_hal_tsc.c
  current/Src/stm32l4xx_ll_i2c.c
  current/Src/stm32l4xx_hal_dac.c
  current/Src/stm32l4xx_hal_hash.c
  current/Src/stm32l4xx_hal_opamp.c
  current/Src/stm32l4xx_hal_sai.c
  current/Src/stm32l4xx_hal_uart.c
  current/Src/stm32l4xx_ll_lptim.c
  current/Src/stm32l4xx_hal_dac_ex.c
  current/Src/stm32l4xx_hal_hash_ex.c
  current/Src/stm32l4xx_hal_opamp_ex.c
  current/Src/stm32l4xx_hal_sai_ex.c
  current/Src/stm32l4xx_hal_uart_ex.c
  current/Src/stm32l4xx_ll_lpuart.c
  current/Src/stm32l4xx_hal_dcmi.c
  current/Src/stm32l4xx_hal_hcd.c
  current/Src/stm32l4xx_hal_ospi.c
  current/Src/stm32l4xx_hal_sd.c
  current/Src/stm32l4xx_hal_usart.c
  current/Src/stm32l4xx_ll_opamp.c
  current/Src/stm32l4xx_hal_dfsdm.c
  current/Src/stm32l4xx_hal_i2c.c
  current/Src/stm32l4xx_hal_pcd.c
  current/Src/stm32l4xx_hal_sd_ex.c
  current/Src/stm32l4xx_hal_usart_ex.c
  current/Src/stm32l4xx_ll_pka.c
  current/Src/stm32l4xx_hal_dfsdm_ex.c
  current/Src/stm32l4xx_hal_i2c_ex.c
  current/Src/stm32l4xx_hal_pcd_ex.c
  current/Src/stm32l4xx_hal_smartcard.c
  current/Src/stm32l4xx_hal_wwdg.c
  current/Src/stm32l4xx_ll_pwr.c
)
##########################################################################
