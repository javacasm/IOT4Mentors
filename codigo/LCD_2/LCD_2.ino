/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // Dirccion 0x27 16 caractares (columnas) en 2 filas
//LiquidCrystal_I2C lcd(0x30,16,2);  // Posibles direcciones alternativas
//LiquidCrystal_I2C lcd(0x3F,16,2);  // Posibles direcciones alternativas

void setup()
{
  lcd.begin();      // Inicializa  las comunicaciones con el LCD
  lcd.backlight();  // Encendemos la luz
}


void loop()
{
   for(int i = 0; i < 16 ; i += 1){
     lcd.clear(); // borramos la pantalla
     lcd.setCursor(i,0);
     lcd.print("Adios!!!");
     delay(500);
   }


}
