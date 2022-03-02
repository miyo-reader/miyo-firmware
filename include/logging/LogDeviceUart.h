/**
 * Miyo - a open software/open hardware ebook - Reader (Firmware)
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

#ifndef INCLUDE_LOGGING_LOGGERUART_H_
#define INCLUDE_LOGGING_LOGGERUART_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "interface/LogDeviceInterface.h"

#include <hal++/interface/UART.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::logging
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class LogDeviceUart : public interface::LogDevice
{
public:

  LogDeviceUart(hal::interface::UART & uart) : _uart{uart} { }
  virtual ~LogDeviceUart() { }

  virtual ssize_t write(uint8_t const * msg, size_t const msg_len) override
  {
    return _uart.transmit(msg, msg_len);
  }

private:

  hal::interface::UART & _uart;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::logging */

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

#define MIYO_LOG_DEVICE_UART_INSTANCE(uart) \
miyo::logging::LogDeviceUart log_device_uart(uart1); \
static miyo::logging::interface::LogDevice & get_log_device_uart() { return log_device_uart; } \
typedef miyo::logging::LoggerBase<get_log_device_uart> Logger;

#endif /* INCLUDE_LOGGING_LOGGERUART_H_ */
