/*
   Copyright (C) 2022 Mike Cherry <mcherry@inditech.org>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
  * @file EPDSD.h
  * 
  * Helper functions for SD access
  */
#pragma once

#include <ArduinoJson.h>
#include <SD.h>
#include <SPI.h>

bool StartSD() {
  bool retVal = false;
  
  Serial.print("Initializing SD card ... ");
  if (!SD.begin(4)) {
    Serial.println("*** FAILED ***");
  } else {
    Serial.println("complete");
    retVal = true;
  }

  return retVal;
}
