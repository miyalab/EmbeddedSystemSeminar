#include <Wire.h>
#include "VL53L0X.h"

#define MOTOR_RED   11
#define MOTOR_BLACK 10

VL53L0X sensor;

void setup()
{
  pinMode(MOTOR_RED, OUTPUT);
  pinMode(MOTOR_BLACK, OUTPUT);

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
  int distance = sensor.readRangeContinuousMillimeters();
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }
  else {
    if (distance >= 220) {
      digitalWrite(MOTOR_RED, HIGH);
      digitalWrite(MOTOR_BLACK, LOW);
    }
    else if (distance > 180) {
      digitalWrite(MOTOR_RED, HIGH);
      digitalWrite(MOTOR_BLACK, HIGH);
    }
    else {
      digitalWrite(MOTOR_RED, LOW);
      digitalWrite(MOTOR_BLACK, HIGH);
    }
  }
}
