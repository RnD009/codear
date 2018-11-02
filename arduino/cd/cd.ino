int senVal1;
byte senVal2;
byte senVal3;
byte senVal4;
byte senVal_sw;

float voltage;

float pressure_pascal;
float pressure_kpa;
float pressure_psi;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  voltage = (float)(analogRead(A0) * 10) / 1023;
  pressure_pascal = (3 * ((float)voltage - 0.4)) * 100000; //* 100000.0
  pressure_kpa = (float)(pressure_pascal / 1000); //0.0012858

  pressure_psi = (float)(pressure_kpa * 0.145);
  Serial.print(analogRead(A0),1);
  Serial.print(":");
  Serial.print(voltage,1);
  Serial.print(":");
  Serial.print(pressure_pascal,1);
  Serial.print(":");
  Serial.print(pressure_kpa,1);
  Serial.print(":");
  Serial.println(pressure_psi, 0);
  

  //kpa = (float)(voltage/5-0.04)/0.0013; //0.0012858
  
//  // pascal
//  pressure_pascal = (3.0 * ((float)voltage - 0.4)) * 100000.0;
//  Serial.print(pressure_pascal);
//  Serial.print(":");
//  //bar
//  pressure_bar = pressure_pascal / 1e5;
//  Serial.print(pressure_bar);
//  Serial.print(":");
//  //psi
//  psi = (int)pressure_bar * 14.5038;
//  Serial.println(psi);
  delay(500);

}
