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

#ifndef INCLUDE_HAL_SPI_HPP_
#define INCLUDE_HAL_SPI_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <hal++/interface/SPI.h>

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

template <SPI_TypeDef * SPI_INSTANCE(), void ENABLE_PERIPHERAL_CLOCK(), uint32_t MODE, uint32_t DIRECTION, uint32_t DATA_SIZE, uint32_t CLK_POLARITY, uint32_t CLK_PHASE, uint32_t BAUD_RATE_PRESCALER, uint32_t FIRST_BIT>
class SPI : public interface::SPI
{
public:
  SPI(interface::DigitalOutPin & mosi, interface::DigitalOutPin & miso, interface::DigitalOutPin & sck)
  : _mosi{mosi}
  , _miso{miso}
  , _sck{sck}
  , _spi_hdl{}
  { }
  virtual ~SPI() { }

  virtual bool    init() override;
  virtual ssize_t transfer(uint8_t const * const tx_buf, uint8_t * rx_buf, size_t const tx_buf_size) override;


private:
  interface::DigitalOutPin & _mosi, & _miso, & _sck;
  SPI_HandleTypeDef _spi_hdl; 
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "SPI.ipp"

#endif /* INCLUDE_HAL_SPI_HPP_ */
