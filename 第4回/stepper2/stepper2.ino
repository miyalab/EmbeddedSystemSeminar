#define STPM_Y  11  // ステッパーのA相ピン
#define STPM_R  10  // ステッパーの~A相ピン
#define STPM_B  9   // ステッパーのB相ピン
#define STPM_O  8   // ステッパーの~B相ピン

void setup(){
  pinMode(STPM_Y, OUTPUT);
  pinMode(STPM_R, OUTPUT);
  pinMode(STPM_B, OUTPUT);
  pinMode(STPM_O, OUTPUT);
}

void loop(){
  int wait = 10;      // 待機時間
  // A/B相励磁
  digitalWrite(STPM_Y, HIGH);
  digitalWrite(STPM_R, LOW);
  digitalWrite(STPM_B, HIGH);
  digitalWrite(STPM_O, LOW);
  delay(wait);
  // ~A/B相励磁
  digitalWrite(STPM_Y, LOW);
  digitalWrite(STPM_R, HIGH);
  digitalWrite(STPM_B, HIGH);
  digitalWrite(STPM_O, LOW);
  delay(wait);
  // ~A/B~相励磁
  digitalWrite(STPM_Y, LOW);
  digitalWrite(STPM_R, HIGH);
  digitalWrite(STPM_B, LOW);
  digitalWrite(STPM_O, HIGH);
  delay(wait);
  // A/~B相励磁
  digitalWrite(STPM_Y, HIGH);
  digitalWrite(STPM_R, LOW);
  digitalWrite(STPM_B, LOW);
  digitalWrite(STPM_O, HIGH);
  delay(wait);
}
