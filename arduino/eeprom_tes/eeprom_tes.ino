#include <SoftwareSerial.h>
#include <EEPROM.h>

char passwd[10];
char ganti[10];
char devpass[6] = {'r', 'e', 'v', 'o', 'l', 't'};
char viewpass[5] = {'!', '@', '#', '$', '%'};
char resetpass[10] = {'!', '#', '%', '&', '(', '@', '$', '^', '*', ')'};
char value;

bool password;
bool mulai;
bool endline;
bool save;
bool swDown;
bool swUp;
bool Up1;
bool Up2;
bool Up3;
bool ON = false;
bool OFF = false;

char data[500];
char pass;

int i = 0;
int j;
int pos1;
int pos2;


int sw = 4;
int bt1 = 5;
int bt2 = 7;
int bt3 = 6;
int bt4 = 8;
int bt5 = 9;
int bt6 = 11;
int bt7 = 10;
int bt8 = 12;

int inputDown = 2;
int inputUp = 3;

int valDown = 0;
int valUp = 0;

int senVal1;
int senVal2;
int senVal3;
int senVal4;
int senVal_sw;

float voltage;
float pressure_pascal;
float pressure_kpa;
float vSens_1;
float vSens_2;
float vSens_3;
float vSens_4;
float vSens_5;

int mem1a = 0;
int mem1b = 0;
int mem1c = 0;
int mem1d = 0;

int mem2a = 0;
int mem2b = 0;
int mem2c = 0;
int mem2d = 0;

int mem3a = 0;
int mem3b = 0;
int mem3c = 0;
int mem3d = 0;

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
  //Serial.println(passwd);
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
  
  if (data[i - 1] == 's' && password == 1) {
    allLow();
      Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
  }
  else if (data[i - 1] == fa1 && password == 1) {
    digitalWrite(bt1, HIGH);
  }
  else if (data[i - 1] == fa2 && password == 1) {
    digitalWrite(bt2, HIGH);
  }
  else if (data[i - 1] == fa3 && password == 1) {
    digitalWrite(bt3, HIGH);
  }
  else if (data[i - 1] == fa4 && password == 1) {
    digitalWrite(bt4, HIGH);
  }
  else if (data[i - 1] == fa5 && password == 1) {
    digitalWrite(bt5, HIGH);
  }
  else if (data[i - 1] == fa6 && password == 1) {
    digitalWrite(bt6, HIGH);
  }
  else if (data[i - 1] == fa7 && password == 1) {
    digitalWrite(bt7, HIGH);
  }
  else if (data[i - 1] == fa8 && password == 1) {
    digitalWrite(bt8, HIGH);
  }
  else if (data[i - 1] == fa9 && password == 1) {
    frontUp();
  }
  else if (data[i - 1] == fa10 && password == 1) {
    frontDown();
  }
  else if (data[i - 1] == fa11 && password == 1) {
    rearUp();
  }
  else if (data[i - 1] == fa12 && password == 1) {
    rearDown();
  }
  else if (data[i - 1] == fa13 && password == 1) {
    allUp();
  }
  else if (data[i - 1] == fa14 && password == 1) {
    allDown();
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

void calibration() {

  if (data[i - 1] == '<' && password == 1) {

    digitalWrite(bt1, HIGH); //front left up
    //Serial.println("Front Left Up");
    delay(3000);
    allLow();
              Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    digitalWrite(bt3, HIGH); //front left down
    //Serial.println("Front Left Down");
    delay(2000);
    allLow();
              Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    delay(2000);

    digitalWrite(bt2, HIGH); //front right up
    //Serial.println("Front Right Up");
    delay(3000);
    allLow();
              Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    digitalWrite(bt4, HIGH); //front right down
    //Serial.println("Front Right Down");
    delay(2000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    delay(2000);
    
    digitalWrite(bt5, HIGH); //rear left up
    //Serial.println("Rear Left Up");
    delay(3000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    digitalWrite(bt7, HIGH); //rear left down
    //Serial.println("Rear Left Down");
    delay(2000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    delay(2000);
    
    digitalWrite(bt6, HIGH); //rear right up
    //Serial.println("Rear Right Up");
    delay(3000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    digitalWrite(bt8, HIGH); //rear right down
    //Serial.println("Rear Left Down");
    delay(2000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    delay(2000);
    
    frontUp(); //front up
    //Serial.println("Front Up");
    delay(3000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    frontDown(); //front down
    //Serial.println("Front Down");
    delay(2000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    delay(2000);

    rearUp(); //rear up
    //Serial.println("Rear Up");
    delay(3000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    rearDown(); //rear down
    //Serial.println("Rear Down");
    delay(2000);
    allLow();
    
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    delay(2000);

    allUp(); //all up
    //Serial.println("All Up");
    delay(3000);
    allLow();
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
    allDown(); //all down
    //Serial.println("All Down");
    delay(2000);
    //Serial.println("Calibration Succes");
    allLow();
    delay(2000);
          Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);
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

void Svmem() {
  //sv mem 1
  if (data[i - 1] == '[' && password == 1) {
    mem1a = vSens_1;
    mem1b = vSens_2;
    mem1c = vSens_3;
    mem1d = vSens_4;
    //Serial.println("mem 1 saved");
//    Serial.print(mem1a);
//    Serial.print(mem1b);
//    Serial.print(mem1c);
//    Serial.println(mem1d);
  }
  //sv mem 2
  else if (data[i - 1] == ']' && password == 1) {
    mem2a = vSens_1;
    mem2b = vSens_2;
    mem2c = vSens_3;
    mem2d = vSens_4;
    //Serial.println("mem 2 saved");
  }
  //sv mem 3
  else if (data[i - 1] == '>' && password == 1) {
    mem3a = vSens_1;
    mem3b = vSens_2;
    mem3c = vSens_3;
    mem3d = vSens_4;
    //Serial.println("mem 3 saved");

  }
}


void Opmem11(){
  // op mem 1
  //Serial.println("open mem 1");
    //depan kiri
    if(vSens_1 < mem1a){  
      digitalWrite(bt1, HIGH); //naik
      //Serial.print(vSens_1); Serial.print("<"); Serial.println(mem1a);
      //Serial.println("depan kiri naik");
      if(vSens_1 == mem1a){
        digitalWrite(bt1, LOW);
        }
      }
      
        else if(vSens_1 > mem1a){
        digitalWrite(bt3, HIGH); //turun
        //Serial.print(vSens_1); Serial.print(">"); Serial.println(mem1a);
        //Serial.println("depan kiri turun");
        if(vSens_1 == mem1a){
          digitalWrite(bt3, LOW);
          }
        }

      //depan kanan
      else if(vSens_2 < mem1b){  
      digitalWrite(bt2, HIGH); //naik
      //Serial.print(vSens_2); Serial.print("<"); Serial.println(mem1b);
      //Serial.println("depan kanan naik");
      if(vSens_1 == mem1b){
        digitalWrite(bt2, LOW);
        }
      }
      else if(vSens_2 > mem1b){
      digitalWrite(bt4, HIGH); //turun
      //Serial.print(vSens_2); Serial.print(">"); Serial.println(mem1b);
      //Serial.println("depan kanan turun");
      if(vSens_2 == mem1b){
        digitalWrite(bt4, LOW);
        }
      }

      //belakang kiri
      else if(vSens_3 < mem1c){  
      digitalWrite(bt5, HIGH); //naik
      //Serial.print(vSens_3); Serial.print("<"); Serial.println(mem1c);
      //Serial.println("belakang kiri naik");
      if(vSens_3 == mem1c){
        digitalWrite(bt5, LOW);
        }
      }
      else if(vSens_3 > mem1c){
      digitalWrite(bt7, HIGH); //turun
      //Serial.print(vSens_3); Serial.print(">"); Serial.println(mem1c);
      //Serial.println("belakang kiri turun");
      if(vSens_3 == mem1c){
        digitalWrite(bt7, LOW);
        }
      }

      //belakang kanan
      else if(vSens_4 < mem1d){  
      digitalWrite(bt6, HIGH); //naik
      //Serial.println("belakang kanan naik");
      if(vSens_4 == mem1d){
        digitalWrite(bt6, LOW);
        }
      }
      else if(vSens_4 > mem1d){
      digitalWrite(bt8, HIGH); //turun
      //Serial.println("belakang kanan turun");
      if(vSens_4 == mem1d){
        digitalWrite(bt8, LOW);
        }
      }
  }

void Opmem21(){
  // op mem 2
  //Serial.println("open mem 2");
    //depan kiri
    if(vSens_1 < mem2a){  
      digitalWrite(bt1, HIGH); //naik
      if(vSens_1 == mem2a){
        digitalWrite(bt1, LOW);
        }
      }
      else if(vSens_1 > mem2a){
      digitalWrite(bt3, HIGH); //turun
      if(vSens_1 == mem2a){
        digitalWrite(bt3, LOW);
        }
      }

      //depan kanan
      else if(vSens_2 < mem2b){  
      digitalWrite(bt2, HIGH); //naik
      if(vSens_1 == mem2b){
        digitalWrite(bt2, LOW);
        }
      }
      else if(vSens_2 > mem2b){
      digitalWrite(bt4, HIGH); //turun
      if(vSens_2 == mem2b){
        digitalWrite(bt4, LOW);
        }
      }

      //belakang kiri
      else if(vSens_3 < mem2c){  
      digitalWrite(bt5, HIGH); //naik
      if(vSens_3 == mem2c){
        digitalWrite(bt5, LOW);
        }
      }
      else if(vSens_3 > mem2c){
      digitalWrite(bt7, HIGH); //turun
      if(vSens_3 == mem2c){
        digitalWrite(bt7, LOW);
        }
      }

      //belakang kanan
      else if(vSens_4 < mem2d){  
      digitalWrite(bt6, HIGH); //naik
      if(vSens_4 == mem2d){
        digitalWrite(bt6, LOW);
        }
      }
      else if(vSens_4 > mem2d){
      digitalWrite(bt8, HIGH); //turun
      if(vSens_4 == mem2d){
        digitalWrite(bt8, LOW);
        }
      }
  }

void Opmem31(){
  // op mem 3
    //Serial.println("open mem 3");
    //depan kiri
    if(vSens_1 < mem3a){  
      digitalWrite(bt1, HIGH); //naik
      if(vSens_1 == mem3a){
        digitalWrite(bt1, LOW);
        }
      }
      else if(vSens_1 > mem3a){
      digitalWrite(bt3, HIGH); //turun
      if(vSens_1 == mem3a){
        digitalWrite(bt3, LOW);
        }
      }

      //depan kanan
      else if(vSens_2 < mem3b){  
      digitalWrite(bt2, HIGH); //naik
      if(vSens_1 == mem3b){
        digitalWrite(bt2, LOW);
        }
      }
      else if(vSens_2 > mem3b){
      digitalWrite(bt4, HIGH); //turun
      if(vSens_2 == mem3b){
        digitalWrite(bt4, LOW);
        }
      }

      //belakang kiri
      else if(vSens_3 < mem3c){  
      digitalWrite(bt5, HIGH); //naik
      if(vSens_3 == mem3c){
        digitalWrite(bt5, LOW);
        }
      }
      else if(vSens_3 > mem3c){
      digitalWrite(bt7, HIGH); //turun
      if(vSens_3 == mem3c){
        digitalWrite(bt7, LOW);
        }
      }

      //belakang kanan
      else if(vSens_4 < mem3d){  
      digitalWrite(bt6, HIGH); //naik
      if(vSens_4 == mem3d){
        digitalWrite(bt6, LOW);
        }
      }
      else if(vSens_4 > mem3d){
      digitalWrite(bt8, HIGH); //turun
      if(vSens_4 == mem3d){
        digitalWrite(bt8, LOW);
        }
      }
  }


void Opmem1(){
  // op mem 1
  if (data[i - 1] == '{') {
      //Serial.println("open mem 1");
    //depan kiri
    if(vSens_1 < mem1a){  
      digitalWrite(bt1, HIGH); //naik
      delay(1);
//      Serial.print(vSens_1); Serial.print("<"); Serial.println(mem1a);
//      Serial.println("depan kiri naik");
      if(vSens_1 < mem1a+3 &&  vSens_1 > mem1a-3){
        digitalWrite(bt1, LOW);
        delay(100);
        }
      }
      
      if(vSens_1 > mem1a){
        digitalWrite(bt3, HIGH); //turun
        delay(1);
//        Serial.print(vSens_1); Serial.print(">"); Serial.println(mem1a);
//        Serial.println("depan kiri turun");
        if(vSens_1 < mem1a+3 &&  vSens_1 > mem1a-3){
          digitalWrite(bt3, LOW);
          delay(100);
          }

        }

      //depan kanan
      if(vSens_2 < mem1b){  
      digitalWrite(bt2, HIGH); //naik
      delay(1);
//      Serial.print(vSens_2); Serial.print("<"); Serial.println(mem1b);
//      Serial.println("depan kanan naik");
      if(vSens_2 < mem1b+3 &&  vSens_2 > mem1b-3){
        digitalWrite(bt2, LOW);
          delay(100);
        }
      }
      if(vSens_2 > mem1b){
      digitalWrite(bt4, HIGH); //turun
      delay(1);
//      Serial.print(vSens_2); Serial.print(">"); Serial.println(mem1b);
//      Serial.println("depan kanan turun");
      if(vSens_2 < mem1b+3 &&  vSens_2 > mem1b-3){
        digitalWrite(bt4, LOW);
        delay(100);
        }
      }

      //belakang kiri
      if(vSens_3 < mem1c){  
      digitalWrite(bt5, HIGH); //naik
      delay(1);
//      Serial.print(vSens_3); Serial.print("<"); Serial.println(mem1c);
//      Serial.println("belakang kiri naik");
      if(vSens_3 < mem1c+3 &&  vSens_3 > mem1c-3){
        digitalWrite(bt5, LOW);
        delay(100);
        }
      }
      if(vSens_3 > mem1c){
      digitalWrite(bt7, HIGH); //turun
      delay(1);
//      Serial.print(vSens_3); Serial.print(">"); Serial.println(mem1c);
//      Serial.println("belakang kiri turun");
      if(vSens_3 < mem1c+3 &&  vSens_3 > mem1c-3){
        digitalWrite(bt7, LOW);
        delay(100);
        }
      }

      //belakang kanan
      if(vSens_4 < mem1d){  
      digitalWrite(bt6, HIGH); //naik
      delay(1);
//     Serial.println("belakang kanan naik");
      if(vSens_4 < mem1d+3 &&  vSens_4 > mem1d-3){
        digitalWrite(bt6, LOW);
        delay(100);
        }
      }
      if(vSens_4 > mem1d){
      digitalWrite(bt8, HIGH); //turun
      delay(1);
//     Serial.println("belakang kanan turun");
      if(vSens_4 < mem1d+3 &&  vSens_4 > mem1d-3){
        digitalWrite(bt8, LOW);
        delay(100);
        }
      }

 
  }
  }

void Opmem2(){
  // op mem 2
 
  if (data[i - 1] == '}') {
//      Serial.println("open mem 2");
    //depan kiri
    if(vSens_1 < mem2a){  
      digitalWrite(bt1, HIGH); //naik
      delay(1);
//      Serial.print(vSens_1); Serial.print("<"); Serial.println(mem1a);
//      Serial.println("depan kiri naik");
      if(vSens_1 < mem2a+3 &&  vSens_1 > mem2a-3){
        digitalWrite(bt1, LOW);
        delay(100);
        }
      }
      
      if(vSens_1 > mem2a){
        digitalWrite(bt3, HIGH); //turun
        delay(1);
//        Serial.print(vSens_1); Serial.print(">"); Serial.println(mem1a);
//        Serial.println("depan kiri turun");
        if(vSens_1 < mem2a+3 &&  vSens_1 > mem2a-3){
          digitalWrite(bt3, LOW);
          delay(100);
          }

        }

      //depan kanan
      if(vSens_2 < mem2b){  
      digitalWrite(bt2, HIGH); //naik
      delay(1);
//      Serial.print(vSens_2); Serial.print("<"); Serial.println(mem1b);
//      Serial.println("depan kanan naik");
      if(vSens_2 < mem2b+3 &&  vSens_2 > mem2b-3){
        digitalWrite(bt2, LOW);
          delay(100);
        }
      }
      if(vSens_2 > mem2b){
      digitalWrite(bt4, HIGH); //turun
      delay(1);
//      Serial.print(vSens_2); Serial.print(">"); Serial.println(mem1b);
//      Serial.println("depan kanan turun");
      if(vSens_2 < mem2b+3 &&  vSens_2 > mem2b-3){
        digitalWrite(bt4, LOW);
        delay(100);
        }
      }

      //belakang kiri
      if(vSens_3 < mem2c){  
      digitalWrite(bt5, HIGH); //naik
      delay(1);
//      Serial.print(vSens_3); Serial.print("<"); Serial.println(mem1c);
//      Serial.println("belakang kiri naik");
      if(vSens_3 < mem2c+3 &&  vSens_3 > mem2c-3){
        digitalWrite(bt5, LOW);
        delay(100);
        }
      }
      if(vSens_3 > mem2c){
      digitalWrite(bt7, HIGH); //turun
      delay(1);
//      Serial.print(vSens_3); Serial.print(">"); Serial.println(mem1c);
//      Serial.println("belakang kiri turun");
      if(vSens_3 < mem2c+3 &&  vSens_3 > mem2c-3){
        digitalWrite(bt7, LOW);
        delay(100);
        }
      }

      //belakang kanan
      if(vSens_4 < mem2d){  
      digitalWrite(bt6, HIGH); //naik
      delay(1);
//     Serial.println("belakang kanan naik");
      if(vSens_4 < mem2d+3 &&  vSens_4 > mem2d-3){
        digitalWrite(bt6, LOW);
        delay(100);
        }
      }
      if(vSens_4 > mem2d){
      digitalWrite(bt8, HIGH); //turun
      delay(1);
//     Serial.println("belakang kanan turun");
      if(vSens_4 < mem2d+3 &&  vSens_4 > mem2d-3){
        digitalWrite(bt8, LOW);
        delay(100);
        }
      }
  }
  }

void Opmem3(){
  // op mem 3
  if (data[i - 1] == '~') {
    //depan kiri
//    Serial.println("open mem 3");    //depan kiri
    if(vSens_1 < mem3a){  
      digitalWrite(bt1, HIGH); //naik
      delay(1);
//      Serial.print(vSens_1); Serial.print("<"); Serial.println(mem1a);
//      Serial.println("depan kiri naik");
      if(vSens_1 < mem3a+3 &&  vSens_1 > mem3a-3){
        digitalWrite(bt1, LOW);
        delay(100);
        }
      }
      
      if(vSens_1 > mem3a){
        digitalWrite(bt3, HIGH); //turun
        delay(1);
//        Serial.print(vSens_1); Serial.print(">"); Serial.println(mem1a);
//        Serial.println("depan kiri turun");
        if(vSens_1 < mem3a+3 &&  vSens_1 > mem3a-3){
          digitalWrite(bt3, LOW);
          delay(100);
          }

        }

      //depan kanan
      if(vSens_2 < mem3b){  
      digitalWrite(bt2, HIGH); //naik
      delay(1);
//      Serial.print(vSens_2); Serial.print("<"); Serial.println(mem1b);
//      Serial.println("depan kanan naik");
      if(vSens_2 < mem3b+3 &&  vSens_2 > mem3b-3){
        digitalWrite(bt2, LOW);
          delay(100);
        }
      }
      if(vSens_2 > mem3b){
      digitalWrite(bt4, HIGH); //turun
      delay(1);
//      Serial.print(vSens_2); Serial.print(">"); Serial.println(mem1b);
//      Serial.println("depan kanan turun");
      if(vSens_2 < mem3b+3 &&  vSens_2 > mem3b-3){
        digitalWrite(bt4, LOW);
        delay(100);
        }
      }

      //belakang kiri
      if(vSens_3 < mem3c){  
      digitalWrite(bt5, HIGH); //naik
      delay(1);
//      Serial.print(vSens_3); Serial.print("<"); Serial.println(mem1c);
//      Serial.println("belakang kiri naik");
      if(vSens_3 < mem3c+3 &&  vSens_3 > mem3c-3){
        digitalWrite(bt5, LOW);
        delay(100);
        }
      }
      if(vSens_3 > mem3c){
      digitalWrite(bt7, HIGH); //turun
      delay(1);
//      Serial.print(vSens_3); Serial.print(">"); Serial.println(mem1c);
//      Serial.println("belakang kiri turun");
      if(vSens_3 < mem3c+3 &&  vSens_3 > mem3c-3){
        digitalWrite(bt7, LOW);
        delay(100);
        }
      }

      //belakang kanan
      if(vSens_4 < mem3d){  
      digitalWrite(bt6, HIGH); //naik
      delay(1);
//     Serial.println("belakang kanan naik");
      if(vSens_4 < mem3d+3 &&  vSens_4 > mem3d-3){
        digitalWrite(bt6, LOW);
        delay(100);
        }
      }
      if(vSens_4 > mem3d){
      digitalWrite(bt8, HIGH); //turun
      delay(1);
//     Serial.println("belakang kanan turun");
      if(vSens_4 < mem3d+3 &&  vSens_4 > mem3d-3){
        digitalWrite(bt8, LOW);
        delay(100);
        }
      }
  }
  }

void Opmem() {
  Opmem1();
  Opmem2();
  Opmem3();
}

void swCompOn() {
  digitalWrite(sw, HIGH);
}

void swCompOff() {
  digitalWrite(sw, LOW);
}

void swComp(){
  if(vSens_5 >= 150){
      swCompOff();
    }
    else if(vSens_5 <= 100){
        swCompOn();
      }
  }

void set_up(){
  
  if(data[i - 1] == '?'){
    swCompOn();
//    Serial.println("kompressor on");
  }
//  else if(data[i - 1] == 'P'){
//    swCompOn();
//    swDown = true;
////    Serial.println("kompressor on, swDown = true");
//  }
//  else if(data[i - 1] == 'J'){
//    swCompOn();
//    swDown = true;
//    swUp = true;
//    Up1 = true;
////    Serial.println("swDown = true, swUp = true, Up1 = true");
//  }
//  else if(data[i - 1] == 'K'){
//    swCompOn();
//    swDown = true;
//    swUp = true;
//    Up2 = true;
////    Serial.println("swDown = true, swUp = true, Up2 = true");
//  }
//  else if(data[i - 1] == 'L'){
//    swCompOn();
//    swDown = true;
//    swUp = true;
//    Up3 = true;
////    Serial.println("swDown = true, swUp = true, Up3 = true");
//  }
  else if(data[i - 1] == '/'){
    swCompOff();
//    Serial.println("kompressor off");
    }
}

void carOFF(){
  if(valDown == HIGH){
    //Serial.println("down");
    OFF = true;
    }
  }

void carON(){
  if(valUp == HIGH){
    //Serial.println("up");
    ON = true;
    }
  }

void handleOFF(){
    if(OFF == 1 && swDown==1){
//      Serial.println("alldown");
      allDown();
      delay(2500);
      allLow();
      OFF = false;

      }
  }

void handleON(){
  if(ON == true){
      if(swUp == true && Up1 == true){
//      Serial.println("car = ON dan Opmem1");
      Opmem11();
      ON = false;

      }
    else if(swUp == true && Up2 == true){
//      Serial.println("car = ON dan Opmem2");
      Opmem21();
      ON = false;

      }
    else if(swUp == true && Up3 == true){
//      Serial.println("car = ON dan Opmem3");
      Opmem31();
      ON = false;

      }
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
  Serial.begin(9600);
  
//  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(bt1, OUTPUT);
  pinMode(bt2, OUTPUT);
  pinMode(bt3, OUTPUT);
  pinMode(bt4, OUTPUT);
  pinMode(bt5, OUTPUT);
  pinMode(bt6, OUTPUT);
  pinMode(bt7, OUTPUT);
  pinMode(bt8, OUTPUT);
  pinMode(sw, OUTPUT);

  //pinMode(senVal1, INPUT);
//  pinMode(inputUp , INPUT);

  allLow();
  
  getpassee();
  //Serial.println(passwd);
  
}

void (*resetFunc)(void) = 0;

void loop() {

senVal1 = analogRead(A0);
senVal2 = analogRead(A1);
senVal3 = analogRead(A2);
senVal4 = analogRead(A3);
senVal_sw = analogRead(A4);

//valDown = digitalRead(inputDown);
//valUp = digitalRead(inputUp);

/////////////////////////////
//  carOFF();
//    carON();
//
//  handleOFF();
//    handleON();

  swComp();

//  Serial.print("val Down = "); Serial.println(valDown);
//  Serial.print("val UP = "); Serial.println(valUp);
  
/////////////////////////////

      //input sensor
      //delay(10);
    voltage = (float)(senVal1 * 5) / 1024;
    pressure_pascal = (3 * ((float)voltage - 0.47)) * 100000; //* 100000.0
    pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
    vSens_1 = (float)(pressure_kpa * 0.145);
    if (vSens_1<10){
      vSens_1 = 0;
      }
    


        voltage = (float)(senVal2 * 5) / 1024;
        pressure_pascal = (3 * ((float)voltage - 0.47)) * 100000; //* 100000.0
        pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
        vSens_2 = (float)(pressure_kpa * 0.145);
        if (vSens_2<10){
          vSens_2 = 0;
        }

    
          voltage = (float)(senVal3 * 5) / 1024;
          pressure_pascal = (3 * ((float)voltage - 0.47)) * 100000; //* 100000.0
          pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
          vSens_3 = (float)(pressure_kpa * 0.145);
          if (vSens_3<10){
            vSens_3 = 0;
          }

      
            voltage = (float)(senVal4 * 5) / 1024;
            pressure_pascal = (3 * ((float)voltage - 0.47)) * 100000; //* 100000.0
            pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
            vSens_4 = (float)(pressure_kpa * 0.145);
            if (vSens_4<10){
              vSens_4 = 0;
            }

              voltage = (float)(senVal_sw * 5) / 1024;
              pressure_pascal = (3 * ((float)voltage - 0.47)) * 100000; //* 100000.0
              pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858
              vSens_5 = (float)(pressure_kpa * 0.145);
              if (vSens_5<10){
                vSens_5 = 0;
              }

      Serial.print(vSens_1,0);
      Serial.print(":");
        Serial.print(vSens_2,0);
        Serial.print(":");
          Serial.print(vSens_3,0);
          Serial.print(":");
            Serial.print(vSens_4,0);
            Serial.print(":");
              Serial.println(vSens_5,0);

      

//    Serial.print(vSens_1,0);
//      Serial.print(":");
//        Serial.print(vSens_2,0);
//        Serial.print(":");
//          Serial.print(vSens_3,0);
//          Serial.print(":");
//            Serial.print(vSens_4,0);
//            Serial.print(":");
//              Serial.println(vSens_5,0);
  
    delay(200);
  
  if (Serial.available() > 0) {

    
    value = Serial.read();
    data[i] = value;
    i++;

    //Serial.println(data);
    //Serial.print("val Down = "); Serial.println(valDown);
    //Serial.print("val UP = "); Serial.println(valUp);

    login();
    view();
    resetpasswd();
    set_up();

    calibration();
    onTouch();
/////////////////////////
    

/////////////////////////
    down();

    Svmem();
    Opmem();
    start();
    endl();
    gpass();

    reset();
   
  }
  //delay(1000);
  
  //Serial.flush();
  
} //end of loop

void reset() {
  if (data[i - 1] == '9') {
    resetFunc();
  }
}
