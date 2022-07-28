#define STPM_Y  11  // ステッパーのA相ピン
#define STPM_R  10  // ステッパーの~A相ピン
#define STPM_B  6   // ステッパーのB相ピン
#define STPM_O  5   // ステッパーの~B相ピン

#define PUSH_PIN 4  // ボタンが接続されているピン番号

int cnt = 0;
bool flag = false;
int stpCnt = 0;

void setup() {
  pinMode(STPM_Y, OUTPUT);
  pinMode(STPM_R, OUTPUT);
  pinMode(STPM_B, OUTPUT);
  pinMode(STPM_O, OUTPUT);

  pinMode(PUSH_PIN, INPUT);
}

void loop() {
  int wait = 10;      // 待機時間

  if (digitalRead(PUSH_PIN) == LOW && flag == false) {
    flag = true;
  }
  else if (digitalRead(PUSH_PIN) == HIGH && flag == true) {
    cnt++;
    flag = false;
  }

  if (stpCnt == cnt * 50) {
    digitalWrite(STPM_Y, HIGH);
    digitalWrite(STPM_R, HIGH);
    digitalWrite(STPM_B, HIGH);
    digitalWrite(STPM_O, HIGH);
  }
  else {
    if (stpCnt % 4 == 0) {
      // A相励磁
      digitalWrite(STPM_Y, HIGH);
      digitalWrite(STPM_R, LOW);
      digitalWrite(STPM_B, HIGH);
      digitalWrite(STPM_O, HIGH);
    }
    else if (stpCnt % 4 == 1) {
      // B相励磁
      digitalWrite(STPM_Y, HIGH);
      digitalWrite(STPM_R, HIGH);
      digitalWrite(STPM_B, HIGH);
      digitalWrite(STPM_O, LOW);
    }
    else if (stpCnt % 4 == 2) {
      // ~A相励磁
      digitalWrite(STPM_Y, LOW);
      digitalWrite(STPM_R, HIGH);
      digitalWrite(STPM_B, HIGH);
      digitalWrite(STPM_O, HIGH);
    }
    else if (stpCnt % 4 == 3) {
      // ~B相励磁
      digitalWrite(STPM_Y, HIGH);
      digitalWrite(STPM_R, HIGH);
      digitalWrite(STPM_B, LOW);
      digitalWrite(STPM_O, HIGH);
    }
    stpCnt++;
  }
  delay(wait);
}
