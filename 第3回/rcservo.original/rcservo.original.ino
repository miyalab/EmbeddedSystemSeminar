#define SERVO_PIN 13      // サーボが接続されているピン
#define PWM_CYCLE 20000   // PWM周期[us]

void setup() {
  pinMode(SERVO_PIN, OUTPUT);
}

void loop() {
  int duty = 500;                      // パルス幅[us]
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(duty);
  digitalWrite(SERVO_PIN, LOW);
  delayMicroseconds(PWM_CYCLE - duty);
}
