#define PWM_PERIOD  1000  // PWM周期

#define MOTOR_RED   11    // DCモータ赤線に対応したピン
#define MOTOR_BLACK 10    // DCモータ黒線に対応したピン

void setup() {
  pinMode(MOTOR_RED, OUTPUT);
  pinMode(MOTOR_BLACK, OUTPUT);
}

void loop() {
  int duty = 500;
  digitalWrite(MOTOR_RED, HIGH);
  digitalWrite(MOTOR_BLACK, LOW);
  delayMicroseconds(duty);              // 赤線のON時間
  digitalWrite(MOTOR_RED, LOW);
  digitalWrite(MOTOR_BLACK, HIGH);
  delayMicroseconds(PWM_PERIOD - duty); // 黒線のON時間
}
