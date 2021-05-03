#include <Keypad.h> // importa o incluye la libreria Keypad
const byte FILAS=4;
const byte COLUMNAS=4;
char keys[FILAS][COLUMNAS]= {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS]= {9,8,7,6};
byte pinesColumnas[COLUMNAS]= {5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
char TECLA;

void setup()
{
  //iniciamos el puerto serie
  Serial.begin(9600);
}

void loop()
{
  
  TECLA= teclado.getKey(); // obtiene tecla presionada y asigna el valor a TECLA
  
  if (TECLA)
  {
    switch (TECLA)
    {
      case '1':
       
        Serial.println("Presioné la tecla 1");
        break;
        
      case '2':
        Serial.println("Presioné la tecla 2");
        break;
        
      case '3':
        Serial.println("Presioné la tecla 3");
        break;
        
      default:
        Serial.println("Presioné OTRO");
        
        break;      
    }
  } 
}
