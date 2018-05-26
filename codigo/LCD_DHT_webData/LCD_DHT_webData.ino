#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>

#include "DHT.h"

LiquidCrystal_I2C lcd(0x27,16,2); // Cambiamos la direccion

DHT dht16(D6,DHT22);

int iNumeroConexiones = 0;

WiFiServer server(80);

IPAddress staticIP666_30(192,168,1,30);
IPAddress gateway666_30(192,168,1,1);
IPAddress subnet666_30(255,255,255,0);  

float temperatura, humedad;
void setup()
{
  lcd.begin();

  lcd.home();

  lcd.backlight();  // Activamos la iluminacion

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

void getData(){
  temperatura = dht16.readTemperature( );
  humedad = dht16.readHumidity(); 
}

void showData(){
    lcd.display();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperatura);
    lcd.print("  H:");
    lcd.print(humedad);

    lcd.setCursor(0,1);
    lcd.print("Conexiones:");
    lcd.print(iNumeroConexiones);
    Serial.print("Temp:");
    Serial.println(temperatura);
    Serial.print("Hum:");
    Serial.println(humedad);    
    Serial.print(iNumeroConexiones);
    Serial.println(" conexiones");
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
    client.println(temperatura);
    client.println("</body>");
    client.println("</html>");
    client.println("");
    client.flush();
    iNumeroConexiones++;
    delay(200);
   // client.stop();
    delay(100);
    
    getData();
    showData();
}
