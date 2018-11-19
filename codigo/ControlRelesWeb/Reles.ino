#include "Reles.h"
#include <Arduino.h>

void setup_reles(){
    pinMode(RELE_1, OUTPUT); 
    pinMode(RELE_2, OUTPUT); 
}


void apagaRele(int pinRele){
    if(pinRele == D1 ) Serial.print("D1");
    else Serial.print("D4");
    Serial.println(" Off");
    
    digitalWrite(pinRele, LOW);
}

void enciendeRele(int pinRele){
    if(pinRele == D1 ) Serial.print("D1");
    else Serial.print("D4");
    Serial.println(" On");  
    digitalWrite(pinRele, HIGH);
}
