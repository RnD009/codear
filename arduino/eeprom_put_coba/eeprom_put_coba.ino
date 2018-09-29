
#include <EEPROM.h>

struct password {char pass[15];};

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  int eeAddress = 0;   //Location we want the data to be put.
  password customVar = {"revolt"};
  Serial.println("put data into eeprom");
  EEPROM.put(eeAddress, customVar);
  
  Serial.println(".");
  delay(1000);
  Serial.println(".");
  delay(1000);
  Serial.println(".");
  delay(1000);
  Serial.println("data from eeprom");
  secondTest();
}

void secondTest() {
  int eeAddress = 0;
  password customVar;
  EEPROM.get(eeAddress, customVar);
  
  Serial.println(customVar.pass);
}

void loop() {
  /* Empty loop */
}
