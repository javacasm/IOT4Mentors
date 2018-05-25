#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "DHT.h"

LiquidCrystal_I2C lcd(0x27,16,2); // Cambiamos la direccion

DHT dht16(D4,DHT22);

void setup()
{
  lcd.begin();

  lcd.home();

  lcd.backlight();  // Activamos la iluminacion
}


void loop()
{

    lcd.display();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print((dht16.readTemperature( )));
    lcd.setCursor(0, 1);  // Ajustamos la posicion
    lcd.print("H:");
    lcd.print((dht16.readHumidity( )));
    delay(1000);

}
