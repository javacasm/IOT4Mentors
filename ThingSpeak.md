# Publicación en ThingSpeak

![](./images/ThingSpeak_1.png)

ThingSpeak es una servicio web que nos permite publicar datos de las medidas de nuestros dispositivos IOT (o de cualquier otro).

Es gratuito para cierto número de datos y nos permite de manera muy sencilla subir datos

## Creación del canal (Channel)

* Nos hacemos una cuenta en ThingSpeak, recibiremos un email y lo verificamos

* Entramos en Channels->My Channels y pulsamos en "New Channel"

![ThingSpeak New Channel](./images/ThingSpeak_New_Channel.png)

* Configuraremos el canal, indicando los datos que se van a enviar. Podemos añadir una descripción y datos como la web, canal de youtube, etc...

![Configuracion canal](./images/ThingSpeak_Configuracion_Canal.png)

* Para poder enviar datos al canal necesitamos el API KEY que lo identifica que incluiremos en nuestro código

![ThingSpeak API Keys](./images/ThingSpeak_API_Keys.png)

* Para que cualquiera pueda ver los datos, podemos hacer que el canal sea público, desde la pestaña Sharing

![sharing](./images/ThingSpeak_Canal_Publico.png)

* Una vez creado el canal podemos configurar los detalles de cada gráfico, para lo que pulsaremos sobre el icono "lapiz" de cada uno

* En cualquier momento podemos importar/exportar los datos de un gráfico dado

![ThingSpeak Import-Export](./images/ThingSpeak_Import-Export.png)

![ThingSpeak Configuracion Grafico](./images/ThingSpeak_Configuracion_Grafico.png)

## Código 

Para subir datos usaremos la librería ciao de Arduino UNO Wifi y haremos una petición a su web construyendo una URL con nuestra API Key (que hemos obtenido al Canal) y los datos.

Un código básico sería algo así:


 ```C++

      #include <ESP8266WiFi.h>

      #include <ESP8266HTTPClient.h>

      IPAddress staticIP199_10(192,168,1,10);
      IPAddress gateway199_10(192,168,1,1);
      IPAddress subnet199_10(255,255,255,0);

      WiFiClient client;

      String thingSpeakAddress= "http://api.thingspeak.com/update?";
      String writeAPIKey;
      String tsfield1Name;
      String request_string;

      HTTPClient http;

      void setup()
      {
          Serial.begin(9600);
          WiFi.disconnect();
          delay(3000);
          Serial.println("START");
          WiFi.begin("my-net","");
          while ((!(WiFi.status() == WL_CONNECTED))){
            delay(300);
            Serial.print("..");
          }
          Serial.println("Connected");
          WiFi.config(staticIP199_10, gateway199_10, subnet199_10);
          Serial.println("Your IP is");
          Serial.println((WiFi.localIP().toString()));
      }


      void loop()
      {
        // Falta leer los sensores
        if (client.connect("api.thingspeak.com",80)) {
          request_string = thingSpeakAddress;
          request_string += "key=";
          request_string += "CLAVE_KEY";
          request_string += "&field1=";
          request_string += "Valor1";
          request_string += "&field2=";
          request_string += "Valor2";
          request_string += "&field3=";
          request_string += "Valor3";

          http.begin(request_string);
          http.GET();
          http.end();
          request_string="";

        }

      }
```
