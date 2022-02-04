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

#include <cstdio>
#include <cstring>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::logging
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<interface::LogDevice & LOG_DEVICE(), size_t LOG_BUFFER_SIZE>
void LoggerBase<LOG_DEVICE, LOG_BUFFER_SIZE>::log(LogLevel const lvl, char const * fmt, ...)
{
  log_level(lvl);

  va_list args;
  va_start(args, fmt);
  log_message(fmt, args);
  va_end(args);

  log_str("\r\n");
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

template<interface::LogDevice & LOG_DEVICE(), size_t LOG_BUFFER_SIZE>
void LoggerBase<LOG_DEVICE, LOG_BUFFER_SIZE>::log_str(char const * str)
{
  LOG_DEVICE().write(reinterpret_cast<uint8_t const *>(str), strlen(str));
}


template<interface::LogDevice & LOG_DEVICE(), size_t LOG_BUFFER_SIZE>
void LoggerBase<LOG_DEVICE, LOG_BUFFER_SIZE>::log_level(LogLevel const lvl)
{
  switch(lvl)
  {
  case LogLevel::Error:   log_str("[E] "); break;
  case LogLevel::Warning: log_str("[W] "); break;
  case LogLevel::Info:    log_str("[I] "); break;
  case LogLevel::Debug:   log_str("[D] "); break;
  case LogLevel::Verbose: log_str("[V] "); break;
  }
}

template<interface::LogDevice & LOG_DEVICE(), size_t LOG_BUFFER_SIZE>
void LoggerBase<LOG_DEVICE, LOG_BUFFER_SIZE>::log_message(char const * fmt, va_list args)
{
  char buf[LOG_BUFFER_SIZE] = {0};
  vsnprintf(buf, LOG_BUFFER_SIZE, fmt, args);
  log_str(buf);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::logging */
