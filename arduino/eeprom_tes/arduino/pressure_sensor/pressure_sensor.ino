///////////////////////////////////////////////////////
float senVal1;
float senVal2;
float senVal3;
float senVal4;
float senVal_sw;

float voltage;
int pressure_pascal;
int pressure_bar;
int pressure_psi;

void setup() {
  // put your setup code here, to run once:
      Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:

  senVal1 = analogRead(A0);
  senVal2 = analogRead(A1);
  senVal3 = analogRead(A2);
  senVal4 = analogRead(A3);
  senVal_sw = analogRead(A4);
  
  // voltage
  voltage = (senVal1 * 5.0) / 1024.0;
  // pascal
  pressure_pascal = (3.0*((float)voltage-0.35))*100000.0;
  //bar
  pressure_bar = pressure_pascal/1e5;
  //psi
  pressure_psi = (int)pressure_bar * 14.5038;
  Serial.print(pressure_psi);
  Serial.println(" Psi");
  delay(1000);

}
