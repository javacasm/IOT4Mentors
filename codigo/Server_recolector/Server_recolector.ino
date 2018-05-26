/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

IPAddress staticIP666_30(192,168,1,15);
IPAddress gateway666_30(192,168,1,1);
IPAddress subnet666_30(255,255,255,0);

WiFiServer server(80);

String  httpurl;
String  TheHiddenAnswerOfClient;
HTTPClient http;

String SendWithAnswer(String IPcache, String monmessagecache) {
httpurl = "http://";
httpurl+=IPcache;
httpurl+="/";
httpurl+=monmessagecache;
http.begin(httpurl);
http.GET();
TheHiddenAnswerOfClient = (http.getString());
http.end();
return TheHiddenAnswerOfClient;
}

String  Dato_temperatura;

void getData(){
 Dato_temperatura = (SendWithAnswer("192.168.1.30","yes")); 
}

void showData(){
   Serial.println(Dato_temperatura);
}
void setup()
{
  Serial.begin(9600);


   WiFi.begin("SmartCities","CitiesSmart17");
  while (((WiFi.status() == WL_CONNECTED) != true)){
    Serial.print(".");
    delay(200);

  }
  WiFi.config(staticIP666_30, gateway666_30, subnet666_30);
  WiFi.hostname("Node_Base") ;
  Serial.println("");
  Serial.print("IP:");
  Serial.println((WiFi.localIP().toString()));
  server.begin();
  
  getData();
  showData();
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
    Serial.println(Dato_temperatura);
    client.println(Dato_temperatura);
    client.flush();
    delay(200);

  getData();
  showData();

}
