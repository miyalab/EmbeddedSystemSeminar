#include <Servo.h>

#define SERVO_PIN 13    // サーボに接続されているピン

Servo servo;            // サーボ型の宣言

void setup(){
  // サーボピンをサーボとして登録
  servo.attach(SERVO_PIN, 500, 2400);
}

void loop(){
  servo.write(0);     // 0度
  delay(2000);
  servo.write(90);    // 90度
  delay(2000);
  servo.write(180);   // 180度
  delay(2000);
}
