#include <SoftwareSerial.h>
#include <EEPROM.h>

int eeAddress = 0;
char passwd[450];
char ganti[15];
int i=0;
char value;
char passIn;
bool password;

char data[800];
char pass;
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

  
  void getpassee(){
    EEPROM.get(eeAddress, passwd);
    Serial.print("Password default :");
    Serial.println(passwd);
    }
  void putpasee(){
    EEPROM.put(eeAddress, ganti);
    Serial.print("Password terganti");
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
    if(data[i-1]==fa1 && password == 1){
      digitalWrite(a1, HIGH);
      }
      else if(data[i-1]==fa2 && password == 1){
      digitalWrite(a2, HIGH);
      }
      else if(data[i-1]==fa3 && password == 1){
      digitalWrite(a3, HIGH);
      }
      else if(data[i-1]==fa4 && password == 1){
      digitalWrite(a4, HIGH);
      }
      else if(data[i-1]==fa5 && password == 1){
      digitalWrite(a5, HIGH);
      }
      else if(data[i-1]==fa6 && password == 1){
      digitalWrite(a6, HIGH);
      }
      else if(data[i-1]==fa7 && password == 1){
      digitalWrite(a7, HIGH);
      }
      else if(data[i-1]==fa8 && password == 1){
      digitalWrite(a8, HIGH);
      }
      else if(data[i-1]==fa9 && password == 1){
      frontUp();
      }
      else if(data[i-1]==fa10 && password == 1){
      frontDown();
      }
      else if(data[i-1]==fa11 && password == 1){
      rearUp();
      }
      else if(data[i-1]==fa12 && password == 1){
      rearDown();
      }
      else if(data[i-1]==fa13 && password == 1){
      allUp();
      }
      else if(data[i-1]==fa14 && password == 1){
      allDown();
      } 
      else{
        allLow();
        }
    }

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

    void start(){
      if(data[i-1]=='Z' && password == 1){
      bool start = true;
      Serial.println("start");
      }              
    }

    void endl(){
      if(data[i-1]=='x' && password == 1){
      bool endl= true;
      Serial.println("endl");
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

  getpassee();


}
void (*resetFunc)(void) = 0;

void loop() {
  
  if(Serial.available() > 0) {
    value = Serial.read();
    data[i]=value;
    i++;

    Serial.print(i);
    Serial.println(value);
    Serial.println(ganti);

    if(data[0]==passwd[0] && data[1]==passwd[1] && data[2]==passwd[2] && data[3]==passwd[3] && data[4]==passwd[4] && data[5]==passwd[5] && data[6]==passwd[6] && data[7]==passwd[7] && data[8]==passwd[8] && data[9]==passwd[9] && data[10]==passwd[10]){
            password=true;
            Serial.println("password benar");
      }
    else if(data[i-1]=='9'){
      resetFunc();
    }    
    onTouch();
    start();
    endl();

  }
  Serial.flush();
  
} //end of loop



  
