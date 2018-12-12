#define LED_PWM D6


int iUmbralHumedad = 500;
void setup()  {
 
}


void loop() {
   for (int i = 0 ; i < 1023 ; i++){ // vamos subiendo el nivel de brillo
      analogWrite(LED_PWM,i);
      delay(100); // damos un tiempo para que se vea el cambio
   }

   for (int i = 1023;i >= 0; i++){  // vamos bajando el nivel de brillo
      analogWrite(LED_PWM,i);
      delay(100); // damos un tiempo para que se vea el cambio
   }

}
