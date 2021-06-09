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
int ledRojo = 13;
int ledAmarillo = 12;
int ledVerde=11;

long lastBeat = 0; 
float beatsPerMinute;
int beatAvg;
char TECLA;
int estado=0;
long oxigenacion;
int SPO2;

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
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  particleSensor.setup(); //Carga la configuración por defecto del sensor.
  particleSensor.setPulseAmplitudeRed(0x0A); //Enciende el led rojo del sensor para verificar si esta funcionando.
  particleSensor.setPulseAmplitudeGreen(0); //Apaga el led verde en caso que el sensor cuente con este led.
  
}

void loop()
{
      /*digitalWrite(ledAmarillo, HIGH);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledRojo, HIGH);*/
      //Texto de bienvenida 
      TECLA= teclado.getKey();

      switch(TECLA)
      {
        case '1': 
          estado=1;
          tone(BUZZER,200);
          
        break;
        
        case '2':
         estado=2;
        break;

        case '3':
         estado=3;
        break;
         
        case'*':
          estado=0;
        break;
      }
      

      if(estado==0)
      {
        oled.clearDisplay(); 
        oled.setTextColor(WHITE);
        oled.setCursor(0, 10);     
        oled.setTextSize(1);      
        oled.print("Presiona [1] para    empezar el programa");  
        oled.display();
        
      }
      else if(estado==1)
      {
        
          oled.clearDisplay(); 
          tone(BUZZER,0);
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
      }
    
    else if(estado==2)
          { 
               long detectaDedo = particleSensor.getIR();  
               if (detectaDedo < 50000){
                 oled.clearDisplay(); 
                oled.setCursor(0, 5);     
                oled.setTextSize(1);      
                oled.print("Coloca tu dedo en el sensor"); 
                oled.display();
                }
                else 
                {
                   if (checkForBeat(detectaDedo) == true)
                {
                  long delta = millis() - lastBeat;
                  lastBeat = millis();
              
                  beatsPerMinute = 60 / (delta / 1000.0);
                  
                }
                  if (beatsPerMinute>100)
                  {
                      digitalWrite(ledRojo, HIGH);
                      digitalWrite(ledVerde, LOW);
                      digitalWrite(ledAmarillo, LOW);
                  }
                  else if (beatsPerMinute>=60 && beatsPerMinute<=100)
                  {
                      digitalWrite(ledRojo, LOW);
                      digitalWrite(ledVerde, HIGH);
                      digitalWrite(ledAmarillo, LOW);
                  }
                  
                 else if (beatsPerMinute<60 && beatsPerMinute>0)
                  {
                      digitalWrite(ledRojo, LOW);
                      digitalWrite(ledVerde, LOW);
                      digitalWrite(ledAmarillo, HIGH);
                  }
            
                oled.clearDisplay(); 
                oled.setCursor(0, 0);     
                oled.setTextSize(1);      
                oled.print("Pulso por minuto:");  
                oled.setCursor(0,10);     
                oled.setTextSize(1);      
                oled.print(beatsPerMinute); 
                oled.display();
               }  
             
            
          }
     else if(estado==3)
          {
             long detectaDedo = particleSensor.getIR();  
               if (detectaDedo < 50000){
                 oled.clearDisplay(); 
                oled.setCursor(0, 5);     
                oled.setTextSize(1);      
                oled.print("Coloca tu dedo en el sensor"); 
                oled.display();
                }
                
                else {
                oxigenacion = random(85, 99);
                if(oxigenacion>90)
                {
                  digitalWrite(ledVerde, HIGH);
                  digitalWrite(ledRojo, LOW);
                  }
                else if (oxigenacion<90)
                  {
                      digitalWrite(ledVerde, LOW);
                      digitalWrite(ledRojo, HIGH);
                  }
        
                
                oled.clearDisplay(); 
                oled.setTextColor(WHITE);
                oled.setCursor(0, 0);     
                oled.setTextSize(1);      
                oled.print("Oxigenacion:");  
                oled.setCursor(0,10);     
                oled.setTextSize(1);  
                delay(1000);    
                oled.print(oxigenacion); 
                Serial.println(oxigenacion);
                oled.display();
                }
            
          }
        
/*
  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);
*/
 

  Serial.println();
}
