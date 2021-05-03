#include "LedControl.h" // incluye la libreria

LedControl lc=LedControl(11,13,10,1); // Creacion del objeto


void setup() 
{
  lc.shutdown(0,false); //enciende la matriz
  lc.setIntensity(0,4); // establecer el brillo de 0 a 15
  lc.clearDisplay(0); // blanquea matriz, apaga todos los leds
}

void loop() 
{
  for (int fila=0; fila < 8; fila++)
  {
      for (int columna=0; columna < 8; columna++)
      {
        lc.setLed(0,fila,columna,false);
         delay(100);
         //lc.setLed(0,fila,columna,false);
         //delay(100);
      }    
  }   
  //lc.clearDisplay(0);
}
     
