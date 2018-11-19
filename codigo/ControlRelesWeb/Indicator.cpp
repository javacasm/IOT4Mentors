
#include <Arduino.h>

#define LED_INDICATOR LED_BUILTIN

void setup_indicator(){
  pinMode(LED_INDICATOR,OUTPUT);  
}

void blinkIndicator(){
  digitalWrite(LED_INDICATOR,!digitalRead(LED_INDICATOR));
}
