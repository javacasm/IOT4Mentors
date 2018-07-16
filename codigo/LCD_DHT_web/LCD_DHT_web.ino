#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>

#include "DHT.h"

LiquidCrystal_I2C lcd(0x27,16,2); // Cambiamos la direccion

DHT dht16(D6,DHT22);    // Conectamos el sensor DHT al pin D6

int iNumeroConexiones = 0;  // Guardamos las conexiones web que se han hecho

WiFiServer server(80);

String  texto;
float temperatura, humedad;
void setup()
{
  lcd.begin();

  lcd.home();

  lcd.backlight();  // Activamos la iluminacion

    Serial.begin(9600);


   WiFi.begin("SmartCities","CitiesSmart17");
  while (((WiFi.status() == WL_CONNECTED) != true)){
    Serial.print(".");  // imprimimos "." hasta que se conecte al wifi
    delay(200);

  }
  WiFi.hostname("Node_Base") ;
  Serial.println("");
  Serial.print("IP:");
  Serial.println((WiFi.localIP().toString()));
  lcd.print((WiFi.localIP().toString()));
  delay(1000); // Mostramos la ip durante 1 segundo
  server.begin();

  temperatura = dht16.readTemperature( );
  humedad = dht16.readHumidity();

  showTemperatura();
}


void showTemperatura(){
    lcd.display();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperatura);
    lcd.print("  H:");
    lcd.print(humedad);

    lcd.setCursor(0,1);
    lcd.print("Conexiones:");
    lcd.print(iNumeroConexiones);

    Serial.print(temperatura);
    Serial.print(",");
    Serial.print(humedad);
    Serial.print(",");
    Serial.println(iNumeroConexiones));
}

void loop()
{

   WiFiClient client = server.available();
    if (!client) {   // Si no hay clientes conectados actualizamos los datos
      temperatura = int(dht16.readTemperature( ));
      humedad = dht16.readHumidity();
      showTemperatura();
      delay(200);
      return;
    }
    while(!client.available()){
		delay(1);
	}
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
      texto.concat(int(temperatura));
      client.println("<span style=""color:#660000;font-size:20px"">");
      client.println(texto);
      client.println("</span>");
      client.println("<br>");
      texto = "Humedad:";
      texto.concat(humedad);
      client.println("<span style=""color:#000099;font-size:20px"">");
      client.println(texto);
      client.println("</span>");
    client.println("</body>");
    client.println("</html>");
    client.println("");
    client.flush();
    iNumeroConexiones++;
    delay(200);
   // client.stop();
    delay(100);
}
