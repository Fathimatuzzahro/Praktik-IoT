#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

LiquidCrystal_I2C lcd(0x20, 20,4);

DS1307 rtc;

/* Simple Temperature uses the lm35 in the basic centigrade temperature configu
ration
*/
float temp;
int tempPin = 0; // analog input pin
int sampleTime = 1000; // 1 second dafault

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  rtc.begin();
  if (! rtc.isrunning()) {
    lcd.println("RTC is NOT running!");
  } else
  {
  // following line sets the RTC to the date & time this sketch was compiled
  //rtc.adjust(DateTime("01.01.2020", "00.00.00"));
  //rtc.adjust(DateTime(__DATE__, __TIME__));
    lcd.println("RTC is running!");
  }

  lcd.begin(20, 4);                    
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("microcontrolere");
  lcd.setCursor(1,1);
  lcd.print("wordpress.com");
  lcd.setCursor(1,2);
  lcd.print("LCD 20x4 I2C TEST");
  lcd.setCursor(1,3);
  lcd.print("....................");

}

void loop() {
  // put your main code here, to run repeatedly:
  {
    delay(1000);
    lcd.clear();
    delay(1000);
    DateTime now = rtc.now();
    /*
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    */
    char buf[100];
    strncpy(buf,"hh:mm:ss\0",100);
    
    //gets and prints the raw data from the lm35
    temp = analogRead(tempPin);
    //converts raw data into degrees celsius and prints it out
    // 500mV/1024=.48828125
    temp = temp * 0.48828125;
    lcd.setCursor(1,0);
    lcd.print("CELSIUS: ");
    lcd.print(temp);
    lcd.println("*C ");
    delay(500);
    lcd.setCursor(1,1);
    lcd.print("Line 2 TEST OK  ");
    delay(500);
    lcd.setCursor(1,2);
    lcd.print(now.format(buf));
    delay(500);
    lcd.setCursor(1,3);
    lcd.print("Line 4 TEST OK  ");
    delay(1000);
    }

}
