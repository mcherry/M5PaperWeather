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
  * @file ConfigFile.h
  * 
  * Loading of JSON configuration from file.
  */
#pragma once

#include <ArduinoJson.h>
#include <SD.h>
#include <SPI.h>

#define NULL_STR "null"
#define CONFIG_BUFFER 512   // Bytes: increase buffer size if you add more stuff to the config

typedef struct {
    char wifiSSID[64];
    char wifiKey[64];
    char city[64];      // need to increase this if you live in Taumatawhakatangihangakoauauotamateaturipukakapikimaungahoronukupokaiwhenuakitanatahu, NZ
    char lat[8];
    char lng[8];
    char units[9];      // string: 'imperial' or 'metric'
    char apiKey[33];
} weatherConfig;

weatherConfig  myConfig;

weatherConfig getConfig(const char *filename) {
    weatherConfig configData;
    StaticJsonDocument<CONFIG_BUFFER> jsonConfig;
    File configFile = SD.open(filename);
    
    DeserializationError error = deserializeJson(jsonConfig, configFile);
    if (error) {
        Serial.println(F("Failed to load config"));
    } else {
        strlcpy(configData.wifiSSID, jsonConfig["ssid"] | NULL_STR, sizeof(configData.wifiSSID));
        strlcpy(configData.wifiKey, jsonConfig["key"] | NULL_STR, sizeof(configData.wifiKey));
        strlcpy(configData.city, jsonConfig["city"] | NULL_STR, sizeof(configData.city));
        strlcpy(configData.lat, jsonConfig["lat"] | NULL_STR, sizeof(configData.lat));
        strlcpy(configData.lng, jsonConfig["lng"] | NULL_STR, sizeof(configData.lng));
        strlcpy(configData.units, jsonConfig["units"] | NULL_STR, sizeof(configData.units));
        strlcpy(configData.apiKey, jsonConfig["apiKey"] | NULL_STR, sizeof(configData.apiKey));

        Serial.print("Loaded ");
        Serial.print(sizeof(configData));
        Serial.println(" bytes");
    }
    
    configFile.close();
    
    return configData;
}
