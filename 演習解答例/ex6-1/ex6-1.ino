#define ACCELE_X_PIN A1 // 加速度センサ X軸出力ピン
#define ACCELE_Y_PIN A2 // 加速度センサ Y軸出力ピン
#define ACCELE_Z_PIN A3 // 加速度センサ Z軸出力ピン
#define PUSH_PIN     4  // タクトスイッチピン
#define MOTOR_RED    11
#define MOTOR_BLACK  10

int motorFlag = 0;
int fallFlag = 0;
unsigned long startTime;

void setup()
{
    pinMode(PUSH_PIN, INPUT);
    pinMode(MOTOR_RED,   OUTPUT);
    pinMode(MOTOR_BLACK, OUTPUT);
    analogWrite(MOTOR_BLACK, 0);        // HDDは一方向にしか回転しないため固定
}

void loop()
{
    // ボタンを押すとモータ回転
    if(digitalRead(PUSH_PIN) == LOW) motorFlag = 1;

    // 落下検出
    unsigned long time = millis();
    if(anaglogRead(ACCELE_Z_PIN) < 250) {
        startTime = time;
        fallFlag = 1;
    }
    else if(analogRead(ACCELE_Z_PIN) > 750){
        fallFlag = 0;
    }
    // 1000ms -> 1s以上落下
    if(fallFlag * time - startTime > 1000){
        fallFlag = motorFlag = 0;
    }

    // 演算によるモータ制御
    analogWrite(MOTOR_RED, motorFlag * 255);
}