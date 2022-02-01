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
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <USART_TypeDef * USART(), uint32_t BAUD_RATE, uint32_t WORD_LENGTH, uint32_t STOP_BITS, uint32_t PARITY, uint32_t MODE, void ENABLE_PERIPHERAL_CLOCK()>
bool UART<USART, BAUD_RATE, WORD_LENGTH, STOP_BITS, PARITY, MODE, ENABLE_PERIPHERAL_CLOCK>::init()
{
  _tx.init();
  _rx.init();

  ENABLE_PERIPHERAL_CLOCK();

  _hdl_uart.Instance = USART();

  _hdl_uart.Init.BaudRate   = BAUD_RATE;
  _hdl_uart.Init.WordLength = WORD_LENGTH;
  _hdl_uart.Init.StopBits   = STOP_BITS;
  _hdl_uart.Init.Parity     = PARITY;
  _hdl_uart.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  _hdl_uart.Init.Mode       = MODE;

  return (HAL_OK == HAL_UART_Init(&_hdl_uart));
}

template <USART_TypeDef * USART(), uint32_t BAUD_RATE, uint32_t WORD_LENGTH, uint32_t STOP_BITS, uint32_t PARITY, uint32_t MODE, void ENABLE_PERIPHERAL_CLOCK()>
ssize_t UART<USART, BAUD_RATE, WORD_LENGTH, STOP_BITS, PARITY, MODE, ENABLE_PERIPHERAL_CLOCK>::transmit(uint8_t const * const buf, size_t const buf_size)
{
  if (HAL_OK != HAL_UART_Transmit(&_hdl_uart, buf, buf_size, 1000))
    return -1;
  return buf_size;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */
