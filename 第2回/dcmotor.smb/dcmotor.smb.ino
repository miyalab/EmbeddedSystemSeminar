#define MOTOR_RED   11    // DCモータ赤線に対応したピン
#define MOTOR_BLACK 10    // DCモータ黒線に対応したピン

void setup() {
  pinMode(MOTOR_RED, OUTPUT);
  pinMode(MOTOR_BLACK, OUTPUT);
}

void loop() {
  // 正転
  analogWrite(MOTOR_RED, 128);    // duty比 50%
  analogWrite(MOTOR_BLACK, 0);    // duty比  0%
  delay(2000);

  // 反転
  analogWrite(MOTOR_RED, 0);      // duty比  0%
  analogWrite(MOTOR_BLACK, 128);  // duty比 50%
  delay(2000);
}
