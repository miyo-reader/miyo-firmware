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

#include <driver/IT8951/IT8951_IO.h>

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
    deselect(); \
    return ret; \
  }

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

IT8951_IO::IT8951_IO(hal::interface::SPI & spi,
                     hal::interface::DigitalOutPin & cs,
                     hal::interface::DigitalOutPin & nreset,
                     hal::interface::DigitalInPin & host_ready,
                     hal::interface::Delay & delay)
: _spi{spi}
, _cs{cs}
, _nreset{nreset}
, _host_ready{host_ready}
, _delay{delay}
{ }

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

IT8951::Error IT8951_IO::init()
{
  _cs.init();
  _nreset.init();
  _host_ready.init();
  _spi.init();

  _cs.set();

  using namespace std::chrono_literals;
  _nreset.clr();
  _delay.delay(100ms);
  _nreset.set();
  _delay.delay(100ms);

  return Error::None;
}

IT8951::Error IT8951_IO::read(uint16_t & data)
{
  CHECK_RETURN_VAL(waitForHostReady());
  select();
  CHECK_RETURN_VAL(spi_send(Preamble::Read));
  CHECK_RETURN_VAL(waitForHostReady());
  CHECK_RETURN_VAL(spi_send(0)); /* Dummy Word. */
  CHECK_RETURN_VAL(waitForHostReady());
  CHECK_RETURN_VAL(spi_recv(data));
  deselect();
  return Error::None;
}

IT8951::Error IT8951_IO::read(uint16_t * buf, size_t const num_words)
{
  CHECK_RETURN_VAL(waitForHostReady());
  select();
  CHECK_RETURN_VAL(spi_send(Preamble::Read));
  CHECK_RETURN_VAL(waitForHostReady());
  CHECK_RETURN_VAL(spi_send(0)); /* Dummy Word. */
  CHECK_RETURN_VAL(waitForHostReady());
  for (size_t w = 0; w < num_words; w++)
    CHECK_RETURN_VAL(spi_recv(buf[w]));
  deselect();
  return Error::None;
}

IT8951::Error IT8951_IO::write(uint16_t const data)
{
  CHECK_RETURN_VAL(waitForHostReady());
  select();
  CHECK_RETURN_VAL(spi_send(Preamble::Write));
  CHECK_RETURN_VAL(waitForHostReady());
  CHECK_RETURN_VAL(spi_send(data));
  deselect();
  return Error::None;
}

IT8951::Error IT8951_IO::command(Command const cmd)
{
  CHECK_RETURN_VAL(waitForHostReady());
  select();
  CHECK_RETURN_VAL(spi_send(Preamble::Command));
  CHECK_RETURN_VAL(waitForHostReady());
  CHECK_RETURN_VAL(spi_send(static_cast<uint16_t>(cmd)));
  deselect();
  return Error::None;
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

IT8951::Error IT8951_IO::waitForHostReady()
{
  while (!isHostReady()) { /* TODO: Introduce timeout. */ }
  return Error::None;
}

IT8951::Error IT8951_IO::spi_send(Preamble const preamble)
{
  uint16_t preamble_buf = ntohs(static_cast<uint16_t>(preamble));
  size_t const PREAMBLE_BUF_NUM_WORDS = sizeof(preamble_buf) / 2;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-qualifiers"

  if (PREAMBLE_BUF_NUM_WORDS != _spi.transfer((uint8_t const * const)&preamble_buf, (uint8_t *)&preamble_buf, PREAMBLE_BUF_NUM_WORDS))
    return Error::Spi;
  else
    return Error::None;

#pragma GCC diagnostic pop
}

IT8951::Error IT8951_IO::spi_send(uint16_t const data)
{
  uint16_t const tx_buf = ntohs(data);
  uint16_t       rx_buf = 0;

  size_t const TX_RF_BUF_NUM_WORDS = sizeof(tx_buf) / 2;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-qualifiers"

  if (TX_RF_BUF_NUM_WORDS != _spi.transfer((uint8_t const * const)&tx_buf, (uint8_t *)&rx_buf, TX_RF_BUF_NUM_WORDS))
    return Error::Spi;
  else
    return Error::None;

#pragma GCC diagnostic pop
}

IT8951::Error IT8951_IO::spi_recv(uint16_t & data)
{
  uint16_t const tx_buf = {0};
  uint16_t       rx_buf = {0};

  size_t const TX_RF_BUF_NUM_WORDS = sizeof(tx_buf) / 2;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-qualifiers"

  if (TX_RF_BUF_NUM_WORDS != _spi.transfer((uint8_t const * const)&tx_buf, (uint8_t *)&rx_buf, TX_RF_BUF_NUM_WORDS))
    return Error::Spi;

#pragma GCC diagnostic pop

  data = htons(rx_buf);

  return Error::None;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* miyo::driver::IT8951 */
