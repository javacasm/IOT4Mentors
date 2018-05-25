#define Rele_1 D0
#define Rele_2 D4

void setup()
{
  pinMode(Rele_1, OUTPUT);
  pinMode(Rele_2, OUTPUT);

}


void loop()
{

    digitalWrite(Rele_1,HIGH);
    digitalWrite(Rele_2,LOW);
    delay(1000);
    digitalWrite(Rele_1,LOW);
    digitalWrite(Rele_2,HIGH);
    delay(1000);

}
