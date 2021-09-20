#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 20,4);

void setup() {
  // put your setup code here, to run once:
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
    lcd.setCursor(1,0);
    lcd.print("Line 1");
    delay(500);
    lcd.setCursor(1,1);
    lcd.print("Line 2");
    delay(500);
    lcd.setCursor(1,2);
    lcd.print("Line 3");
    delay(500);
    lcd.setCursor(1,3);
    lcd.print("Line 4");
    delay(1000);
    lcd.setCursor(1,0);
    lcd.print("Line 1 TEST OK  ");
    lcd.setCursor(1,1);
    lcd.print("Line 2 TEST OK  ");
    lcd.setCursor(1,2);
    lcd.print("Line 3 TEST OK  ");
    lcd.setCursor(1,3);
    lcd.print("Line 4 TEST OK  ");
    delay(2000);
    }

}
