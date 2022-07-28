#include <Wire.h>
#include "VL53L0X.h"

VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }

  sensor.startContinuous();
}

void loop()
{
  while (Serial.available()) {
    char key = Serial.read();
    if (key == 'L') {
      int distance = 0;
      do{
        distance = sensor.readRangeContinuousMillimeters();
      }while(!sensor.timeoutOccurred());
      Serial.println(distance);
    }
  }
}
