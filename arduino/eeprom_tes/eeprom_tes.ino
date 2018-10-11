#include <SoftwareSerial.h>
#include <EEPROM.h>

char passwd[450];
char ganti[10];
char devpass[6] = {'r', 'e', 'v', 'o', 'l', 't'};
char viewpass[5] = {'!', '@', '#', '$', '%'};
char resetpass[10] = {'!', '#', '%', '&', '(', '@', '$', '^', '*', ')'};
char value;

bool password;
bool mulai;
bool endline;
bool save;

char data[600];
char pass;

int i = 0;
int j;
int pos1;
int pos2;


int sw = 12;
int a1 = 5;
int a2 = 7;
int a3 = 6;
int a4 = 8;
int a5 = 9;
int a6 = 11;
int a7 = 10;
int a8 = 4;

float senVal1;
float senVal2;
float senVal3;
float senVal4;
float senVal_sw;

float voltage;
float pressure_pascal;
int pressure_bar;
int pressure_psi;

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
  Serial.print("Password :");
  Serial.println(passwd);
}
void putpassee() {
  if (save == true && password == true) {
    EEPROM.put(0, ganti);
    Serial.println("Password Changed");
  }
}

void start() {
  if (data[i - 1] == 'Z') {
    mulai = true;
    pos1 = i;
    Serial.println("start");
    Serial.println(pos1);
  }
}

void endl() {
  if (data[i - 1] == 'x') {
    endline = true;
    pos2 = i - 1;
    Serial.println("endl");
  }
}

void gpass() {
  if (endline == true) {
    while (pos1 < pos2) {
      ganti[j] = data[pos1];
      pos1++;
      j++;
      Serial.println(ganti);
    }
    save = true;

  }
  putpassee();
}

void login() {
  if (data[0] == passwd[0] && data[1] == passwd[1] && data[2] == passwd[2] && data[3] == passwd[3] && data[4] == passwd[4] && data[5] == passwd[5] && data[6] == passwd[6] && data[7] == passwd[7] && data[8] == passwd[8] && data[9] == passwd[9] && data[10] == passwd[10]) {
    password = true;
    Serial.println("Correct Password");
    delay(2000);
    Serial.println(" ");
  }
}

void view() {
  if (data[0] == viewpass[0] && data[1] == viewpass[1] && data[2] == viewpass[2] && data[3] == viewpass[3] && data[4] == viewpass[4] && data[5] == viewpass[5] && data[6] == viewpass[6] && data[7] == viewpass[7] && data[8] == viewpass[8] && data[9] == viewpass[9] && data[10] == viewpass[10]) {
    Serial.println(passwd);
    delay(5000);
    Serial.println(" ");
  }
}

void resetpasswd() {
  if (data[0] == resetpass[0] && data[1] == resetpass[1] && data[2] == resetpass[2] && data[3] == resetpass[3] && data[4] == resetpass[4] && data[5] == resetpass[5] && data[6] == resetpass[6] && data[7] == resetpass[7] && data[8] == resetpass[8] && data[9] == resetpass[9] && data[10] == resetpass[10] || data[0] == ')' && data[1] == '(' && data[2] == '&') {
    EEPROM.put(0, devpass);
    Serial.println(devpass);
    delay(5000);
    Serial.println(" ");
  }
}


void onTouch() {
  if (data[i - 1] == fa1 && password == 1) {
    digitalWrite(a1, HIGH);
  }
  else if (data[i - 1] == fa2 && password == 1) {
    digitalWrite(a2, HIGH);
  }
  else if (data[i - 1] == fa3 && password == 1) {
    digitalWrite(a3, HIGH);
  }
  else if (data[i - 1] == fa4 && password == 1) {
    digitalWrite(a4, HIGH);
  }
  else if (data[i - 1] == fa5 && password == 1) {
    digitalWrite(a5, HIGH);
  }
  else if (data[i - 1] == fa6 && password == 1) {
    digitalWrite(a6, HIGH);
  }
  else if (data[i - 1] == fa7 && password == 1) {
    digitalWrite(a7, HIGH);
  }
  else if (data[i - 1] == fa8 && password == 1) {
    digitalWrite(a8, HIGH);
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
  else if(data[i - 1] == 's' && password == 1) {
    allLow();
  }
}

void frontUp() {
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
}

void frontDown() {
  digitalWrite(a3, HIGH);
  digitalWrite(a4, HIGH);
}

void rearUp() {
  digitalWrite(a5, HIGH);
  digitalWrite(a6, HIGH);
}

void rearDown() {
  digitalWrite(a7, HIGH);
  digitalWrite(a8, HIGH);
}

void allUp() {
  frontUp();
  rearUp();
}

void allDown() {
  frontDown();
  rearDown();
}

void sensValue1(){
  // voltage
  voltage = (senVal1 * 5.0) / 1024.0;
  // pascal
  pressure_pascal = (3.0*((float)voltage-0.25))*100000.0;
  //bar
  pressure_bar = pressure_pascal/1e5;
  //psi
  pressure_psi = (int)pressure_bar * 14.5038;
  Serial.print(pressure_psi);
  Serial.println(" Psi");
  delay(100);
  
  }

void sensValue2(){
  // voltage
  voltage = (senVal2 * 5.0) / 1024.0;
  // pascal
  pressure_pascal = (3.0*((float)voltage-0.25))*100000.0;
  //bar
  pressure_bar = pressure_pascal/1e5;
  //psi
  pressure_psi = (int)pressure_bar * 14.5038;
  Serial.print(pressure_psi);
  Serial.println(" Psi");
  delay(100);
  
  }

  void sensValue3(){
  // voltage
  voltage = (senVal3 * 5.0) / 1024.0;
  // pascal
  pressure_pascal = (3.0*((float)voltage-0.25))*100000.0;
  //bar
  pressure_bar = pressure_pascal/1e5;
  //psi
  pressure_psi = (int)pressure_bar * 14.5038;
  Serial.print(pressure_psi);
  Serial.println(" Psi");
  delay(100);
  
  }

  void sensValue4(){
  // voltage
  voltage = (senVal4 * 5.0) / 1024.0;
  // pascal
  pressure_pascal = (3.0*((float)voltage-0.25))*100000.0;
  //bar
  pressure_bar = pressure_pascal/1e5;
  //psi
  pressure_psi = (int)pressure_bar * 14.5038;
  Serial.print(pressure_psi);
  Serial.println(" Psi");
  delay(100);
  
  }

  void sensValueSW(){
  // voltage
  voltage = (senVal_sw * 5.0) / 1024.0;
  // pascal
  pressure_pascal = (3.0*((float)voltage-0.25))*100000.0;
  //bar
  pressure_bar = pressure_pascal/1e5;
  //psi
  pressure_psi = (int)pressure_bar * 14.5038;
  Serial.print(pressure_psi);
  Serial.println(" Psi");
  delay(100);
  
  }

  void vValue(){
    sensValue1();
    sensValue2();
    sensValue3();
    sensValue4();
    sensValueSW();
  }

  void calibration() {
  if (data[i - 1] == '<' && password == 1) {
    digitalWrite(a1, HIGH); //front left up
    Serial.println("Front Left Up");
    delay(3000);
    allLow();
    digitalWrite(a3, HIGH); //front left down
    Serial.println("Front Left Down");
    delay(2000);
    allLow();
    digitalWrite(a2, HIGH); //front right up
    Serial.println("Front Right Up");
    delay(3000);
    allLow();
    digitalWrite(a4, HIGH); //front right down
    Serial.println("Front Right Down");
    delay(2000);
    allLow();
    digitalWrite(a5, HIGH); //rear left up
    Serial.println("Rear Left Up");
    delay(3000);
    allLow();
    digitalWrite(a7, HIGH); //rear left down
    Serial.println("Rear Left Down");
    delay(2000);
    allLow();
    digitalWrite(a6, HIGH); //rear right up
    Serial.println("Rear Right Up");
    delay(3000);
    allLow();
    digitalWrite(a8, HIGH); //rear right down
    Serial.println("Rear Left Down");
    delay(2000);
    allLow();
    frontUp(); //front up
    Serial.println("Front Up");
    delay(3000);
    allLow();
    frontDown(); //front down
    Serial.println("Front Down");
    delay(2000);
    allLow();
    rearUp(); //rear up
    Serial.println("Rear Up");
    delay(3000);
    allLow();
    rearDown(); //rear down
    Serial.println("Rear Down");
    delay(2000);
    allLow(); 
    allUp(); //all up
    Serial.println("All Up");
    delay(3000);
    allLow();
    allDown(); //all down
    Serial.println("All Down");
    delay(2000);
    Serial.println("Calibration Succes");
    allLow();
    delay(2000);
    Serial.println(" ");
    }
  }

  void down(){
    if(data[i - 1] == ';' && password == 1){
       allDown();
       delay(2500);
       allLow();
      }
    
    }

  void swComp(){
    if (data[i - 1] == '?' && password == 1){
      Serial.println("Kompressor on");
      digitalWrite(sw, HIGH);
      }
    else if(data[i - 1] == '/' && password == 1){
      Serial.println("Kompressor off");
      digitalWrite(sw, LOW);
      }
    }

  void allLow() {
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
    digitalWrite(a5, LOW);
    digitalWrite(a6, LOW);
    digitalWrite(a7, LOW);
    digitalWrite(a8, LOW);
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
                  pinMode(sw, OUTPUT);

  senVal1 = analogRead(A0);
    senVal2 = analogRead(A1);
      senVal3 = analogRead(A2);
        senVal4 = analogRead(A3);
           senVal_sw = analogRead(A4);

  allLow();

  getpassee();


}
void (*resetFunc)(void) = 0;

void loop() {

  if (Serial.available() > 0) {
    value = Serial.read();
    data[i] = value;
    i++;

    Serial.print(i);
    Serial.println(value);
    Serial.println(ganti);

    login();
    view();
    resetpasswd();
    calibration();
//    vValue();
    onTouch();
    down();
    swComp();
    start();
    endl();
    gpass();

    reset();

  }
  Serial.flush();

} //end of loop

void reset() {
  if (data[i - 1] == '9') {
    resetFunc();
  }
}
