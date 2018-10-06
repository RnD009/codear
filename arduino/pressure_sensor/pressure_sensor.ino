#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2); 

float senVal1 = analogRead(A0);
float senVal2 = analogRead(A1);
float senVal3 = analogRead(A2);
float senVal4 = analogRead(A3);

float voltage;
float pressure_pascal;
float pressure_bar;
float pressure_psi;


//int senVal_sw = analogRead(A5);

void setup() {
  // put your setup code here, to run once:
      Serial.begin(38400);
      lcd.begin();
      pinMode(senVal1, INPUT);
      pinMode(senVal2, INPUT);
      pinMode(senVal3, INPUT);
      pinMode(senVal4, INPUT);
      //pinMode(senVal_sw, INPUT);
      
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Sensor Value: ");
  Serial.print(senVal1);

  voltage = (senVal1 * 5.0) / 1024.0;
    Serial.print("Volts: ");
    Serial.print(voltage);
   
  pressure_pascal = (3.0*((float)voltage-0.47))*1000000.0;
  pressure_bar = pressure_pascal/10e5;
    Serial.print("Pressure = ");
    Serial.print(pressure_bar);
    Serial.println(" bars");

  pressure_psi =  pressure_bar * 14.5038;
    Serial.print("Pressure = ");
    Serial.print(pressure_psi);
    Serial.println(" psi");

// psi
    lcd.setCursor(0,0);
    lcd.print(pressure_psi);
    lcd.setCursor(11,0);
    lcd.print(" Psi");

// bar
    lcd.setCursor(0,1);
    lcd.print(pressure_bar);
    lcd.setCursor(11,1);
    lcd.print(" bar");


  if  (pressure_psi >= 120.0){
    lcd.setCursor(0,1);
    lcd.print("COMPRESSOR OFF");
    }
    
}
