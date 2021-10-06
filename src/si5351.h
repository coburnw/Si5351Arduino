/*
 * si5351.h - Si5351 library for Arduino
 *
 * Copyright (C) 2015 - 2019 Jason Milldrum <milldrum@gmail.com>
 *                           Dana H. Myers <k6jq@comcast.net>
 *
 * Many defines derived from clk-si5351.h in the Linux kernel.
 * Sebastian Hesselbarth <sebastian.hesselbarth@gmail.com>
 * Rabeeh Khoury <rabeeh@solid-run.com>
 *
 * do_div() macro derived from /include/asm-generic/div64.h in
 * the Linux kernel.
 * Copyright (C) 2003 Bernardo Innocenti <bernie@develer.com>
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SI5351_H_
#define SI5351_H_

#include <stdint.h>

#include "si5351_base.h"

/* Define definitions */

class Si5351
{
public:

  /**
   * Use this constructor when using the (default) Arduino
   * I2C interface.
   */
  Si5351(uint8_t i2c_addr = SI5351_BUS_BASE_ADDR);

  uint8_t check_address(uint8_t);
  uint8_t si5351_write_bulk(uint8_t, uint8_t, uint8_t *);
  uint8_t si5351_write(uint8_t, uint8_t);
  uint8_t si5351_read(uint8_t);

private:
  uint8_t i2c_bus_addr;
};

#endif /* SI5351_H_ */
