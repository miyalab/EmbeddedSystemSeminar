#define MOTOR_RED 11
#define MOTOR_BLACK 10

int phase = 0;
char key = 0;
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
  int duty;

  // 受信有無
  while (Serial.available()) {
    key = Serial.read();
    if (key == '\n') {
      switch (phase) {
        case 0:
          if (strcmp(recvData, "CW") == 0) phase = 1;
          else if (strcmp(recvData, "CCW") == 0) phase = -1;
          break;

        case -1:
        case 1:
          sscanf(recvData, "%d", &duty);
          motor(phase * duty);
          phase = 0;
          break;
      }
      // 受信データ初期化
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
