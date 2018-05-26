/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
   WiFi.begin("SmartCities","CitiesSmart17");
  while (((WiFi.status() == WL_CONNECTED) != true)){
    Serial.print(".");
    delay(200);

  }
  WiFi.hostname("Node_Base") ;
  Serial.println("");
  Serial.print("IP:");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.flush();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("");
    client.println("</html>");
    client.stop();
    delay(1);

}
