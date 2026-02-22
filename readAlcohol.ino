/*!
 * @file  readAlcohol.ino
 * @brief Reading Alcohol concentration, A concentration of one part per million (PPM).
 * @n step: we must first determine the iic device address, will dial the code 
 * @n switch A0, A1 (ALCOHOL_ADDRESS_0 for [0 0]), (ALCOHOL_ADDRESS_1 for [1 0]), (ALCOHOL_ADDRESS_2 for [0 1]), (ALCOHOL_ADDRESS_3 for [1 1]).
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author ZhixinLiu(zhixin.liu@dfrobot.com)
 * @version V1.0
 * @date 2020-09-09
 * @url https://github.com/dfrobot/DFRobot_Alcohol
 */

#include "DFRobot_Alcohol.h"

#define COLLECT_NUMBER   5
#define ALCOHOL_I2C_ADDRESS ALCOHOL_ADDRESS_3

/**
 * select i2c device address 
 * ALCOHOL_ADDRESS_0               0x72
 * ALCOHOL_ADDRESS_1               0x73
 * ALCOHOL_ADDRESS_2               0x74
 * ALCOHOL_ADDRESS_3               0x75
 */
DFRobot_Alcohol_I2C Alcohol(&Wire ,ALCOHOL_I2C_ADDRESS);

/*
#ifdef ESP_PLATFORM
  DFRobot_Alcohol_UART Alcohol(&Serial2 ,9600);
#else
  SoftwareSerial mySerial(10 ,11);
  DFRobot_Alcohol_UART Alcohol(&mySerial ,9600);
#endif
*/

void setup() 
{
  Serial.begin(9600);
  while(!Alcohol.begin()){
    Serial.println("NO Deivces !");
    delay(1000);
  }
  Serial.println("Device connected successfully !");

  Alcohol.setModes(MEASURE_MODE_AUTOMATIC);
}

void loop() 
{
  float alcoholConcentration = Alcohol.readAlcoholData(COLLECT_NUMBER);

  if(alcoholConcentration == ERROR){
    Serial.println("Please check the connection !");
  }else{
    Serial.print("Alcohol concentration is ");
    Serial.print(alcoholConcentration);
    Serial.println(" PPM.");

    float estimatedBAC = alcoholConcentration * 0.20;  // 0.40 ppm ≈ 0.08% BAC

    Serial.print("Estimated BAC is ");
    Serial.print(estimatedBAC);
    Serial.println(" %");

    // Machine-readable line for Python
    Serial.print("BAC:");
    Serial.println(estimatedBAC, 3);
  }

  delay(1000);
}
