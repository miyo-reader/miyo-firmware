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

#ifndef INCLUDE_DRIVER_IT8951_CONST_H_
#define INCLUDE_DRIVER_IT8951_CONST_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdint>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::driver::IT8951
{

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static uint16_t constexpr MCSR_BASE_ADDR = 0x0200;
static uint16_t constexpr LISAR          = (MCSR_BASE_ADDR + 0x0008);

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

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

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::driver::IT8951 */

#endif /* INCLUDE_DRIVER_IT8951_CONST_H_ */
