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

#include <hal++/UART.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

UART::UART(interface::DigitalOutPin & tx, interface::DigitalOutPin & rx)
: _tx{tx}
, _rx{rx}
, _hdl_uart{nullptr}
{

}

UART::~UART()
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

bool UART::init()
{
  _tx.init();
  _rx.init();

  /* Enable USART clock */
  __HAL_RCC_USART1_CLK_ENABLE();

  /* USART configuration */
  _hdl_uart.Instance = USART1;

  _hdl_uart.Init.BaudRate   = 115200;
  _hdl_uart.Init.WordLength = UART_WORDLENGTH_8B;
  _hdl_uart.Init.StopBits   = UART_STOPBITS_1;
  _hdl_uart.Init.Parity     = UART_PARITY_NONE;
  _hdl_uart.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  _hdl_uart.Init.Mode       = UART_MODE_TX_RX;

  return (HAL_OK == HAL_UART_Init(&_hdl_uart));
}

ssize_t UART::transmit(uint8_t const * const buf, size_t const buf_size)
{
  if (HAL_OK != HAL_UART_Transmit(&_hdl_uart, buf, buf_size, 1000))
    return -1;
  return buf_size;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */
