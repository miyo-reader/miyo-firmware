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

#ifndef INCLUDE_HAL_DIGITALOUTPIN_H_
#define INCLUDE_HAL_DIGITALOUTPIN_H_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

#include <hal++/interface/DigitalOutPin.h>

#include <cstdint>

#include <functional>

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

class DigitalOutPin : public interface::DigitalOutPin
{

public:

  DigitalOutPin(GPIO_TypeDef * type,
                uint32_t const pin,
                uint32_t const mode,
                uint32_t const pull,
                uint32_t const speed,
                uint32_t const alternate,
                std::function<void()> const enable_peripheral_clock);
  virtual ~DigitalOutPin();


  virtual void set() override;
  virtual void clr() override;


private:

  GPIO_TypeDef * _type;
  uint32_t _pin;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */

#endif /* INCLUDE_HAL_DIGITALOUTPIN_H_ */
