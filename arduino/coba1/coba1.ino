#include <SoftwareSerial.h>
#include <EEPROM.h>
String inString;
char buffer[100];
char inChar;
int i;

bool mulai;
bool endline;
bool save;
char value;
char pass[15];
char pa[15] = {'a', 'k', 'u', 'a'};
char data[800];
char password[15];
int pos1;
int pos2;
int j;
int k;


    void start(){
      if(data[i-1]=='Z'){
        mulai = true;
          pos1 = i;
            Serial.println("start");
               Serial.println(pos1);
      }              
    }

    void endl(){
      if(data[i-1]=='x'){
        endline = true;
          pos2 = i - 1;
            Serial.println("endl");
      }              
    }
    
void setup() {
  // put your setup code here, to run once:
    Serial.begin(38400);
    Serial.println("reboot succes");
    EEPROM.get(0, pass);
    Serial.println(pass);
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

    if(endline==true){

      while(pos1<pos2){
          password[j] = data[pos1];
            pos1++;
            j++;  
            Serial.print(password);   
        }
        save = true;

      }

    if(save==true){
      EEPROM.put(0, password); 
        Serial.println("put done!!!");
      }

    if(data[i-1]=='9'){
      resetFunc();
    }  
}
   
    delay (500);
}
