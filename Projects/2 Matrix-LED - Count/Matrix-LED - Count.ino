#include "LedControl.h"

LedControl lc = LedControl(11,13,10,1);

byte cero[8] = {
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100

};


byte uno[8]= {        // array que contiene todos los elementos de las
  B00010000,        // filas necesarias por mostrar el digito uno
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};

byte dos[8]= {        // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito dos
  B01000100,
  B00000100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111100
};
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
byte tres[8] = {
  B01111110,
  B00000010,
  B00000010,
  B01111110,
  B00000010,
  B00000010,
  B00000010,
  B01111110

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
    lc.setRow(0,i,cero[i]);

  }

  delay(1000);

  
 
  
  for(int u=0; u<8;u++)
  {
    lc.setRow(0,u,uno[u]);

  }
delay(1000);
  
 
  for(int d=0; d<8; d++)
  {
    lc.setRow(0,d,dos[d]);
  
   
  }
  delay(1000);
   for(int d=0; d<8; d++)
  {
    lc.setRow(0,d,tres[d]);
  
   
  }
  delay(1000);
  

   for(int d=0; d<8; d++)
  {
    lc.setRow(0,d,cuatro[d]);
  
   
  }
  delay(1000);

   for(int d=0; d<8; d++)
  {
    lc.setRow(0,d,cinco[d]);
  
   
  }
  delay(1000);
  


  

}
