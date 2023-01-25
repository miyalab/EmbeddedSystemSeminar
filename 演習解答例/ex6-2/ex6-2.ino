#define ACCELE_X_PIN A1 // 加速度センサ X軸出力ピン
#define ACCELE_Y_PIN A2 // 加速度センサ Y軸出力ピン
#define ACCELE_Z_PIN A3 // 加速度センサ Z軸出力ピン

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    while(Serial.available()){
        char key = Serial.read();
        if(key == 'V'){
            Serial.print(9.80665 * (5.0 * analogRead(ACCELE_X_PIN) / 1023 - 2.5));
            Serial.print(" ");
            Serial.print(9.80665 * (5.0 * analogRead(ACCELE_Y_PIN) / 1023 - 2.5));
            Serial.print(" ");
            Serial.println(9.80665 * (5.0 * analogRead(ACCELE_Z_PIN) / 1023 - 2.5));
        }
    }
}