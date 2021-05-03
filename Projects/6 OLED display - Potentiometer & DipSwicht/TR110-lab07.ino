
#include <Wire.h>     // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306
 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64

#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto

int SW1;
int SW3;
int ANALOG;


void setup() {
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
}
 
void loop() {

  SW1=digitalRead(2);
  SW3=digitalRead(3);
  ANALOG=analogRead(A3);
  oled.clearDisplay();      // limpia pantalla
  oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
  
  oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
  oled.setTextSize(1);      // establece tamano de texto en 1
  oled.print("Switch 1: ");  // escribe en pantalla el texto
  
  if(SW1==1)
  {
    oled.print("Activado");  
  }
  else
  {
    oled.print("Desactivado");
  }
  
  
  oled.setCursor (0, 20);    // ubica cursor en coordenas 10,30
  oled.setTextSize(1);      // establece tamano de texto en 2
  oled.print("Switch 2: ");  // escribe en pantalla el texto
  if(SW3)
  {
    oled.print("Activado");  
  }
  else
  {
    oled.print("Desactivado");
  }     // escribe texto

  oled.setCursor (0, 40);    // ubica cursor en coordenas 10,30
  oled.setTextSize(1);      // establece tamano de texto en 2
  oled.print("Potencia: ");  // escribe en pantalla el texto
  int potencia = ANALOG/100;
  oled.print(potencia);      // escribe texto

  oled.setCursor (0, 45);    // ubica cursor en coordenas 10,30
  oled.setTextSize(1); 
  oled.print("-----------");// establece tamano de texto en 2
  switch(potencia)
  {
    case 1:
     oled.setCursor (0, 50);    
    oled.setTextSize(1);      
    oled.print("+");
    break;
    case 2:
     oled.setCursor (0, 50);    
    oled.setTextSize(1);      
    oled.print("++");
    break;
     case 3:
     oled.setCursor (0, 50);    
    oled.setTextSize(1);      
    oled.print("+++");
    break;
     case 4:
     oled.setCursor (0, 50);    
    oled.setTextSize(1);      
    oled.print("++++");
    break;
      case 5:
     oled.setCursor (0, 50);    
    oled.setTextSize(1);      
    oled.print("+++++");
    break;
      case 6:
     oled.setCursor (0, 50);    
    oled.setTextSize(1);      
    oled.print("++++++");
    break;
    case 7:
     oled.setCursor (0, 50);    
    oled.setTextSize(1);      
    oled.print("++++++");
    break;
  }
  
  
  oled.display();     // muestra en pantalla todo lo establecido anteriormente
}
