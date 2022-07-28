#define LED_PIN 9

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  char receiveData;
  // 受信文字があるときループ
  while(Serial.available()){
    // 受信データ 1文字読み込み
    receiveData = Serial.read();
    if(receiveData == 'a'){
      digitalWrite(LED_PIN, LOW);
    }
    else if(receiveData == 'b') {
      digitalWrite(LED_PIN, HIGH);
    }
  }
}
