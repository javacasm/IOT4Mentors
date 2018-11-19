/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

#include "DHT.h"

WiFiServer server(80);

String  texto;/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

#include "DHT.h"

WiFiServer server(80);

String  texto;
DHT dht16(D6,DHT22);

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
Serial.println(dht16.readTemperature( ));
}


void loop()
{

WiFiClient client = server.available();
if (!client) { return; }
while(!client.available()){  delay(1); }
Serial.println("Cliente conectado");
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head>");       
client.println("<Title>Datos atmosféricos</Title>");     
client.println("</head>");
client.println("<body>");
client.println("<h1 style=""color:#ff0000"">");
client.println("Datos atmosfericos");
client.println("</h1>");
texto = "Temperatura:";
texto.concat((dht16.readTemperature( )));
client.println("<span style=""color:#006600;font-size:16px"">");
client.println(texto);
client.println("</span>");
client.println("<br>");
texto = "Humedad:";
texto.concat((dht16.readHumidity( )));
client.println("<span style=""color:#000099;font-size:20px"">");
client.println(texto);
client.println("</span>");
client.println("</body>");
client.println("</html>");
delay(200);
client.stop();
delay(100);

}

DHT dht16(D6,DHT22);

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
  Serial.println(dht16.readTemperature( ));
}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");       
    client.println("<Title>Datos atmosféricos</Title>");     
    client.println("</head>");
    client.println("<body>");
      client.println("<h1 style=""color:#ff0000"">");
      client.println("Datos atmosfericos");
      client.println("</h1>");
      texto = "Temperatura:";
      texto.concat((dht16.readTemperature( )));
      client.println("<span style=""color:#660000;font-size:16px"">");
      client.println(texto);
      client.println("</span>");
      client.println("<br>");
      texto = "Humedad:";
      texto.concat((dht16.readHumidity( )));
      client.println("<span style=""color:#000099;font-size:20px"">");
      client.println(texto);
      client.println("</span>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(100);

}

