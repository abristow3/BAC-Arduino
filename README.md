# BAC-Arduino
Arduino code to read BAC sensor data via i2c and publish it via serial port.

readAlcohol.ino reads alcohol concentration in PPM using a DFRobot Alcohol sensor over I2C. Select the sensor address via A0 and A1 pins (ALCOHOL_ADDRESS_0–ALCOHOL_ADDRESS_3). The sketch prints alcohol concentration and estimated BAC to Serial. Requires the DFRobot_Alcohol library. MIT license. Author: Zhixin Liu. Source: https://github.com/dfrobot/DFRobot_Alcohol
