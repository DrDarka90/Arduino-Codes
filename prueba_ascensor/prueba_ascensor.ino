int E1 = 5;
int INM11 = 4;
int INM12 = 6;
int boton1 = A0;
int boton2 = A1;
int E2 = 9;
int INM21 = 7;
int INM22 = 8;
int boton3 = A2;
int boton4 = A3;

void setup() {
  pinMode(E1, OUTPUT);
  pinMode(INM11, OUTPUT);
  pinMode(INM12, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(E2, OUTPUT);
  pinMode(INM21, OUTPUT);
  pinMode(INM22, OUTPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  Serial.begin(9800);
}

void loop() {

  Serial.print(analogRead(boton1));
  Serial.print(" ");
  Serial.print(analogRead(boton2));
  Serial.print(" ");
  Serial.print(analogRead(boton3));
  Serial.print(" ");
  Serial.println(analogRead(boton4));
  if (analogRead(boton1) > 100)
  {
    analogWrite(E1, 255);
    digitalWrite(INM11, HIGH);
    digitalWrite(INM12, LOW);
  }
  if (analogRead(boton1) < 100)
  {
    analogWrite(E1, 0);
    digitalWrite(INM11, LOW);
    digitalWrite(INM12, LOW);
  }
  if (analogRead(boton2) > 100)
  {
    analogWrite(E1, 255);
    digitalWrite(INM11, LOW);
    digitalWrite(INM12, HIGH);
  }
  if (analogRead(boton2) < 100)
  {
    analogWrite(E1, 0);
    digitalWrite(INM11, LOW);
    digitalWrite(INM12, LOW);
  }
  if (analogRead(boton3) > 100)
  {
    analogWrite(E2, 255);
    digitalWrite(INM21, HIGH);
    digitalWrite(INM22, LOW);
  }
  if (analogRead(boton3) < 100)
  {
    analogWrite(E2, 0);
    digitalWrite(INM21, LOW);
    digitalWrite(INM22, LOW);
  }
  if (analogRead(boton4) > 100)
  {
    analogWrite(E2, 255);
    digitalWrite(INM21, LOW);
    digitalWrite(INM22, HIGH);
  }
  if (analogRead(boton4) < 100)
  {
    analogWrite(E2, 0);
    digitalWrite(INM21, LOW);
    digitalWrite(INM22, LOW);
  }
}



