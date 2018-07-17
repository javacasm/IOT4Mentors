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
}


void loop()
{
  long msDesdeArranque = millis();
  int segundos = msDesdeArranque % 60; // el resto de dividir entre 60
  msDesdeArranque = msDesdeArranque / 60;
  int minutos = msDesdeArranque % 60;
  msDesdeArranque = msDesdeArranque / 60;
  int horas = msDesdeArranque % 24;

  lcd.setCursor(0, 0);
  if (horas < 10 ) lcd.print("0");
  lcd.print(horas);

  lcd.print(":")

  if (minutos < 10 ) lcd.print("0");
  lcd.print(minutos);

  lcd.print(":")

  if (segundos < 10 ) lcd.print("0");
  lcd.print(segundos);

  delay(1000);
}
