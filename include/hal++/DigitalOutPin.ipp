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
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <GPIO_TypeDef * PORT(), uint32_t PIN, uint32_t MODE, uint32_t PULL, uint32_t SPEED, uint32_t ALTERNATE, void ENABLE_PERIPHERAL_CLOCK()>
void DigitalOutPin<PORT, PIN, MODE, PULL, SPEED, ALTERNATE, ENABLE_PERIPHERAL_CLOCK>::init()
{
  ENABLE_PERIPHERAL_CLOCK();

  GPIO_InitTypeDef gpio_init_structure;

  gpio_init_structure.Pin       = PIN;
  gpio_init_structure.Mode      = MODE;
  gpio_init_structure.Pull      = PULL;
  gpio_init_structure.Speed     = SPEED;
  gpio_init_structure.Alternate = ALTERNATE;

  HAL_GPIO_Init(PORT(), &gpio_init_structure);
}

template <GPIO_TypeDef * PORT(), uint32_t PIN, uint32_t MODE, uint32_t PULL, uint32_t SPEED, uint32_t ALTERNATE, void ENABLE_PERIPHERAL_CLOCK()>
void DigitalOutPin<PORT, PIN, MODE, PULL, SPEED, ALTERNATE, ENABLE_PERIPHERAL_CLOCK>::set()
{
  HAL_GPIO_WritePin(PORT(), PIN, GPIO_PIN_SET);
}

template <GPIO_TypeDef * PORT(), uint32_t PIN, uint32_t MODE, uint32_t PULL, uint32_t SPEED, uint32_t ALTERNATE, void ENABLE_PERIPHERAL_CLOCK()>
void DigitalOutPin<PORT, PIN, MODE, PULL, SPEED, ALTERNATE, ENABLE_PERIPHERAL_CLOCK>::clr()
{
  HAL_GPIO_WritePin(PORT(), PIN, GPIO_PIN_RESET);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */
