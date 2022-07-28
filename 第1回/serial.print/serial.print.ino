// 起動後に一度だけ実行される関数
void setup() {
  Serial.begin(9600);             // シリアル通信開始(baudrate:9600)
}

// ずっと繰り返される関数
void loop() {
  Serial.print("Hello ");
  Serial.println("Arduino");
  delay(1000);
}
