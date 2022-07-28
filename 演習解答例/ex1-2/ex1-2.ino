#define LED_PIN 9
#define CDS_PIN A0
#define DARK_VAL  800

void setup(){
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  if(analogRead(CDS_PIN) > DARK_VAL){
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }
}
