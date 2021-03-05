#define PUNTO 263.15
#define RAYA  PUNTO*2
#define SEPARACION_LETRA PUNTO
#define SEPARACION_SIGNO PUNTO/2

//Funciones base
void encender(int tiempo)
{
  
  digitalWrite(13, HIGH); 
  delay(tiempo);                      
}
void separar_signo()
{
    digitalWrite(13, LOW);    
  delay(SEPARACION_SIGNO);                      
}

//Funciones para los signos
void punto()
{
  encender(PUNTO);
  separar_signo();
}

void raya()
{
  encender(RAYA);
  separar_signo();
}
//Espaciado
void espacio_entre_letras()
{
  digitalWrite(13, LOW);    
  delay(SEPARACION_LETRA);
}

//Letras
void letra_R()
{
  //R = . - .  
  punto();
  raya();
  punto();  
  espacio_entre_letras();
}

void letra_I()
{
 // I = . .
 punto();
 punto();  
 espacio_entre_letras();
  
}

void letra_C()
{
  //C = - . - . 
  raya();
  punto();
  raya();
  punto();
  espacio_entre_letras();
  
}

void letra_A()
{
  //A = . -  
  punto();
  raya();
  espacio_entre_letras();
  
  
}

void letra_D(){
  //D = - . .
  raya();
  punto();
  punto();
  espacio_entre_letras();   
}

void letra_O()
{
  //O = - - -  
  raya();
  raya();
  raya();
  espacio_entre_letras();
}

void letra_S(){
  //S = . . .  
  punto();
  punto();
  punto();
  espacio_entre_letras();
   
}
void letra_Espacio(){
 // / = - . . - .
  raya();
  punto();
  punto();
  raya();
  punto();
}
void letra_N(){
  //N = - .  
  raya();
  punto();
  espacio_entre_letras();
}
void cinco_segundos()
{
  digitalWrite(13, HIGH);    
  delay(5000);
}

void setup() {
  
  pinMode(13, OUTPUT);
}



  
  
void loop() {
  /* 
   R = . - .   
   I = . .     
   C = - . - . 
   A = . -     
   R = . - .   
   D = - . .   
   O = - - -   
   / = - . . - .
   A = . -     
   S = . . .   
   I = . .     
   N = - .     
  */
  
  letra_R();
  letra_I();
  letra_C();
  letra_A();
  letra_R();
  letra_D();
  letra_O();
  letra_Espacio();
  letra_A();
  letra_S();
  letra_I();
  letra_N();
  cinco_segundos();
  
  

}
