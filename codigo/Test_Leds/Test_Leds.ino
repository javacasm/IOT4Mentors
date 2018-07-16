
int espera = 1000; // Tiempo es parpadeo


void setup() {
  pinMode(D4, OUTPUT); // Configuramos las patillas D0 y D4 como salida
  pinMode(D0, OUTPUT);

}


void loop() {

    digitalWrite(D4,HIGH);
    digitalWrite(D0,LOW);
    delay(espera); // Esperamos un tiempo para poder apreciar el parpadeo
    digitalWrite(D4,LOW);
    digitalWrite(D0,HIGH);
    delay(espera);

}
