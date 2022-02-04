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
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
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

  src/main.cpp
  src/stm32l4xx_hal_msp.c
  src/stm32l4xx_it.c
  src/syscalls.c
  src/sysmem.c
  src/system_stm32l4xx.c

  startup/startup_stm32l4s5aiix.s
)
##########################################################################
target_compile_features(${MIYO_READER} PRIVATE cxx_std_17)
##########################################################################
target_compile_definitions(${MIYO_READER} PRIVATE DBG_ENABLE_ERROR)
target_compile_definitions(${MIYO_READER} PRIVATE DBG_ENABLE_WARNING)
target_compile_definitions(${MIYO_READER} PRIVATE DBG_ENABLE_INFO)
target_compile_definitions(${MIYO_READER} PRIVATE DBG_ENABLE_DEBUG)
target_compile_definitions(${MIYO_READER} PRIVATE DBG_ENABLE_VERBOSE)
##########################################################################
target_link_libraries(${MIYO_READER}
  miyo-cmsis
  miyo-cmsis-device-l4
  miyo-stm32hal
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
add_custom_target(upload
  COMMENT "Uploading miyo-reader-firmware to target ..."
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  COMMAND openocd -f tools/openocd/openocd.cfg
)
##########################################################################
