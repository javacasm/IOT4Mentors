// include libraries

#include "Wifi.h"

#include "webServer.h"
#include "Reles.h"

#include "Indicator.h"

void setup(){
  Serial.begin(9600);

  setup_indicator();

  setup_Wifi();

  setup_reles();
      
  setup_server();
    
}
void loop()
{
  loop_wifi();

  loop_webserver();
     
}
