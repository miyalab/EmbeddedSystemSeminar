#define SERVO_PIN 13
#define PWM_CYCLE 20000
#define Tmax 2400
#define Tmin  500
#define Amax 1800

int index = 0;
char recvData[32] = "";
int duty = 500;

void setup() {
  Serial.begin(9600);
  pinMode(SERVO_PIN, OUTPUT);
}

void loop() {
  int angle;
  char key;
  while (Serial.available()) {
    key = Serial.read();
    if (key == '\n') {
      sscanf(recvData, "%d",&angle);
      duty = (Tmax - Tmin)* angle / Amax + Tmin;
      memset(recvData, 0, sizeof(recvData));
      index = 0;
    }
    else {
      recvData[index] = key;
      index++;
    }
  }
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(duty);
  digitalWrite(SERVO_PIN, LOW);
  delayMicroseconds(PWM_CYCLE - duty);

}
