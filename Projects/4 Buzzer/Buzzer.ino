#define BUZZER 12

void setup() {
  
  pinMode(BUZZER, OUTPUT);
  
}

void loop() {
  tone(BUZZER,800);
  delay(200);
  tone(BUZZER,1400);
  delay(200);
  tone(BUZZER,1800);
  delay(200);
  tone(BUZZER,2400);
  delay(200);
  tone(BUZZER,1200);
  delay(200);
   tone(BUZZER,200);
  delay(200);
     tone(BUZZER,100);
  delay(200);
     tone(BUZZER,50);
  delay(200);
     tone(BUZZER,0);
  delay(200);
}
