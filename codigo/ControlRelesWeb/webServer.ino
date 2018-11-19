#include "Reles.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


ESP8266WebServer server(80);

const char *form = 
"<HTML>"
"<head></head>"
"<body>"
"<center><form action='/'>"
"<button name='dir' type='submit' value='1'>ON Rele 1</button>"
"<button name='dir' type='submit' value='4'>ON Indicador 2</button><br>"
"<button name='dir' type='submit' value='2'>OFF Rele 1</button>"
"<button name='dir' type='submit' value='3'>OFF Indicador 2</button>"
"<br><a href=\"https://github.com/javacasm/Teleco_IOTHT/\">Codigo</a>"
"<br><img src=\"https://github.com/javacasm/Teleco_IOT/blob/master/images/Licencia_CC_peque.png?raw=true\">"
"</form></center>"
"</body>"
"</HTML>";

void handle_form()
{
    // only move if we submitted the form
    if (server.arg("dir"))
    {
        // get the value of request argument "dir"
        int direction = server.arg("dir").toInt();
        // chose direction
        switch (direction)
        {
            case 1:
                enciendeRele(RELE_1);
                break;
            case 2:
                apagaRele(RELE_1);
                break;
            case 3:
                enciendeRele(RELE_2);
                break;
            case 4:
                apagaRele(RELE_2);
                break;
        }
        // move for 300ms, gives chip time to update wifi also
        delay(300);
    }

    // in all cases send the response
    server.send(200, "text/html", form);
}

void setup_server(){
  server.on("/", handle_form);
  server.begin();

  
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop_webserver(){
  server.handleClient();
}
