/*Ascensor*/
/*Botones*/
const int boton1 = 7;
const int boton2 = 6;
const int boton3 = 5;
const int boton4 = 4;
/*Motores*/
const int E1 = 11;
const int M1 = 12;
const int M2 = 13;
const int E2 = 10;
const int M3 = 9;
const int M4 = 8;
/*Estado*/
int valor1 = 0;
int valor2 = 0;
int valor3 = 0;
int valor4 = 0;

void setup() {
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(E1,255);
  digitalWrite(M1,);
  digitalWrite(M2,HIGH);

}
