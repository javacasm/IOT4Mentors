#define Sensor_LDR A0
#define Rele_1 D4

int iUmbralIluminacion = 500;

void setup()  {
  pinMode(Rele_1, OUTPUT);     // Activamos la salida del rele
}


void loop() {
   int valorLDR = analogRead(Sensor_LDR);
   
   if( valorLDR <= iUmbralIluminacion) {  // Si el valor del sensor LDR es menor que el umbral se activa el rele 
    digitalWrite(Rele_1,HIGH);
   } else {
    digitalWrite(Rele_1,LOW);
   }

}
