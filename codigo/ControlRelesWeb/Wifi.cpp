
#include <JeVe_EasyOTA.h>  // https://github.com/jeroenvermeulen/JeVe_EasyOTA/blob/master/JeVe_EasyOTA.h

#include "Config.h"   // Configuración del wifi

#include "Indicator.h"

EasyOTA OTA;

void setup_Wifi(){
  // This callback will be called when JeVe_EasyOTA has anything to tell you.
  OTA.onMessage([](char *message, int line) {
    Serial.println(message);
  });
  
  OTA.setup(ssid, password, ARDUINO_HOSTNAME);  

  // connect
  while (WiFi.status() != WL_CONNECTED)
  {
      delay(200);
      Serial.print(".");
      blinkIndicator();
      
  }

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop_wifi(){
  // OTA
  OTA.loop();
}
