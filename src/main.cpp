/**
 * miyo-firmware is a firmware for an open software/open hardware ebook reader.
 * Copyright (C) 2021 Alexander Entinger, LXRobotics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

extern "C" {
#include "stm32l4xx_hal.h"
}

#include <hal++/SPI.hpp>
#include <hal++/UART.hpp>
#include <hal++/DigitalInPin.hpp>
#include <hal++/DigitalOutPin.hpp>

#include <driver/IT8951.h>

#include <logging/LoggerBase.hpp>
#include <logging/LogDeviceUart.h>

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

static void SystemClock_Config();

constexpr SPI_TypeDef * Spi_1() { return SPI1; }
constexpr GPIO_TypeDef * Port_A() { return GPIOA; }
constexpr GPIO_TypeDef * Port_B() { return GPIOB; }
constexpr USART_TypeDef * Usart_1() { return USART1; }

static void spi1_clk_enable  () { __HAL_RCC_SPI1_CLK_ENABLE(); }
static void gpioa_clk_enable () { __HAL_RCC_GPIOA_CLK_ENABLE(); }
static void gpiob_clk_enable () { __HAL_RCC_GPIOB_CLK_ENABLE(); }
static void usart1_clk_enable() { __HAL_RCC_USART1_CLK_ENABLE(); }

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

miyo::hal::DigitalOutPin<Port_B,
                         GPIO_PIN_14,
                         GPIO_MODE_OUTPUT_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_HIGH,
                         0,
                         gpiob_clk_enable> led_green;
miyo::hal::DigitalOutPin<Port_B,
                         GPIO_PIN_6,
                         GPIO_MODE_AF_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_HIGH,
                         GPIO_AF7_USART1,
                         gpiob_clk_enable> uart1_tx;
miyo::hal::DigitalOutPin<Port_B,
                         GPIO_PIN_7,
                         GPIO_MODE_AF_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_HIGH,
                         GPIO_AF7_USART1,
                         gpiob_clk_enable> uart1_rx;
miyo::hal::DigitalOutPin<Port_A,
                         GPIO_PIN_5,
                         GPIO_MODE_AF_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_HIGH,
                         GPIO_AF5_SPI1,
                         gpioa_clk_enable> spi1_sck; /* D13 / PA5 */
miyo::hal::DigitalInPin <Port_A,
                         GPIO_PIN_6,
                         GPIO_MODE_AF_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_HIGH,
                         GPIO_AF5_SPI1,
                         gpioa_clk_enable> spi1_miso; /* D12 / PA6 */
miyo::hal::DigitalOutPin<Port_A,
                         GPIO_PIN_7,
                         GPIO_MODE_AF_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_HIGH,
                         GPIO_AF5_SPI1,
                         gpioa_clk_enable> spi1_mosi; /* D11 / PA7 */
miyo::hal::DigitalOutPin<Port_A,
                         GPIO_PIN_2,
                         GPIO_MODE_OUTPUT_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_HIGH,
                         0,
                         gpioa_clk_enable> it8951_cs_select; /* D10 / PA2 */
miyo::hal::DigitalOutPin<Port_A,
                         GPIO_PIN_15,
                         GPIO_MODE_OUTPUT_PP,
                         GPIO_NOPULL,
                         GPIO_SPEED_FREQ_LOW,
                         0,
                         gpioa_clk_enable> it8951_nreset; /* D9 / PA15 */
miyo::hal::DigitalInPin <Port_B,
                         GPIO_PIN_2,
                         GPIO_MODE_INPUT,
                         GPIO_PULLUP,
                         GPIO_SPEED_FREQ_HIGH,
                         0,
                         gpiob_clk_enable> it8951_host_ready; /* D8 / PB2 */

miyo::hal::UART<Usart_1,
                115200,
                UART_WORDLENGTH_8B,
                UART_STOPBITS_1,
                UART_PARITY_NONE,
                UART_MODE_TX_RX,
                usart1_clk_enable> uart1(uart1_tx, uart1_rx);

miyo::hal::SPI<Spi_1,
               spi1_clk_enable,
               SPI_MODE_MASTER,
               SPI_DIRECTION_2LINES,
               SPI_DATASIZE_16BIT,
               SPI_POLARITY_LOW,
               SPI_PHASE_1EDGE,
               SPI_BAUDRATEPRESCALER_128,
               SPI_FIRSTBIT_MSB> spi1(spi1_mosi, spi1_miso, spi1_sck);

MIYO_LOG_DEVICE_UART_INSTANCE(uart1);

miyo::driver::IT8951 it8951(spi1, it8951_cs_select, it8951_nreset, it8951_host_ready);

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  led_green.init();
  uart1.init();

  it8951_cs_select.init();
  it8951_nreset.init();
  it8951_host_ready.init();

  it8951_cs_select.set();

  it8951_nreset.clr();
  HAL_Delay(100);
  it8951_nreset.set();
  HAL_Delay(100);

  spi1.init();

  for(;;)
  {
    led_green.set();
    HAL_Delay(100);
    led_green.clr();
    HAL_Delay(100);

    DBG_INFO("Hello Miyo!");

    uint16_t data = 0;
    it8951.command(miyo::driver::IT8951::Command::REG_RD);
    it8951.write(0x0208);
    it8951.read(data);
    DBG_INFO("LISAR = 0x%04x", data);
  }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follows :
  *            System Clock source            = PLL (MSI)
  *            SYSCLK(Hz)                     = 120000000
  *            HCLK(Hz)                       = 120000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            MSI Frequency(Hz)              = 4000000
  *            PLL_M                          = 1
  *            PLL_N                          = 60
  *            PLL_Q                          = 2
  *            PLL_R                          = 2
  *            PLL_P                          = 7
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  
  /* Enable voltage range 1 boost mode for frequency above 80 Mhz */
  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);
  __HAL_RCC_PWR_CLK_DISABLE();

  /* Enable MSI Oscillator and activate PLL with MSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 60;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLP = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }
  
  /* To avoid undershoot due to maximum frequency, select PLL as system clock source */
  /* with AHB prescaler divider 2 as first step */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }

  /* AHB prescaler divider at 1 as second step */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

