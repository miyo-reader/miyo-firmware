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

#ifndef INCLUDE_HAL_INTERFACE_DIGITALOUTPIN_H_
#define INCLUDE_HAL_INTERFACE_DIGITALOUTPIN_H_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal::interface
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class DigitalOutPin
{

public:

  virtual ~DigitalOutPin() { }

  virtual void init() = 0;

  virtual void set() = 0;
  virtual void clr() = 0;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal::interface */

#endif /* INCLUDE_HAL_INTERFACE_DIGITALOUTPIN_H_ */
