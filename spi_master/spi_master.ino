#include <SPI.h>

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(115200); //set baud rate to 115200 for usart
  digitalWrite(SS, HIGH); // disable Slave Select
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV8);//divide the clock by 8
  //untuk UNO 16MHz/8 --> 2MHz
}

void loop(void) {
  // put your main code here, to run repeatedly:
  char c; //untuk menyimpan karakter
  digitalWrite(SS, LOW); // enable Slave Select, diset low dulu biar bisa membaca data
  // send test string
  for (const char * p = "Hello, world!\r" ; c = *p; p++) {
    SPI.transfer (c);
    Serial.print(c);
  }
  digitalWrite(SS, HIGH); // disable Slave Select
  delay(2000);

}
