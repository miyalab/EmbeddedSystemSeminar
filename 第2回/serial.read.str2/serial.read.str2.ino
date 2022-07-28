int recvIndex = 0;          // 受信データ格納インデックス
char recvData[32] = "";     // 受信データ格納用

void setup() {
  Serial.begin(9600);
}

void loop() {
  int a, b, c;
  
  // 受信文字があるときループ
  while(Serial.available()){
    // 受信データ取得
    char key = Serial.read();

    // 改行文字受信
    if(key == '\n'){
      // 受信データを数値に変換
      sscanf(recvData, "%d %d %d", &a, &b, &c);
      Serial.println(a+b+c);
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
