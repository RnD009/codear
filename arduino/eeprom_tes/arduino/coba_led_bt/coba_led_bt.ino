//coba bt led
#include <SoftwareSerial.h>

char data;
void setup() 
{
Serial.begin(38400);         //Sets the data rate in bits per second (baud) for serial data transmission
pinMode(12, OUTPUT);        //Sets digital pin 13 as output pin
digitalWrite(12, LOW);
}
void loop()
{
if(Serial.available() > 0)  // Send data only when you receive data:
{
data = Serial.read();      //Read the incoming data and store it into variable data
Serial.print(data);        //Print Value inside data in Serial monitor
  if(data == '^'){
        digitalWrite(12, HIGH);
    }
  if(data == 't'){
        Serial.write('password salah");
    }
  else if(data == 's'){
          digitalWrite(12, LOW);
          }
}                            
}
