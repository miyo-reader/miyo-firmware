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

#ifndef INCLUDE_HAL_DELAY_H_
#define INCLUDE_HAL_DELAY_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <hal++/interface/Delay.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace miyo::hal
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Delay : public interface::Delay
{
public:

  virtual ~Delay() { }

  virtual void delay(std::chrono::milliseconds const ms) override;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */

#endif /* INCLUDE_HAL_DELAY_H_ */
