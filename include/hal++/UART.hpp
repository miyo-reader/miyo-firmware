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

#ifndef INCLUDE_HAL_UART_HPP_
#define INCLUDE_HAL_UART_HPP_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

#include <hal++/interface/UART.h>

#include <hal++/interface/DigitalOutPin.h>

extern "C" {
#include "stm32l4xx_hal.h"
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <uint32_t BAUD_RATE, uint32_t WORD_LENGTH, uint32_t STOP_BITS, uint32_t PARITY, uint32_t MODE>
class UART : public interface::UART
{
public:

  UART(interface::DigitalOutPin & tx, interface::DigitalOutPin & rx)
  : _tx{tx}
  , _rx{rx}
  , _hdl_uart{}
  { }
  virtual ~UART() { }


  virtual bool    init() override;
  virtual ssize_t transmit(uint8_t const * const buf, size_t const buf_size) override;


private:

  interface::DigitalOutPin & _tx, & _rx;
  UART_HandleTypeDef _hdl_uart;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "UART.ipp"

#endif /* INCLUDE_HAL_UART_HPP_ */
