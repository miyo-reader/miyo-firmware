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

#include <driver/IT8951/IT8951_IO.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::driver::IT8951
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef struct __attribute__((packed, aligned(4)))
{
  uint16_t panel_width;
  uint16_t panel_height;
  uint16_t img_buf_address_low;
  uint16_t img_buf_address_high;
  uint8_t  fw_version[16];
  uint8_t  lut_version[16];
} DeviceInfo;
static_assert(sizeof(DeviceInfo) == 40);

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class IT8951
{
public:

  IT8951(IT8951_IO & io);


  Error getDeviceInfo(DeviceInfo & dev_info);
  Error setImageBufferBaseAddr(uint32_t const img_buf_base_addr);

  std::tuple<Error, uint16_t> readRegister (uint16_t const reg_addr);
  Error                       writeRegister(uint16_t const reg_addr, uint16_t const reg_val);

private:

  IT8951_IO & _io;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::driver::IT8951 */

#endif /* INCLUDE_DRIVER_IT8951_H_ */
