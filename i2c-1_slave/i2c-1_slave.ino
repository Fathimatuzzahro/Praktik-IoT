#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8); // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);

}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write("hello "); // respond with message of 6 bytes
  // as expected by master
  }
