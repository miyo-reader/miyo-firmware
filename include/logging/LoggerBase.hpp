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

#ifndef INCLUDE_LOGGING_LOGGERBASE_H_
#define INCLUDE_LOGGING_LOGGERBASE_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdarg>

#include "interface/LogDeviceInterface.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::logging
{

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

#ifdef DBG_ENABLE_ERROR
#  define DBG_ERROR(fmt, ...) Logger::instance().log(miyo::logging::LogLevel::Error, fmt, ## __VA_ARGS__)
#else
#  define DBG_ERROR(fmt, ...)
#endif

#ifdef DBG_ENABLE_WARNING
#  define DBG_WARNING(fmt, ...) Logger::instance().log(miyo::logging::LogLevel::Warning, fmt, ## __VA_ARGS__)
#else
#  define DBG_WARNING(fmt, ...)
#endif

#ifdef DBG_ENABLE_INFO
#  define DBG_INFO(fmt, ...) Logger::instance().log(miyo::logging::LogLevel::Info, fmt, ## __VA_ARGS__)
#else
#  define DBG_INFO(fmt, ...)
#endif

#ifdef DBG_ENABLE_DEBUG
#  define DBG_DEBUG(fmt, ...) Logger::instance().log(miyo::logging::LogLevel::Debug, fmt, ## __VA_ARGS__)
#else
#  define DBG_DEBUG(fmt, ...)
#endif

#ifdef DBG_ENABLE_VERBOSE
#  define DBG_VERBOSE(fmt, ...) Logger::instance().log(miyo::logging::LogLevel::Verbose, fmt, ## __VA_ARGS__)
#else
#  define DBG_VERBOSE(fmt, ...)
#endif

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

enum class LogLevel
{
  Error, Warning, Info, Debug, Verbose
};

/**************************************************************************************
 * CONSTANT
 **************************************************************************************/

static constexpr size_t DEFAULT_LOG_BUFFER_SIZE = 160;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<interface::LogDevice & LOG_DEVICE(), size_t LOG_BUFFER_SIZE = DEFAULT_LOG_BUFFER_SIZE>
class LoggerBase
{
public:

  static LoggerBase & instance();

  void log(LogLevel const lvl, char const * fmt, ...);
  void log(LogLevel const lvl, char const * fmt, va_list args);

  void operator = (LoggerBase &) = delete;

private:

  void log_str    (char const * str);
  void log_level  (LogLevel const lvl);
  void log_message(char const * fmt, va_list args);

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::logging */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "LoggerBase.ipp"

#endif /* INCLUDE_LOGGING_LOGGERBASE_H_ */
