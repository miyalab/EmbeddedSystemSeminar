#define STPM_Y  11  // ステッパーのA相ピン
#define STPM_R  10  // ステッパーの~A相ピン
#define STPM_B  9   // ステッパーのB相ピン
#define STPM_O  8   // ステッパーの~B相ピン

int index = 0;
char recvData[32] = "";

int wait = 10;
int target = 0;
bool flag = false;
int stpCnt = 0;

void setup() {
  pinMode(STPM_Y, OUTPUT);
  pinMode(STPM_R, OUTPUT);
  pinMode(STPM_B, OUTPUT);
  pinMode(STPM_O, OUTPUT);

  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  // 受信制御
  while (Serial.available()) {
    char key = Serial.read();
    if (key == '\n') {
      sscanf(recvData, "%d %d", &wait, &target);
      flag = true;
      memset(recvData, 0, sizeof(recvData));
      index = 0;
    }
    else {
      recvData[index] = key;
      index++;
    }
  }

  // 以下，ステッピングモータの制御
  if (stpCnt < target) stpCnt++;
  else if (stpCnt > target) stpCnt--;
  else {
    if (flag == true) {
      Serial.println("complete");
      flag = false;
    }
  }
  
  int stp = stpCnt % 4;
  if (stp < 0) stp += 4;
  if (stp % 4 == 0) {
    // A相励磁
    digitalWrite(STPM_Y, HIGH);
    digitalWrite(STPM_R, LOW);
    digitalWrite(STPM_B, HIGH);
    digitalWrite(STPM_O, HIGH);
  }
  else if (stp % 4 == 1) {
    // B相励磁
    digitalWrite(STPM_Y, HIGH);
    digitalWrite(STPM_R, HIGH);
    digitalWrite(STPM_B, HIGH);
    digitalWrite(STPM_O, LOW);
  }
  else if (stp % 4 == 2) {
    // ~A相励磁
    digitalWrite(STPM_Y, LOW);
    digitalWrite(STPM_R, HIGH);
    digitalWrite(STPM_B, HIGH);
    digitalWrite(STPM_O, HIGH);
  }
  else if (stp % 4 == 3) {
    // ~B相励磁
    digitalWrite(STPM_Y, HIGH);
    digitalWrite(STPM_R, HIGH);
    digitalWrite(STPM_B, LOW);
    digitalWrite(STPM_O, HIGH);
  }
  delay(wait);

}
