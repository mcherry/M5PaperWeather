
## M5PaperWeather
  **M5Paper project with weather information from openweathermap ***

   ![M5PaperWeather](images/M5PaperWeather.png "M5Paper")


### Description
  This project is a fork from https://github.com/Bastelschlumpf/M5PaperWeather

  Arduino project to show internal environment data and weather information from 
  openweathermap https://openweathermap.org on the e-ink display of the M5Paper.
  Please edit the config.h file with your own data or modify config.json and place on a SD card 
in the device..
  You need an api key from openweathermap.
  The software shows the following information:
  * A header with version, city wifi strength and battery status
  * Sun section with sunrise and sunset 
  * Moon section with moonrise and moonset
  * Wind section with wind direction and wind speed
  * The internal SH30 sensor data (temperature and humidity) with the current date and time
  * A hourly forecast with hour, temperature and a weather icon.
  * Some detailt forecast graphs with temperature, rain, humidity and pressure

### Disclaimer
   I don't take any responsibility nor liability for using this software nor for the 
   installation or any tips, advice, videos, etc. given by any member of this site or any related site.

### License
   This program is licensed under GPL-3.0

### Thanks
   * https://www.arduino.cc
     *Thanks to the Arduino community with all its incredible possibilities and support.** 
   * Special thanks for the drawing function of the moon and the wind section from David Bird
     https://github.com/G6EJD/ESP32-Revised-Weather-Display-42-E-Paper
