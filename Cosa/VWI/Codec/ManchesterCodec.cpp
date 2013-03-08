/**
 * @file Cosa/VWI/Codec/ManchesterCodec.cpp
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2013, Mikael Patel (Cosa C++ port and refactoring)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 *
 * @section Description
 * Manchester Phase 4-to-8 bit codec for the Cosa VWI (Virtual Wire
 * Interface). 
 *
 * This file is part of the Arduino Che Cosa project.
 */

#include "Cosa/VWI/Codec/ManchesterCodec.hh"

// Manchester encoder table 4 to 8 bits. In binary to show how it works
const uint8_t 
ManchesterCodec::symbols[] PROGMEM = {
  0b10101010,
  0b10101001,
  0b10100110,
  0b10100101,
  0b10011010,
  0b10011001,
  0b10010110,
  0b10010101,
  0b01101010,
  0b01101001,
  0b01100110,
  0b01100101,
  0b01011010,
  0b01011001,
  0b01010110,
  0b01010101
};

uint8_t 
ManchesterCodec::decode4(uint8_t symbol)
{
  uint8_t res = 0;
  if (symbol & 1) res |= 1;
  if (symbol & 4) res |= 2;
  if (symbol & 16) res |= 4;
  if (symbol & 64) res |= 8;
  return (res);
}

// Ethernet frame header; preamble and delimiter
const uint8_t 
ManchesterCodec::header[] PROGMEM = {
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x5d
};

