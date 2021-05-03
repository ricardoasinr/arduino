#include <Wire.h>     // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306
 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64

#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto

int x=0;
void setup() {
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
}
 
void loop() {
  oled.clearDisplay();      // limpia pantalla      
  oled.drawRect(10, 20, 100, 44, WHITE); // dibuja rectangulo

  oled.setCursor(18, 34);   // ubica cursor en coordenadas 28,34
  oled.setTextSize(2);      // establece tamano de texto en 2
  oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
  oled.print("Ricardo");     // escribe texto
  oled.display();     // muestra en pantalla todo lo establecido anteriormente
}
