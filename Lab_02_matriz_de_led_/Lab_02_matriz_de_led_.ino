#include "LedControl.h" // incluye la libreria

LedControl lc=LedControl(11,13,10,1); // Creacion del objeto


void setup() 
{
  lc.shutdown(0,false); //enciende la matriz
  lc.setIntensity(0,2); // establecer el brillo de 0 a 15
  lc.clearDisplay(0); // blanquea matriz, apaga todos los leds
}

void loop() 
{
  for (int fila=0; fila < 5; fila++)
  {
      for (int columna=0; columna < 5; columna++)
      {
         lc.setLed(0,fila,columna,true);
         delay(500);
         //lc.setLed(0,fila,columna,false);
         //delay(100);
      }    
  }

   for (int fila=4; fila >= 0; fila--)
  {
      for (int columna=4; columna >= 0; columna--)
      {
         lc.setLed(0,fila,columna,false);
         delay(500);
         //lc.setLed(0,fila,columna,false);
         //delay(100);
      }    
  }   
  //lc.clearDisplay(0);
}
