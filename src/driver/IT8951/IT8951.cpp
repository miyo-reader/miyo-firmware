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

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <driver/IT8951/IT8951.h>

#include <cstring>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::driver::IT8951
{

/**************************************************************************************
 * DEFINE
 **************************************************************************************/

#define CHECK_RETURN_VAL(expr) \
  if (auto ret = (expr); ret != Error::None) { \
    return ret; \
  }

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

IT8951::IT8951(IT8951_IO & io)
: _io{io}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

std::tuple<Error, DeviceInfo> IT8951::getDeviceInfo()
{
  DeviceInfo dev_info;
  memset(&dev_info, 0, sizeof(DeviceInfo));

#define CHECK_RETURN_VAL_GET_DEVICE_INFO(expr) \
  if (auto ret = (expr); ret != Error::None) { \
    return std::tuple(ret, dev_info); \
  }

  CHECK_RETURN_VAL_GET_DEVICE_INFO(_io.command(Command::USERDEF_GET_DEVICE_SYSTEM_INFO));
  CHECK_RETURN_VAL_GET_DEVICE_INFO(_io.read(reinterpret_cast<uint16_t *>(&dev_info), sizeof(DeviceInfo) / 2));

  return std::tuple(Error::None, dev_info);
}

Error IT8951::setImageBufferBaseAddr(uint32_t const img_buf_base_addr)
{
  uint16_t const reg_val_high = static_cast<uint16_t>((img_buf_base_addr >> 16) & 0x0000FFFF);
  uint16_t const reg_val_low  = static_cast<uint16_t>((img_buf_base_addr >>  0) & 0x0000FFFF);

  CHECK_RETURN_VAL(writeRegister(LISAR + 2, reg_val_high));
  CHECK_RETURN_VAL(writeRegister(LISAR + 0, reg_val_low));
  return Error::None;
}

std::tuple<Error, uint16_t> IT8951::readRegister(uint16_t const reg_addr)
{
  uint16_t reg_val = 0;

#define CHECK_RETURN_VAL_READ_REGISTER(expr) \
  if (auto ret = (expr); ret != Error::None) { \
    return std::tuple(ret, reg_val); \
  }

  CHECK_RETURN_VAL_READ_REGISTER(_io.command(Command::REG_RD));
  CHECK_RETURN_VAL_READ_REGISTER(_io.write(reg_addr));
  CHECK_RETURN_VAL_READ_REGISTER(_io.read(reg_val));

  return std::tuple(Error::None, reg_val);
}

Error IT8951::writeRegister(uint16_t const reg_addr, uint16_t const reg_val)
{
  CHECK_RETURN_VAL(_io.command(Command::REG_WR));
  CHECK_RETURN_VAL(_io.write(reg_addr));
  CHECK_RETURN_VAL(_io.write(reg_val));
  return Error::None;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::driver::IT8951 */
