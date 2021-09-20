//Code for the Master board
#include<Wire.h>
//This library is used for I2C communication
int x;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); //master gak pake address
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(A0);//Reading value from Potentiometer
  x/=4;
  Wire.beginTransmission(9);
//9 here is the address of the slave board
  Wire.write(x);
//Transfers the value of potentiometer to the slave board
  Wire.endTransmission();
  Serial.print(x);
  delay(1000);

}
