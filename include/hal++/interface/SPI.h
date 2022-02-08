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

#ifndef INCLUDE_HAL_INTERFACE_SPI_H_
#define INCLUDE_HAL_INTERFACE_SPI_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdint>
#include <unistd.h> /* size_t, ssize_t */

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal::interface
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class SPI
{

public:

  virtual ~SPI() { }

  virtual bool    init() = 0;
  virtual ssize_t transfer(uint8_t const * const tx_buf, uint8_t * rx_buf, size_t const tx_buf_size) = 0;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal::interface */

#endif /* INCLUDE_HAL_INTERFACE_SPI_H_ */
