/***
    eeprom_get example.

    This shows how to use the EEPROM.get() method.

    To pre-set the EEPROM data, run the example sketch eeprom_put.
    This sketch will run without it, however, the values shown
    will be shown from what ever is already on the EEPROM.

    This may cause the serial object to print out a large string
    of garbage if there is no null character inside one of the strings
    loaded.

    Written by Christopher Andrews 2015
    Released under MIT licence.
***/

#include <EEPROM.h>

void setup() {

  int eeAddress = 0;
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  Serial.print("Read float from EEPROM: ");
  secondTest(); //Run the next test.
}
struct password {
  char pass[10];
};

void secondTest() {
  int eeAddress = 0;
  password customVar;
  EEPROM.get(eeAddress, customVar);
  Serial.println(customVar.pass);
}

void loop() {
  /* Empty loop */
}
