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
 * NAMESPACE
 **************************************************************************************/

#include <hal++/DigitalOutPin.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

DigitalOutPin::DigitalOutPin(GPIO_TypeDef * type,
                             uint32_t const pin,
                             uint32_t const mode,
                             uint32_t const pull,
                             uint32_t const speed,
                             uint32_t const alternate,
                             std::function<void()> const enable_peripheral_clock)
: _type{type}
, _pin{pin}
, _mode{mode}
, _pull{pull}
, _speed{speed}
, _alternate{alternate}
, _enable_peripheral_clock{enable_peripheral_clock}
{

}

DigitalOutPin::~DigitalOutPin()
{
  HAL_GPIO_DeInit(_type, _pin);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void DigitalOutPin::init()
{
  _enable_peripheral_clock();

  GPIO_InitTypeDef gpio_init_structure;

  gpio_init_structure.Pin       = _pin;
  gpio_init_structure.Mode      = _mode;
  gpio_init_structure.Pull      = _pull;
  gpio_init_structure.Speed     = _speed;
  gpio_init_structure.Alternate = _alternate;

  HAL_GPIO_Init(_type, &gpio_init_structure);
}

void DigitalOutPin::set()
{
  HAL_GPIO_WritePin(_type, _pin, GPIO_PIN_SET);
}

void DigitalOutPin::clr()
{
  HAL_GPIO_WritePin(_type, _pin, GPIO_PIN_RESET);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */
