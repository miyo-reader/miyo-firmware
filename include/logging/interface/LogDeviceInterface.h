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

#ifndef INCLUDE_LOGGING_INTERFACE_LOGDEVICE_H_
#define INCLUDE_LOGGING_INTERFACE_LOGDEVICE_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdint>
#include <unistd.h> /* size_t, ssize_t */

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::logging::interface
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class LogDevice
{
public:

  virtual ~LogDevice() { }
  
  virtual ssize_t write(uint8_t const * msg, size_t const msg_len) = 0;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::logging::interface */

#endif /* INCLUDE_LOGGING_INTERFACE_LOGDEVICE_H_ */
