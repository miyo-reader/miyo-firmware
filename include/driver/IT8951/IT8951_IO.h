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

#ifndef INCLUDE_DRIVER_IT8951_H_
#define INCLUDE_DRIVER_IT8951_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <functional>

#include <hal++/interface/SPI.h>
#include <hal++/interface/DigitalInPin.h>
#include <hal++/interface/DigitalOutPin.h>

#include "IT8951_Const.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::driver::IT8951
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<void(uint32_t const)> DelayFuncMs;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class IT8951_IO
{
public:

  IT8951_IO(hal::interface::SPI & spi,
            hal::interface::DigitalOutPin & cs,
            hal::interface::DigitalOutPin & nreset,
            hal::interface::DigitalInPin & host_ready,
            DelayFuncMs const delay_func);


  Error init   ();

  Error read   (uint16_t & data);
  Error write  (uint16_t const data);
  Error command(Command const cmd);


#ifdef __HOST_LITTLE_ENDIAN__
  constexpr uint16_t ntohs(uint16_t const val) { return __builtin_bswap16(val); }
  constexpr uint16_t htons(uint16_t const val) { return __builtin_bswap16(val); }
#else
  constexpr uint16_t ntohs(uint16_t const val) { return val; }
  constexpr uint16_t htons(uint16_t const val) { return val; }
#endif

private:

  hal::interface::SPI & _spi;
  hal::interface::DigitalOutPin & _cs;
  hal::interface::DigitalOutPin & _nreset;
  hal::interface::DigitalInPin & _host_ready;
  DelayFuncMs const _delay_func;

  enum class Preamble : uint16_t
  {
    Command = 0x6000,
    Write   = 0x0000,
    Read    = 0x1000,
  };

  Error waitForHostReady();
  Error spi_send(Preamble const preamble);
  Error spi_send(uint16_t const data);
  Error spi_recv(uint16_t & data);
  

  inline bool isHostReady() { return _host_ready.isSet(); }
  inline void select()      { _cs.clr(); }
  inline void deselect()    { _cs.set(); }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::driver::IT8951 */

#endif /* INCLUDE_DRIVER_IT8951_H_ */
