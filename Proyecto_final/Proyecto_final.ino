#include <Wire.h>
#include "MAX30105.h"
#include <Adafruit_GFX.h>   
#include <Adafruit_SSD1306.h>
#include "heartRate.h"
#include <Keypad.h> 

#define BUZZER 1
#define ANCHO 128     
#define ALTO 32       
#define OLED_RESET 4      


MAX30105 particleSensor;
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);



const byte FILAS=4;
const byte COLUMNAS=4;
byte pinesFilas[FILAS]= {9,8,7,6};
byte pinesColumnas[COLUMNAS]= {5,4,3,2};

long lastBeat = 0; 
float beatsPerMinute;
int beatAvg;
char TECLA;
int inicio=0;
int opciones =0;
char keys[FILAS][COLUMNAS]= {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing...");
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  //Dectecta el sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Utiliza el puerto 12C, a una velocidad de 400kHz speed
  {
    Serial.println("El sensor MAX30102 no fue encontrado");
  }
  //Serial.println("Por favor coloque su dedo en el sensor");

  pinMode(BUZZER, OUTPUT);
  particleSensor.setup(); //Carga la configuración por defecto del sensor.
  particleSensor.setPulseAmplitudeRed(0x0A); //Enciende el led rojo del sensor para verificar si esta funcionando.
  particleSensor.setPulseAmplitudeGreen(0); //Apaga el led verde en caso que el sensor cuente con este led.
  
}

void loop()
{

      //Texto de bienvenida 
      TECLA= teclado.getKey();
      if(TECLA=='1')
        {
          inicio=1;
        }
      if(TECLA=='*')
        {
          inicio=0;
        }
     if(TECLA=='2')
          {
            opciones=1;
          } 
      
    
      if(inicio==0)
      {
        oled.setCursor(0, 10);     
        oled.setTextSize(1);      
        oled.print("Presiona [1] para    empezar el programa");  
        oled.display();
        
      }
      else
      {
        if(inicio==1)
        {
          oled.clearDisplay(); 
          oled.setCursor(0,0);     
          oled.setTextSize(1);      
          oled.print("Opciones:"); 
          
          oled.setCursor(0,15);     
          oled.setTextSize(1);      
          oled.print("[2].Medir BPM");  

          oled.setCursor(0,25);     
          oled.setTextSize(1);      
          oled.print("[3].Medir oxigenacion");  
          oled.display();
        }else
        {
          if(opciones==1)
          {
                oled.clearDisplay(); 
                oled.setCursor(0, 0);     
                oled.setTextSize(1);      
                oled.print("Pulso por hora");  
                oled.setCursor(0,10);     
                oled.setTextSize(1);      
                oled.print(beatsPerMinute); 
                oled.display();
            
          }
        }

        /*
          if((opciones =2))
              {
                oled.clearDisplay(); 
                oled.setCursor(0, 0);     
                oled.setTextSize(1);      
                oled.print("Pulso por hora");  
                oled.setCursor(0,10);     
                oled.setTextSize(1);      
                oled.print(beatsPerMinute); 
                oled.display();
              }*/
      }
      
      

      //Se cierra en cierto tiempo 

      ///Carga el menu 


  
  long irValue = particleSensor.getIR();
   if (irValue < 50000){
    
    //Serial.print(" No finger?");
    
   }
    
  
  if (checkForBeat(irValue) == true)
  {
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    
  }

      oled.clearDisplay();      // limpia pantalla
      oled.setTextColor(WHITE);
      /*
      oled.setCursor(0, 0);     
      oled.setTextSize(1);      
      oled.print("Pulso por hora");  // escribe en pantalla el texto
      oled.setCursor(0,10);     
      oled.setTextSize(1);      
      oled.print(beatsPerMinute);  // escribe en pantalla el texto
      oled.display();
*/
  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);

 

  Serial.println();
}
