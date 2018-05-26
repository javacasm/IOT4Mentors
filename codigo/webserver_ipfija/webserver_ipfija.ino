#include <ESP8266WiFi.h>

IPAddress staticIP390_10(192,168,1,10);
IPAddress gateway390_10(192,168,1,1);
IPAddress subnet390_10(255,255,255,0);

WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
   WiFi.begin("SmartCities","CitiesSmart17");
  while (((WiFi.status() == WL_CONNECTED) != true)){
    Serial.print(".");
    delay(200);

  }
  WiFi.config(staticIP390_10, gateway390_10, subnet390_10);
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
