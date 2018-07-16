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

void setup() {
  lcd.begin();      // Inicializa  las comunicaciones con el LCD

  lcd.home();       // Pone el cursor en 0,0
  lcd.backlight();  // Encendemos la luz
  lcd.setCursor(0, 0);  //Posicionamos el cursor arriba a la izquierda
  lcd.print("Hola");
  lcd.setCursor(0, 1); //Posicionamos el cursor al principio de la segunda fila
  lcd.print("Adios");

}


void loop() {
  // El codigo solo se ejecuta 1 vez en setup


}
