#include <Servo.h>

#define CDS_PIN   A0
#define SERVO_PIN 13
#define DARK_VAL  800

Servo servo;

void setup() {
  servo.attach(SERVO_PIN, 500, 2400);
}

void loop() {
  if (analogRead(CDS_PIN) > DARK_VAL) {
    servo.write(0);
  }
  else{
    servo.write(90);
  }
}
