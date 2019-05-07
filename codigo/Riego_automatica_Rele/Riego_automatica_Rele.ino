#define Sensor_Humedad A0
#define Rele_1 D4

int iUmbralHumedad = 500;

void setup()  {
  pinMode(Rele_1, OUTPUT);     // Activamos la salida del rele
}


void loop() {
   int valorHumedad = analogRead(Sensor_Humedad);
   
   if( valorHumedad <= iUmbralHumedad) {  // Si el valor de humedad es menor que el umbral se activa el rele 
    digitalWrite(Rele_1,HIGH);
   } else {
    digitalWrite(Rele_1,LOW);
   }

}
