/*
   Copyright (C) 2021 SFini

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
  * @file Config.h
  * 
  * Configuration information. Blank or 0 values will cause config
  * to be loaded from config.json on SD card
  */
#pragma once

#define VERSION          "Version 1.1"
#define CITY_NAME        ""

// change to your location
#define LATITUDE         0
#define LONGITUDE        0
#define UNITS            ""

#define OPENWEATHER_SRV  "api.openweathermap.org"
#define OPENWEATHER_PORT 80
#define OPENWEATHER_API  ""

#define WIFI_SSID        ""
#define WIFI_PW          ""
