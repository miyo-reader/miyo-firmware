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

  enum class EndianType : uint16_t
  {
    Little = 0,
    Big = 1,
  };
  enum class PixelMode : uint16_t
  {
    Mode_2_BPP = 0,
    Mode_3_BPP = 1,
    Mode_4_BPP = 2,
    Mode_8_BPP = 3,
  };
  enum class RotateMode : uint16_t
  {
    NoRotation = 0,
    Rotate_90  = 1,
    Rotate_180 = 2,
    Rotate_270 = 3,
  };


  std::tuple<Error, DeviceInfo> getDeviceInfo();
  Error                         setImageBufferBaseAddr(uint32_t const img_buf_base_addr);
  Error                         loadImageAreaStart(EndianType const endian_type,
                                                   PixelMode const pixel_mode,
                                                   RotateMode const rotate_mode,
                                                   uint16_t const x_start,
                                                   uint16_t const y_start,
                                                   uint16_t const width,
                                                   uint16_t const height);
  Error                         loadImage(uint8_t const * img, size_t const num_bytes);
  Error                         loadImageEnd();


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
