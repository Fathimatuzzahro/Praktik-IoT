#include <Wire.h> //inisialisasi library I2C

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600); // start serial for output
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8, 6); // request 6 bytes from slave device #8
  
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c); // print the character
  }
  delay(500);
}
