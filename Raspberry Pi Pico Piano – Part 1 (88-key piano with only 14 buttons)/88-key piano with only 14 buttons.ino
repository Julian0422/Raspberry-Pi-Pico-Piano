#include "pitches.h"

const int c = 11;
const int cs = 10;
const int d = 9;
const int ds = 8;
const int e = 7;
const int f = 6;
const int fs = 5;
const int g = 4;
const int gs = 3;
const int a = 2;
const int as = 1;
const int b = 0;

const int Buzz = 12;
const int Buzz1 = 15;
const int LED = 15;

const int up = 13;
const int down = 14; 

int up_State = 0;
int down_State = 0;

int count_value =0;
int prestate =0;

int t=100; // ...for 0.1 sec

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  //pinMode(buttonPin3, INPUT);
    
  pinMode(LED, OUTPUT);
  
  pinMode(c, INPUT);
  digitalWrite(c,HIGH);

  pinMode(cs, INPUT);
  digitalWrite(cs,HIGH);
  
  pinMode(d, INPUT);
  digitalWrite(d,HIGH);

  pinMode(ds, INPUT);
  digitalWrite(ds,HIGH);

  pinMode(e, INPUT);
  digitalWrite(e,HIGH);
  
  pinMode(f, INPUT);
  digitalWrite(f,HIGH);

  pinMode(fs, INPUT);
  digitalWrite(fs,HIGH);
  
  pinMode(g, INPUT);
  digitalWrite(g,HIGH);

  pinMode(gs, INPUT);
  digitalWrite(gs,HIGH);
  
  pinMode(a, INPUT);
  digitalWrite(a,HIGH);

  pinMode(as, INPUT);
  digitalWrite(as,HIGH);
  
  pinMode(b, INPUT);
  digitalWrite(b,HIGH);

  digitalWrite(LED,LOW);
  
  //7-Segment display
  // |-----------|
  // |-----A-----|
  // |-F-------B-|
  // |-----G-----|
  // |-E-------C-|
  // |-----D-----|
  // |-----------|
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  
  up_State = digitalRead(up);
  down_State = digitalRead(down);
  
  count();
  
    if (count_value == 1)
    {
      Serial.println("1");
      one();
      piano1();
    }
    else if (count_value == 2)
    {
      Serial.println("2");
      two();
      piano2();
    }
    else if (count_value == 3)
    {
      Serial.println("3");
      three();
      piano3();
    }
    else if (count_value == 4)
    {
      Serial.println("4");
      four();
      piano4();
    }
    else if (count_value == 5)
    {
      Serial.println("5");
      five();
      piano5();
    }
    else if (count_value == 6)
    {
      Serial.println("6");
      six();
      piano6();
    }
    else if (count_value == 7)
    {
      Serial.println("7");
      seven();
      piano7();
    }
    else if (count_value == 8)
    {
      Serial.println("8");
      eight();
      piano8();
    }
    else if (count_value == 9)
    {
      Serial.println("9");
      nine();
      piano9();
    }
    else
    {
      Serial.println(" ");
      zero();
    }
}

void zero()
{
  digitalWrite(16,HIGH);  //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,HIGH);  //D
  digitalWrite(20,HIGH);  //E
  digitalWrite(21,HIGH);  //F
  digitalWrite(22,LOW);   //G
}

void one()
{
  digitalWrite(16,LOW);   //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,LOW);   //D
  digitalWrite(20,LOW);   //E
  digitalWrite(21,LOW);   //F
  digitalWrite(22,LOW);   //G
}

void two()
{
  digitalWrite(16,HIGH);  //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,LOW);   //C
  digitalWrite(19,HIGH);  //D
  digitalWrite(20,HIGH);  //E
  digitalWrite(21,LOW);   //F
  digitalWrite(22,HIGH);  //G
}

void three()
{
  digitalWrite(16,HIGH);  //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,HIGH);  //D
  digitalWrite(20,LOW);   //E
  digitalWrite(21,LOW);   //F
  digitalWrite(22,HIGH);  //G
}

void four()
{
  digitalWrite(16,LOW);   //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,LOW);   //D
  digitalWrite(20,LOW);   //E
  digitalWrite(21,HIGH);  //F
  digitalWrite(22,HIGH);  //G
}

void five()
{
  digitalWrite(16,HIGH);  //A
  digitalWrite(17,LOW);   //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,HIGH);  //D
  digitalWrite(20,LOW);   //E
  digitalWrite(21,HIGH);  //F
  digitalWrite(22,HIGH);  //G
}

void six()
{
  digitalWrite(16,LOW);  //A
  digitalWrite(17,LOW);  //B
  digitalWrite(18,HIGH); //C
  digitalWrite(19,HIGH); //D
  digitalWrite(20,HIGH); //E
  digitalWrite(21,HIGH); //F
  digitalWrite(22,HIGH); //G
}

void seven()
{
  digitalWrite(16,HIGH);  //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,LOW);   //D
  digitalWrite(20,LOW);   //E
  digitalWrite(21,LOW);   //F
  digitalWrite(22,LOW);   //G
}

void eight()
{
  digitalWrite(16,HIGH);  //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,HIGH);  //D
  digitalWrite(20,HIGH);  //E
  digitalWrite(21,HIGH);  //F
  digitalWrite(22,HIGH);  //G
}

void nine()
{
  digitalWrite(16,HIGH);  //A
  digitalWrite(17,HIGH);  //B
  digitalWrite(18,HIGH);  //C
  digitalWrite(19,LOW);   //D
  digitalWrite(20,LOW);   //E
  digitalWrite(21,HIGH);  //F
  digitalWrite(22,HIGH);  //G
}

void count()
{
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (up_State == HIGH && prestate == 0) {
    count_value++;  
    Serial.print(count_value);
    prestate = 1;
  }
  //decrement
  else if (down_State == HIGH && prestate == 0) {
    count_value--;
    Serial.print(count_value);
    prestate = 1;
  } 
    else if(up_State == LOW && down_State == LOW) {
    prestate = 0;
  }
}

void piano1()
{
  if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a1);
    tone(Buzz1,T_a1);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as1);
    tone(Buzz1,T_as1);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b1);
    tone(Buzz1,T_b1);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    noTone(Buzz1);
    digitalWrite(LED,LOW);
  }
}

void piano2()
{
  if(digitalRead(c) == HIGH)
  {
    tone(Buzz,T_c2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(cs) == HIGH)
  {
    tone(Buzz,T_cs2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(d) == HIGH)
  {
    tone(Buzz,T_d2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(ds) == HIGH)
  {
    tone(Buzz,T_ds2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(e) == HIGH)
  {
    tone(Buzz,T_e2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(f) == HIGH)
  {
    tone(Buzz,T_f2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(fs) == HIGH)
  {
    tone(Buzz,T_fs2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(g) == HIGH)
  {
    tone(Buzz,T_g2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(gs) == HIGH)
  {
    tone(Buzz,T_gs2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b2);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    digitalWrite(LED,LOW);
  }
}

void piano3()
{
  if(digitalRead(c) == HIGH)
  {
    tone(Buzz,T_c3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(cs) == HIGH)
  {
    tone(Buzz,T_cs3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(d) == HIGH)
  {
    tone(Buzz,T_d3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(ds) == HIGH)
  {
    tone(Buzz,T_ds3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(e) == HIGH)
  {
    tone(Buzz,T_e3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(f) == HIGH)
  {
    tone(Buzz,T_f3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(fs) == HIGH)
  {
    tone(Buzz,T_fs3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(g) == HIGH)
  {
    tone(Buzz,T_g3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(gs) == HIGH)
  {
    tone(Buzz,T_gs3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b3);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    digitalWrite(LED,LOW);
  }
}

void piano4()
{
    if(digitalRead(c) == HIGH)
  {
    if (Buzz>0){
      tone(Buzz,T_c4);
    }
    else{
    tone(Buzz1,T_c4);
    }
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(cs) == HIGH)
  {
    tone(Buzz,T_cs4);
    tone(Buzz1,T_cs4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(d) == HIGH)
  {
    tone(Buzz,T_d4);
    tone(Buzz1,T_d4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(ds) == HIGH)
  {
    tone(Buzz,T_ds4);
    tone(Buzz1,T_ds4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(e) == HIGH)
  {
    tone(Buzz,T_e4);
    tone(Buzz1,T_e4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(f) == HIGH)
  {
    tone(Buzz,T_f4);
    tone(Buzz1,T_f4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(fs) == HIGH)
  {
    tone(Buzz,T_fs4);
    tone(Buzz1,T_fs4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(g) == HIGH)
  {
    tone(Buzz,T_g4);
    tone(Buzz1,T_g4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(gs) == HIGH)
  {
    tone(Buzz,T_gs4);
    tone(Buzz1,T_gs4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a4);
    tone(Buzz1,T_a4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as4);
    tone(Buzz1,T_as4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b4);
    tone(Buzz1,T_b4);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    noTone(Buzz1);
    digitalWrite(LED,LOW);
  }
}

void piano5()
{
    if(digitalRead(c) == HIGH)
  {
    tone(Buzz,T_c5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(cs) == HIGH)
  {
    tone(Buzz,T_cs5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(d) == HIGH)
  {
    tone(Buzz,T_d5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(ds) == HIGH)
  {
    tone(Buzz,T_ds5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(e) == HIGH)
  {
    tone(Buzz,T_e5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(f) == HIGH)
  {
    tone(Buzz,T_f5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(fs) == HIGH)
  {
    tone(Buzz,T_fs5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(g) == HIGH)
  {
    tone(Buzz,T_g5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(gs) == HIGH)
  {
    tone(Buzz,T_gs5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b5);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    digitalWrite(LED,LOW);
  }
}

void piano6()
{
    if(digitalRead(c) == HIGH)
  {
    tone(Buzz,T_c6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(cs) == HIGH)
  {
    tone(Buzz,T_cs6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(d) == HIGH)
  {
    tone(Buzz,T_d6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(ds) == HIGH)
  {
    tone(Buzz,T_ds6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(e) == HIGH)
  {
    tone(Buzz,T_e6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(f) == HIGH)
  {
    tone(Buzz,T_f6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(fs) == HIGH)
  {
    tone(Buzz,T_fs6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(g) == HIGH)
  {
    tone(Buzz,T_g6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(gs) == HIGH)
  {
    tone(Buzz,T_gs6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b6);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    digitalWrite(LED,LOW);
  }
}

void piano7()
{
    if(digitalRead(c) == HIGH)
  {
    tone(Buzz,T_c7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(cs) == HIGH)
  {
    tone(Buzz,T_cs7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(d) == HIGH)
  {
    tone(Buzz,T_d7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(ds) == HIGH)
  {
    tone(Buzz,T_ds7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(e) == HIGH)
  {
    tone(Buzz,T_e7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(f) == HIGH)
  {
    tone(Buzz,T_f7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(fs) == HIGH)
  {
    tone(Buzz,T_fs7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(g) == HIGH)
  {
    tone(Buzz,T_g7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(gs) == HIGH)
  {
    tone(Buzz,T_gs7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b7);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    digitalWrite(LED,LOW);
  }
}

void piano8()
{
    if(digitalRead(c) == HIGH)
  {
    tone(Buzz,T_c8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(cs) == HIGH)
  {
    tone(Buzz,T_cs8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(d) == HIGH)
  {
    tone(Buzz,T_d8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(ds) == HIGH)
  {
    tone(Buzz,T_ds8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(e) == HIGH)
  {
    tone(Buzz,T_e8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(f) == HIGH)
  {
    tone(Buzz,T_f8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(fs) == HIGH)
  {
    tone(Buzz,T_fs8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(g) == HIGH)
  {
    tone(Buzz,T_g8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(gs) == HIGH)
  {
    tone(Buzz,T_gs8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(a) == HIGH)
  {
    tone(Buzz,T_a8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }

  else if(digitalRead(as) == HIGH)
  {
    tone(Buzz,T_as8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  
  else if(digitalRead(b) == HIGH)
  {
    tone(Buzz,T_b8);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz); 
  }
  else{
    noTone(Buzz);
    digitalWrite(LED,LOW);
  }
}

void piano9()
{
  if (digitalRead(c) == HIGH) 
  {
    tone(Buzz,T_c9);
    digitalWrite(LED,HIGH);
    delay(t);        //time
    noTone(Buzz);  
  } 
  else{
    noTone(Buzz);
    digitalWrite(LED,LOW);
  }
}
