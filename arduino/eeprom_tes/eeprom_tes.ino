#include <SoftwareSerial.h>
#include <EEPROM.h>

char passwd[400];
char ganti[10];
char devpass[6] = {'r', 'e', 'v', 'o', 'l', 't'};
char viewpass[5] = {'!', '@', '#', '$', '%'};
char resetpass[10] = {'!', '#', '%', '&', '(', '@', '$', '^', '*', ')'};
char value;

bool password;
bool mulai;
bool endline;
bool save;

char data[500];
char pass;

int i = 0;
int j;
int pos1;
int pos2;


int sw = 12;
int bt1 = 5;
int bt2 = 7;
int bt3 = 6;
int bt4 = 8;
int bt5 = 9;
int bt6 = 11;
int bt7 = 10;
int bt8 = 4;

byte senVal1;
byte senVal2;
byte senVal3;
byte senVal4;
byte senVal_sw;

float voltage;
float pressure_pascal;
float pressure_kpa;
float pressure_psi;

int mem1;
int mem2;
int mem3;

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


void getpassee() {
  EEPROM.get(0, passwd);
  //Serial.println("Device disconnect");
}
void putpassee() {
  if (save == true && password == true) {
    EEPROM.put(0, ganti);
    //Serial.println("Password Changed");
  }
}

void start() {
  if (data[i - 1] == 'Z') {
    mulai = true;
    pos1 = i;
    //Serial.println("start");
  }
}

void endl() {
  if (data[i - 1] == 'x') {
    endline = true;
    pos2 = i - 1;
    //Serial.println("endl");
  }
}

void gpass() {
  if (endline == true) {
    while (pos1 < pos2) {
      ganti[j] = data[pos1];
      pos1++;
      j++;
      //Serial.println(ganti);
    }
    save = true;

  }
  putpassee();
}

void login() {
  if (data[0] == passwd[0] && data[1] == passwd[1] && data[2] == passwd[2] && data[3] == passwd[3] && data[4] == passwd[4] && data[5] == passwd[5] && data[6] == passwd[6] && data[7] == passwd[7] && data[8] == passwd[8] && data[9] == passwd[9] && data[10] == passwd[10]) {
    password = true;
    

    //Serial.println("Correct Password");
    //delay(2000);
    //Serial.println(" ");
  }
}

void view() {
  if (data[0] == viewpass[0] && data[1] == viewpass[1] && data[2] == viewpass[2] && data[3] == viewpass[3] && data[4] == viewpass[4] && data[5] == viewpass[5] && data[6] == viewpass[6] && data[7] == viewpass[7] && data[8] == viewpass[8] && data[9] == viewpass[9] && data[10] == viewpass[10]) {
    //Serial.println(passwd);
    //delay(5000);
    //Serial.println(" ");
  }
}

void resetpasswd() {
  if (data[0] == resetpass[0] && data[1] == resetpass[1] && data[2] == resetpass[2] && data[3] == resetpass[3] && data[4] == resetpass[4] && data[5] == resetpass[5] && data[6] == resetpass[6] && data[7] == resetpass[7] && data[8] == resetpass[8] && data[9] == resetpass[9] && data[10] == resetpass[10] || data[0] == ')' && data[1] == '(' && data[2] == '&') {
    EEPROM.put(0, devpass);
    //Serial.println(devpass);
    //delay(5000);
    //Serial.println(" ");
  }
}

void onTouch() {
//  pinMode(bt1, OUTPUT);
//  pinMode(bt2, OUTPUT);
//  pinMode(bt3, OUTPUT);
//  pinMode(bt4, OUTPUT);
//  pinMode(bt5, OUTPUT);
//  pinMode(bt6, OUTPUT);
//  pinMode(bt7, OUTPUT);
//  pinMode(bt8, OUTPUT);
  
  if (data[i - 1] == 's' && password == 1) {
    allLow();
    
//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//      Serial.print(pressure_psi);
//    Serial.print(":");
//      Serial.print(pressure_psi);
//    Serial.print(":");
//      Serial.print(pressure_psi);
//    Serial.print(":");
//      Serial.print(pressure_psi);
//    Serial.print(":");
//      Serial.println(pressure_psi);
//    }
  
  }
  else if (data[i - 1] == fa1 && password == 1) {
    digitalWrite(bt1, HIGH);
  
//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }

  }
    
  else if (data[i - 1] == fa2 && password == 1) {
    digitalWrite(bt2, HIGH);
    
//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa3 && password == 1) {
    digitalWrite(bt3, HIGH);
   
//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa4 && password == 1) {
    digitalWrite(bt4, HIGH);
        
//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa5 && password == 1) {
    digitalWrite(bt5, HIGH);

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa6 && password == 1) {
    digitalWrite(bt6, HIGH);

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa7 && password == 1) {
    digitalWrite(bt7, HIGH);

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa8 && password == 1) {
    digitalWrite(bt8, HIGH);

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa9 && password == 1) {
    frontUp();

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa10 && password == 1) {
    frontDown();

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa11 && password == 1) {
    rearUp();

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa12 && password == 1) {
    rearDown();

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
//    }
    
  }
  else if (data[i - 1] == fa13 && password == 1) {
    allUp();

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
// 
//    }
  }
  else if (data[i - 1] == fa14 && password == 1) {
    allDown();

//    voltage = (float)(senVal1 * 10) / 1023;
//    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//    //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//    pressure_psi = (int)(pressure_kpa * 0.145);
//    if(pressure_psi<0){
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.print("0");
//    Serial.print(":");
//    Serial.println("0");
//    }
//    else{
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.print(pressure_psi);
//    Serial.print(":");
//    Serial.println(pressure_psi);
// 
//    }
  }
  
}


void frontUp() {
  digitalWrite(bt1, HIGH);
  digitalWrite(bt2, HIGH);
}

void frontDown() {
  digitalWrite(bt3, HIGH);
  digitalWrite(bt4, HIGH);
}

void rearUp() {
  digitalWrite(bt5, HIGH);
  digitalWrite(bt6, HIGH);
}

void rearDown() {
  digitalWrite(bt7, HIGH);
  digitalWrite(bt8, HIGH);
}

void allUp() {
  frontUp();
  rearUp();
}

void allDown() {
  frontDown();
  rearDown();
}

//void sensValue1() {
//  //senVal1 = analogRead(A0);
//  // voltage
////  voltage = (analogRead(A0) * 5.0) / 1024.0;
////  // pascal
////  pressure_pascal = (3.0 * ((float)voltage - 0.25)) * 100000.0;
////  //bar
////  pressure_bar = pressure_pascal / 1e5;
////  //psi
////  pressure_psi = (int)pressure_bar * 14.5038;
//senVal1 = analogRead(A0);
//  voltage = (float)(senVal1 * 10) / 1023;
//  pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//  pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//  //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//  pressure_psi = (int)(pressure_kpa * 0.145);
//  Serial.print(pressure_psi);
//  Serial.print(":");
//
//}
//
//void sensValue2() {
////  senVal2 = analogRead(A1);
//  // voltage
//  senVal1 = analogRead(A0);
//  voltage = (float)(senVal1 * 10) / 1023;
//  pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//  pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//  //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//  pressure_psi = (int)(pressure_kpa * 0.145);
//  Serial.print(pressure_psi);
//  Serial.print(":");
//}
//
//void sensValue3() {
//  //senVal3 = analogRead(A2);
//  // voltage
//  senVal1 = analogRead(A0);
//  voltage = (float)(senVal1 * 10) / 1023;
//  pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//  pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//  //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//  pressure_psi = (int)(pressure_kpa * 0.145);
//  Serial.print(pressure_psi);
//  Serial.print(":");
//}
//
//void sensValue4() {
//  //senVal4 = analogRead(A3);
//  // voltage
//  senVal1 = analogRead(A0);
//  voltage = (float)(senVal1 * 10) / 1023;
//  pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//  pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//  //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//  pressure_psi = (int)(pressure_kpa * 0.145);
//  Serial.print(pressure_psi);
//  Serial.print(":");
//}
//
//void sensValueSW() {
//  //senVal_sw = analogRead(A4);
//  // voltage
//  senVal1 = analogRead(A0);
//  voltage = (float)(senVal1 * 10) / 1023;
//  pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
//  pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
//  //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
//  pressure_psi = (int)(pressure_kpa * 0.145);
//  Serial.println(pressure_psi);
//
//}
//
//void vValue() {
//  if(password == true){
//    //Serial.println("val");
//     sensValue1();
//     sensValue2();
//     sensValue3();
//     sensValue4();
//     sensValueSW();  
//     //Serial.print(":");
//    }
//}

void calibration() {

//  pinMode(bt1, OUTPUT);
//  pinMode(bt2, OUTPUT);
//  pinMode(bt3, OUTPUT);
//  pinMode(bt4, OUTPUT);
//  pinMode(bt5, OUTPUT);
//  pinMode(bt6, OUTPUT);
//  pinMode(bt7, OUTPUT);
//  pinMode(bt8, OUTPUT);
  
  if (data[i - 1] == '<' && password == 1) {

    digitalWrite(bt1, HIGH); //front left up
    //Serial.println("Front Left Up");
    delay(3000);
    allLow();
    digitalWrite(bt3, HIGH); //front left down
    //Serial.println("Front Left Down");
    delay(2000);
    allLow();
    delay(2000);
    digitalWrite(bt2, HIGH); //front right up
    //Serial.println("Front Right Up");
    delay(3000);
    allLow();
    digitalWrite(bt4, HIGH); //front right down
    //Serial.println("Front Right Down");
    delay(2000);
    allLow();
    delay(2000);
    digitalWrite(bt5, HIGH); //rear left up
    //Serial.println("Rear Left Up");
    delay(3000);
    allLow();
    digitalWrite(bt7, HIGH); //rear left down
    //Serial.println("Rear Left Down");
    delay(2000);
    allLow();
    delay(2000);
    digitalWrite(bt6, HIGH); //rear right up
    //Serial.println("Rear Right Up");
    delay(3000);
    allLow();
    digitalWrite(bt8, HIGH); //rear right down
    //Serial.println("Rear Left Down");
    delay(2000);
    allLow();
    delay(2000);
    frontUp(); //front up
    //Serial.println("Front Up");
    delay(3000);
    allLow();
    frontDown(); //front down
    //Serial.println("Front Down");
    delay(2000);
    allLow();
    delay(2000);
    rearUp(); //rear up
    //Serial.println("Rear Up");
    delay(3000);
    allLow();
    rearDown(); //rear down
    //Serial.println("Rear Down");
    delay(2000);
    allLow();
    delay(2000);
    allUp(); //all up
    //Serial.println("All Up");
    delay(3000);
    allLow();
    allDown(); //all down
    //Serial.println("All Down");
    delay(2000);
    //Serial.println("Calibration Succes");
    allLow();
    delay(2000);
    //Serial.println(" ");
  }
}

void down() {
  if (data[i - 1] == ';' && password == 1) {
    allDown();
    delay(2500);
    allLow();
  }
}

void swComp() {
  pinMode(sw, OUTPUT);
  
  if (data[i - 1] == '?' && password == 1) {
    //Serial.println("Kompressor on");
    digitalWrite(sw, HIGH);
  }
  else if (data[i - 1] == '/' && password == 1) {
    //Serial.println("Kompressor off");
    digitalWrite(sw, LOW);
  }
}

void Svmem() {
  if (data[i - 1] == '[' && password == 1) {

  }
  else if (data[i - 1] == ']' && password == 1) {

  }
  else if (data[i - 1] == '>' && password == 1) {

  }
}

void Opmem() {
  if (data[i - 1] == '{' && password == 1) {

  }
  else if (data[i - 1] == '}' && password == 1) {

  }
  else if (data[i - 1] == '~' && password == 1) {

  }
}

void allLow() {
  digitalWrite(bt1, LOW);
  digitalWrite(bt2, LOW);
  digitalWrite(bt3, LOW);
  digitalWrite(bt4, LOW);
  digitalWrite(bt5, LOW);
  digitalWrite(bt6, LOW);
  digitalWrite(bt7, LOW);
  digitalWrite(bt8, LOW);
}

void setup() {
  Serial.begin(38400);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(bt1, OUTPUT);
  pinMode(bt2, OUTPUT);
  pinMode(bt3, OUTPUT);
  pinMode(bt4, OUTPUT);
  pinMode(bt5, OUTPUT);
  pinMode(bt6, OUTPUT);
  pinMode(bt7, OUTPUT);
  pinMode(bt8, OUTPUT);

//  pinMode(A0, INPUT);

  allLow();
  
  getpassee();
}

void (*resetFunc)(void) = 0;

void loop() {
  
    voltage = (float)(analogRead(A0) * 10) / 1024;
    pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
    pressure_psi = (float)(pressure_kpa * 0.145);
    Serial.print(pressure_psi,0);
    Serial.print(":");
    Serial.print(pressure_psi,0);
    Serial.print(":");
    Serial.print(pressure_psi,0);
    Serial.print(":");
    Serial.print(pressure_psi, 0);
    Serial.print(":");
    Serial.println(pressure_psi, 0);

    if(pressure_psi > 60){
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(1000); 
      }
    
  if (Serial.available() > 0) {
    
    
    value = Serial.read();
    data[i] = value;
    i++;


    //Serial.println(data);

    login();
    view();
    resetpasswd();
    calibration();
    onTouch();
    //vValue();
    down();
    swComp();
    Svmem();
    Opmem();
    start();
    endl();
    gpass();

    reset();

    
  }

  Serial.flush();
delay (500);
} //end of loop

void reset() {
  if (data[i - 1] == '9') {
    resetFunc();
  }
}
