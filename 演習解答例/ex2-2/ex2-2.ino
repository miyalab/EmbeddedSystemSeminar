#define LED_PIN     9
#define MOTOR_RED   11
#define MOTOR_BLACK 10

int index = 0;
char recvData[32] = "";

// motor駆動関数
void motor(int duty);

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_RED, OUTPUT);
  pinMode(MOTOR_BLACK, OUTPUT);
}

void loop() {
  char key = 0;
  int led;
  int duty;

  // 受信有無
  while (Serial.available()) {
    key = Serial.read();
    if (key == '\n') {
      sscanf(recvData, "%d %d", &led, &duty);
      digitalWrite(LED_PIN, led);
      motor(duty);
      memset(recvData, 0, sizeof(recvData));
      index = 0;
    }
    else {
      recvData[index] = key;
      index++;
    }
  }
}

// モータ駆動関数
void motor(int duty) {
  if (duty >= 0) {
    analogWrite(MOTOR_RED, duty);
    analogWrite(MOTOR_BLACK, 0);
  }
  else {
    analogWrite(MOTOR_RED, 0);
    analogWrite(MOTOR_BLACK, -duty);
  }
}
