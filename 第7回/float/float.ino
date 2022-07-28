#define CALC_TIMES 1000

void setup(){
  Serial.begin(9600);
  
  unsigned int startTime;
  unsigned int endTime;

  float a = 12.4141241231;
  float b = 1.24154123312;
  volatile float workf;
  startTime = micros();
  for(int i=0; i < CALC_TIMES; i++){
    workf += a/b;
  }
  endTime = micros();
  Serial.println(endTime - startTime);

  int A = 124141241231;
  int B = 124;
  volatile int worki;
  
  startTime = micros();
  for(int i=0; i < CALC_TIMES; i++){
    worki += A/B;
  }
  endTime = micros();
  Serial.println(endTime - startTime);
}

void loop(){
  
}
