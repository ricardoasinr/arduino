#include "LedControl.h"

LedControl lc = LedControl(11,13,10,1);

byte cuatro[8] = {
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B00000010,
  B00000010,
  B00000010,
  B00000010

};

byte cinco[8]= {        // array que contiene todos los elementos de las
  B01111110,
  B01000000,
  B01000000,
  B01111110,
  B00000010,
  B00000010,
  B00000010,
  B01111110
};

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0,false);
  lc.setIntensity(0,10); 
  lc.clearDisplay(0);
}

void loop() {
  
  for(int i=0; i<8; i++)
  {
    lc.setRow(0,i,cuatro[i]);
  }

  delay(1000);

  for(int u=0; u<8;u++)
  {
    lc.setRow(0,u,cinco[u]);
  }
delay(1000);

}
