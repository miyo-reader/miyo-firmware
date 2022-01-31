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

namespace miyo::hal
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <GPIO_TypeDef * PORT(), uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t alternate, void enable_peripheral_clock()>
void DigitalOutPin<PORT, pin, mode, pull, speed, alternate, enable_peripheral_clock>::init()
{
  enable_peripheral_clock();

  GPIO_InitTypeDef gpio_init_structure;

  gpio_init_structure.Pin       = pin;
  gpio_init_structure.Mode      = mode;
  gpio_init_structure.Pull      = pull;
  gpio_init_structure.Speed     = speed;
  gpio_init_structure.Alternate = alternate;

  HAL_GPIO_Init(PORT(), &gpio_init_structure);
}

template <GPIO_TypeDef * PORT(), uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t alternate, void enable_peripheral_clock()>
void DigitalOutPin<PORT, pin, mode, pull, speed, alternate, enable_peripheral_clock>::set()
{
  HAL_GPIO_WritePin(PORT(), pin, GPIO_PIN_SET);
}

template <GPIO_TypeDef * PORT(), uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t alternate, void enable_peripheral_clock()>
void DigitalOutPin<PORT, pin, mode, pull, speed, alternate, enable_peripheral_clock>::clr()
{
  HAL_GPIO_WritePin(PORT(), pin, GPIO_PIN_RESET);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */
