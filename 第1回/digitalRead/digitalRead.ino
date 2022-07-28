#define PUSH_PIN 4              // ボタンが接続されているピン番号
#define LED_PIN  9              // LEDが接続されているピン番号

// 起動後に一度だけ実行される関数
void setup() {
  pinMode(PUSH_PIN, INPUT);     // ボタンが接続されている端子を入力に設定
  pinMode(LED_PIN, OUTPUT);     // LEDが接続されている端子を出力に設定
}

// ずっと繰り返される関数
void loop() {
  // ボタン入力がLOWのとき
  if(digitalRead(PUSH_PIN) == LOW){
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }
}
