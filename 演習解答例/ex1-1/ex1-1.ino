#define PUSH_PIN 4

int cnt = 0;
bool flag = false;

void setup(){
  Serial.begin(9600);
  
  pinMode(PUSH_PIN, INPUT);
}

void loop(){
  if(digitalRead(PUSH_PIN) == LOW && flag == false){
    flag = true;
  }
  else if(digitalRead(PUSH_PIN) == HIGH && flag == true){
    cnt++;
    flag = false;
    Serial.println(cnt);
  }
  delay(10);
}
