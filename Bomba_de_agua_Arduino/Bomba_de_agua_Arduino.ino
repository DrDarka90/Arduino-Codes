/* Proyecto Bomba Arduino V 1.0

Proyecto de automatización en donde dependiendo
de los valores que el sensor de humedad entregue
al Arduino, este accionara una Bomba para dar 
agua a la bomba

*/

int LuzdeEspera = 3;
int LuzdeAccion = 4;
int Bomba = 5;
int SensorH = A0;
int valorsensor = 0;
int valormapeo = 0;


void setup()
 { 
 pinMode(LuzdeEspera,OUTPUT);
 pinMode(LuzdeAccion,OUTPUT);
 pinMode(Bomba,OUTPUT);
 pinMode(SensorH,INPUT);
 Serial.begin(9600);
 }

void loop()
 { 
 valorsensor = analogRead(A0);
 valormapeo = map(valorsensor,0,1024,0,101);
 Serial.print ("Porcentaje de Humedad: ");
 Serial.print(valormapeo);
 Serial.println(" %");
 delay(1);
   if(valormapeo >= 55){
      digitalWrite(LuzdeEspera,HIGH);
      digitalWrite(LuzdeAccion,LOW);
      digitalWrite(Bomba,LOW);
   }
   else
   {
      digitalWrite(LuzdeEspera,LOW);
      digitalWrite(Bomba,HIGH); 
      digitalWrite(LuzdeAccion,HIGH);
   }
 }

