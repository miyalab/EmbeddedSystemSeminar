#define ACCELE_X_PIN A1 // 加速度センサ X軸出力ピン
#define ACCELE_Y_PIN A2 // 加速度センサ Y軸出力ピン
#define ACCELE_Z_PIN A3 // 加速度センサ Z軸出力ピン

void setup(){
  Serial.begin(9600);

  // 凡例表示
  Serial.print("ACCELE_X");
  Serial.print(",");
  Serial.print("ACCELE_Y");
  Serial.print(",");
  Serial.print("ACCELE_Z");
  Serial.println();
}

void loop(){
  // 加速度センサの出力値を取得して送信
  Serial.print(analogRead(ACCELE_X_PIN));
  Serial.print(",");
  Serial.print(analogRead(ACCELE_Y_PIN));
  Serial.print(",");
  Serial.print(analogRead(ACCELE_Z_PIN));
  Serial.println();
}
