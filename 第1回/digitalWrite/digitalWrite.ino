#define LED_PIN 9               // LEDが接続されているピン番号

// 起動後に一度だけ実行される関数
void setup() {
  pinMode(LED_PIN, OUTPUT);     // LEDが接続されている端子を出力に設定
}

// ずっと繰り返される関数
void loop() {
  digitalWrite(LED_PIN, HIGH);  // LEDが接続されている端子をHIGH出力
  delay(1000);                  // 1000[ms]待機
  digitalWrite(LED_PIN, LOW);   // LEDが接続されている端子をLOW出力
  delay(1000);                  // 1000[ms]待機
}
