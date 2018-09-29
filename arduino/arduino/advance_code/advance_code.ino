#include <SoftwareSerial.h>

char data;

int a1 = 5;
int a2 = 7;
int a3 = 6;
int a4 = 8;
int a5= 9;
int a6= 11;
int a7= 10;
int a8= 12;

char fa1 = '!';
char fa2 = '@';
char fa3 = '|';
char fa4 = '$';
char fa5 = '%';
char fa6 = '^';
char fa7 = '&';
char fa8 = '*';
char fa9 = '(';
char fa10 = ')';
char fa11 = '-';
char fa12 = '_';
char fa13 = '=';
char fa14 = '+';

  void frontUp(){
    digitalWrite(a1, HIGH);
    digitalWrite(a2, HIGH);
    }

  void frontDown(){
    digitalWrite(a3, HIGH);
    digitalWrite(a4, HIGH);
    }
  
  void rearUp(){
    digitalWrite(a5, HIGH);
    digitalWrite(a6, HIGH);
    }
  
  void rearDown(){
    digitalWrite(a7, HIGH);
    digitalWrite(a8, HIGH);
    }
  
  void allUp(){
    frontUp();
    rearUp();
    }
  
  void allDown(){
    frontDown();
    rearDown();
    }
  
  void allLow(){
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
    digitalWrite(a5, LOW);
    digitalWrite(a6, LOW);
    digitalWrite(a7, LOW);
    digitalWrite(a8, LOW);
    }

  void onTouch(){
    if(data == fa1){
      digitalWrite(a1, HIGH);
      }
      else if(data == fa2){
      digitalWrite(a2, HIGH);
      }
      else if(data == fa3){
      digitalWrite(a3, HIGH);
      }
      else if(data == fa4){
      digitalWrite(a4, HIGH);
      }
      else if(data == fa5){
      digitalWrite(a5, HIGH);
      }
      else if(data == fa6){
      digitalWrite(a6, HIGH);
      }
      else if(data == fa7){
      digitalWrite(a7, HIGH);
      }
      else if(data == fa8){
      digitalWrite(a8, HIGH);
      }
      else if(data == fa9){
      frontUp();
      }
      else if(data == fa10){
      frontDown();
      }
      else if(data == fa11){
      rearUp();
      }
      else if(data == fa12){
      rearDown();
      }
      else if(data == fa13){
      allUp();
      }
      else if(data == fa14){
      allDown();
      }
      
    
    else{
      allLow();
      }
    }


void setup() {
  
  Serial.begin(38400);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(a5, OUTPUT);
  pinMode(a6, OUTPUT);
  pinMode(a7, OUTPUT);
  pinMode(a8, OUTPUT);

  allLow();
}

void loop() {
  
  if(Serial.available() > 0) {  // Send data only when you receive data:
    data = Serial.read();     
    Serial.println(data);       
      //onTouch();

      
  }  

  
} //end of loop
