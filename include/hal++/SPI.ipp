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
 * CLASS DECLARATION
 **************************************************************************************/

template <SPI_TypeDef * SPI_INSTANCE(), void ENABLE_PERIPHERAL_CLOCK(), uint32_t MODE, uint32_t DIRECTION, uint32_t DATA_SIZE, uint32_t CLK_POLARITY, uint32_t CLK_PHASE, uint32_t BAUD_RATE_PRESCALER, uint32_t FIRST_BIT>
bool SPI<SPI_INSTANCE,
         ENABLE_PERIPHERAL_CLOCK,
         MODE,
         DIRECTION,
         DATA_SIZE,
         CLK_POLARITY,
         CLK_PHASE,
         BAUD_RATE_PRESCALER,
         FIRST_BIT>::init()
{
  _mosi.init();
  _miso.init();
  _sck.init();

  ENABLE_PERIPHERAL_CLOCK();

  _spi_hdl.Instance = SPI_INSTANCE();

  _spi_hdl.Init.Mode              = MODE;
  _spi_hdl.Init.Direction         = DIRECTION;
  _spi_hdl.Init.DataSize          = DATA_SIZE;
  _spi_hdl.Init.CLKPolarity       = CLK_POLARITY;
  _spi_hdl.Init.CLKPhase          = CLK_PHASE;
  _spi_hdl.Init.NSS               = SPI_NSS_SOFT;
  _spi_hdl.Init.BaudRatePrescaler = BAUD_RATE_PRESCALER;
  _spi_hdl.Init.FirstBit          = FIRST_BIT;
  _spi_hdl.Init.TIMode            = SPI_TIMODE_DISABLE;
  _spi_hdl.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
  _spi_hdl.Init.CRCPolynomial     = 1;
  _spi_hdl.Init.CRCLength         = SPI_CRC_LENGTH_DATASIZE;
  _spi_hdl.Init.NSSPMode          = SPI_NSS_PULSE_DISABLE;

  return (HAL_OK == HAL_SPI_Init(&_spi_hdl));
}

template <SPI_TypeDef * SPI_INSTANCE(), void ENABLE_PERIPHERAL_CLOCK(), uint32_t MODE, uint32_t DIRECTION, uint32_t DATA_SIZE, uint32_t CLK_POLARITY, uint32_t CLK_PHASE, uint32_t BAUD_RATE_PRESCALER, uint32_t FIRST_BIT>
ssize_t SPI<SPI_INSTANCE,
            ENABLE_PERIPHERAL_CLOCK,
            MODE,
            DIRECTION,
            DATA_SIZE,
            CLK_POLARITY,
            CLK_PHASE,
            BAUD_RATE_PRESCALER,
            FIRST_BIT>::transfer(uint8_t const * const tx_buf, uint8_t * rx_buf, size_t const tx_buf_size)
{
  if (HAL_OK != HAL_SPI_TransmitReceive(&_spi_hdl, const_cast<uint8_t *>(tx_buf), rx_buf, tx_buf_size, 1000))
    return -1;
  return tx_buf_size;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::hal */
