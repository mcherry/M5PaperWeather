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
  * @file EPDWifi.h
  * 
  * Helper functions for the wifi connection.
  */
#pragma once
#include <ArduinoJson.h>
#include <WiFi.h>
#include "ConfigFile.h"

/* Start and connect to the wifi */
bool StartWiFi(int &rssi) 
{
   IPAddress dns(8, 8, 8, 8); // Google DNS
   
   WiFi.mode(WIFI_STA);
   WiFi.disconnect();
   WiFi.setAutoConnect(true);
   WiFi.setAutoReconnect(true);

   String WifiSSID = WIFI_SSID;
   String WifiPW = WIFI_PW;
   
   if (WifiSSID == "") {
       Serial.println("SSID not defined, using config from SD");
       
       WifiSSID = String(myConfig.wifiSSID);
       WifiPW = String(myConfig.wifiKey);
   }

   Serial.print("Connecting to ");
   Serial.println(WifiSSID);
   delay(100);
   
   WiFi.begin(WifiSSID.c_str(), WifiPW.c_str());

   for (int retry = 0; WiFi.status() != WL_CONNECTED && retry < 30; retry++) {
      delay(500);
      Serial.print(".");
   }

   rssi = 0;
   if (WiFi.status() == WL_CONNECTED) {
      rssi = WiFi.RSSI();
      Serial.print("WiFi connected: ");
      Serial.println(WiFi.localIP().toString());
      return true;
   } else {
      Serial.println("WiFi connection *** FAILED ***");
      return false;
   }
}

/* Stop the wifi connection */
void StopWiFi() 
{
   Serial.println("WiFi disconnected");
   WiFi.disconnect();
   WiFi.mode(WIFI_OFF);
}
