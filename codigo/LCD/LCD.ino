/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.begin();

  lcd.home();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hola");
  lcd.setCursor(0, 1);
  lcd.print("Adios");

}


void loop()
{



}
