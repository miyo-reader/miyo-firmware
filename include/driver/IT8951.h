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

#ifndef INCLUDE_DRIVER_IT8951_H_
#define INCLUDE_DRIVER_IT8951_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <hal++/interface/SPI.h>
#include <hal++/interface/DigitalInPin.h>
#include <hal++/interface/DigitalOutPin.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::driver
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class IT8951
{
public:

  IT8951(hal::interface::SPI & spi,
         hal::interface::DigitalOutPin & cs,
         hal::interface::DigitalOutPin & nreset,
         hal::interface::DigitalInPin & host_ready);

  enum class Error
  {
    None, TimeoutHostReady, Spi
  };

  enum class Command : uint16_t
  {
    SYS_RUN                        = 0x0001, /* System running, enable all clocks. */
    SLEEP                          = 0x0003, /* Sleep. */
    REG_RD                         = 0x0010, /* Read register. */
    REG_WR                         = 0x0011, /* Write register. */
    MEM_BST_RD_T                   = 0x0012, /* Memory burst read. */
    MEM_BST_RD_S                   = 0x0013, /* Memory burst read start. */
    MEM_BST_WR                     = 0x0014, /* Memory burst write. */
    MEM_BST_END                    = 0x0015, /* Burst access end. */
    LD_IMG                         = 0x0020, /* Load image start. */
    LD_IMG_AREA                    = 0x0021, /* Load image area start. */
    LD_IMG_END                     = 0x0022, /* End load image cycle. */
    /* Only for IT8951. */
    USERDEF_GET_DEVICE_SYSTEM_INFO = 0x0302, /* Get device system info. */
    USERDEF_DISPLAY_AREA           = 0x0034, /* Display image buffer on panel. */
    USERDEF_DISPLAY_BUF_AREA       = 0x0037,
    USERDEF_POWER_ON_OFF           = 0x0038, /* Power ON/OFF sequence. */
    USERDEF_SET_VCOM               = 0x0039, /* Set VCOM value (PMIC platform only). */
    USERDEF_FORCE_SET_TEMPERATURE  = 0x0040, /* Set/get temperature for external temperature sensor. */
  };

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

} /* miyo::driver */

#endif /* INCLUDE_DRIVER_IT8951_H_ */
