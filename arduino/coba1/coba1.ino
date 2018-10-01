#include <SoftwareSerial.h>
String inString;
char buffer[100];
char inChar;
int i;

bool mulai;
bool endline;
char value;
char pass[6]={'r', 'e', 'v', 'o', 'l', 't'};
char data[200];
char password[15];
int pos1;
int j;


    void start(){
      if(data[i-1]=='Z'){
      mulai = true;
      pos1 = i;
      Serial.println("start");
      }              
    }

    void endl(){
      if(data[i-1]=='x'){
      endline = true;
      Serial.println("endl");
      }              
    }
    
void setup() {
  // put your setup code here, to run once:
    Serial.begin(38400);
    Serial.print("reboot succes");
}

void (*resetFunc)(void) = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    value = Serial.read();
    data[i] = value;
    i++;

    start();
    endl();
    Serial.print(i);
    Serial.println(data);
    Serial.println(password);

    if(mulai==true){
      data[i] = value;  
      password[j] = data[pos1++];
      j++;
//        Serial.print(j);
//        Serial.print(i);
//        Serial.println(data);
//        Serial.println(password);
        //Serial.println(value);
        delay(500);

    if(endline==true){
      data[i] = value;  
      password[j] = data[pos1++];
      j++;
        delay(500);
    }
      
//      for(j=0; j<sizeof(pass); j++){
//        
//        Serial.print(j);
//        Serial.print(i);
//        Serial.println(data);
//        delay(500);
//        
//        }
      }
    
    else if(data[i-1]=='9'){
      resetFunc();
    }  

    delay (500);
  }
}
