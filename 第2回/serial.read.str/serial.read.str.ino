#define LED_PIN 4           // LEDピン

int phase = 0;              // 受信データ判定用
int recvIndex = 0;          // 受信データ格納インデックス
char recvData[32] = "";     // 受信データ格納用

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // 受信文字があるときループ
  while(Serial.available()){
    // 受信データ取得
    char key = Serial.read();

    // 改行文字受信
    if(key == '\n'){
      switch(phase){
      case 0:  // コマンド取得;
         if(strcmp(recvData, "LED") == 0) phase = 1;  // 次の文字列はLED制御コード
         break;

      case 1:  // LED制御コード取得
        if(strcmp(recvData, "ON") == 0) digitalWrite(LED_PIN, LOW);
        if(strcmp(recvData, "OFF") == 0) digitalWrite(LED_PIN, HIGH);
        phase = 0;                                    // コマンド取得に戻す
      }

      // 受信データ初期化
      memset(recvData, 0, sizeof(recvData));
      recvIndex = 0;
    }
    else{
      // 受信データ保存
      recvData[recvIndex] = key;
      recvIndex++;              // 次の受信データは次の要素
    }
  }
}
