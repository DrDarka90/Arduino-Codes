#include <IRremote.h> // libreria

/*Configuración del sensor infrarojo*/
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;
/**********************************/

/*Configuracion de los PWM*/
int ENA=10; 
int ENB=5;
/**********************************/

/*Configuración Motor de la derecha*/
int IN1=6;
int IN2=7;

/*Configuración Motor de la izquierda*/
int IN3=8;
int IN4=9;


/*Velocidad*/
int velocidad1=255;
int velocidad2=255;

/*Tiempo*/

int t=12000;

void setup()
{
  /*Configuración del sensor infrarojo*/
  Serial.begin(9600);
  irrecv.enableIRIn();        // Iniciar el receptor
  
   // PWM
  pinMode(ENA,OUTPUT); //Motor A 
  pinMode(ENB,OUTPUT); //Motor B
  
  // comunicicacion del puente H
  /*Motor A*/
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  /*Motor B*/
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
}

void loop()
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value);
    irrecv.resume();          // Recive el siguiente valor , sin este comando queda con un unico valor 
  }
  
 if(16724175==results.value) //SI PRECIONO EL 1 
  {
    results.value=0; //TIENE QUE TOMAR ESTE VALOR OSINO SIEMPRE ESTARA EN ESTE CICLO DEL IF
    
     // Motor A
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA,velocidad1);
    // Motor B
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,velocidad2);
    delay(t);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }
  if(16718055==results.value)//SI PRECIONO EL 2 
  {
   results.value=0;     //TIENE QUE TOMAR ESTE VALOR OSINO SIEMPRE ESTARA EN ESTE CICLO DEL IF
  // Motor de la derecha
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA,velocidad1);
    // Motor B
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    analogWrite(ENB,velocidad2);
    delay(t);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }
}
