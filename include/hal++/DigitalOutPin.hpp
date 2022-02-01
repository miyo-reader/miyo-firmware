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

#ifndef INCLUDE_HAL_DIGITALOUTPIN_HPP_
#define INCLUDE_HAL_DIGITALOUTPIN_HPP_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

#include <hal++/interface/DigitalOutPin.h>

#include <cstdint>

extern "C" {
#include "stm32l4xx_hal.h"
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <GPIO_TypeDef * PORT(), uint32_t PIN, uint32_t MODE, uint32_t PULL, uint32_t SPEED, uint32_t ALTERNATE, void ENABLE_PERIPHERAL_CLOCK()>
class DigitalOutPin : public interface::DigitalOutPin
{
public:

  virtual ~DigitalOutPin() { }

  virtual void init() override;

  virtual void set() override;
  virtual void clr() override;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "DigitalOutPin.ipp"

#endif /* INCLUDE_HAL_DIGITALOUTPIN_HPP_ */
