#define CDS_PIN A0              // Cdsセルが接続されているピン番号

// 起動後に一度だけ実行される関数
void setup() {
  Serial.begin(9600);
}

// ずっと繰り返される関数
void loop() {
  Serial.println(analogRead(CDS_PIN));  // Cdsセルの出力値を送信
  delay(1000);
}
