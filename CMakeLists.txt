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
add_subdirectory(external/cmsis)
add_subdirectory(external/cmsis_device_l4)
add_subdirectory(external/stm32l4xx_hal_driver)
##########################################################################
target_include_directories(${MIYO_READER} PUBLIC include)
##########################################################################
target_sources(${MIYO_READER}
  PUBLIC

  src/main.c
  src/stm32l4s5i_iot01.c
  src/stm32l4xx_hal_msp.c
  src/stm32l4xx_it.c
  src/syscalls.c
  src/sysmem.c
  src/system_stm32l4xx.c

  startup/startup_stm32l4s5aiix.s
)
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
   -Wl,--gc-sections"
)
##########################################################################
