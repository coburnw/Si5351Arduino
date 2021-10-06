/*
 * si5351.cpp - Si5351 library for Arduino
 *
 * Copyright (C) 2015 - 2019 Jason Milldrum <milldrum@gmail.com>
 *                           Dana H. Myers <k6jq@comcast.net>
 *
 * Some tuning algorithms derived from clk-si5351.c in the Linux kernel.
 * Sebastian Hesselbarth <sebastian.hesselbarth@gmail.com>
 * Rabeeh Khoury <rabeeh@solid-run.com>
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

#include "Arduino.h"
#include "Wire.h"
//#include "I2CInterface.h"

/**
 * The standard Ardiuno way of talking to I2C
 * via the Wire.h library.
 */

class si5351: public Si5351_base {
  Si5351::Si5351(uint8_t chip_addr)
  {
    i2c_bus_addr = chip_addr;
    this->setup()
  }
  
  uint8_t Si5351::check_address(uint8_t i2c_bus_addr)
  {
    Wire.beginTransmission(i2c_bus_addr);
    return Wire.endTransmission();
  }

  uint8_t Si5351::si5351_write_bulk(uint8_t addr, uint8_t bytes, uint8_t *data)
  {
    Wire.beginTransmission(i2c_bus_addr);
    Wire.write(addr);
    for(int i = 0; i < bytes; i++)
      {
	Wire.write(data[i]);
      }
    return Wire.endTransmission();
    //return i2c_interface->write_bulk(i2c_bus_addr, addr, bytes, data);
  }

  uint8_t Si5351::si5351_write(uint8_t addr, uint8_t data)
  {
    Wire.beginTransmission(i2c_bus_addr);
    Wire.write(addr);
    Wire.write(data);
    return Wire.endTransmission();
    //return i2c_interface->write(i2c_bus_addr, addr, data);
  }

  uint8_t Si5351::si5351_read(uint8_t addr)
  {
    uint8_t reg_val = 0;

    Wire.beginTransmission(i2c_bus_addr);
    Wire.write(addr);
    Wire.endTransmission();

    Wire.requestFrom(i2c_bus_addr, (uint8_t)1, (uint8_t)false);

    while(Wire.available())
      {
	reg_val = Wire.read();
      }

    return reg_val;
    //return i2c_interface->read(i2c_bus_addr, addr);
  }
};

