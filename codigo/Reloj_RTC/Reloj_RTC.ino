/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////

// Basado en los ejemplos DS3231_set  y DS3231_test de Eric Ayars

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>


LiquidCrystal_I2C lcd(0x27,16,2);

DS3231 Clock;

bool Century=false;
bool h12;
bool PM;
//byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;
byte Year;
byte Month;
byte Date;
byte DoW;
byte Hour;
byte Minute;
byte Second;
float Temperature;

void GetDateStuff(byte& Year, byte& Month, byte& Day, byte& DoW,
    byte& Hour, byte& Minute, byte& Second) {
  // Call this if you notice something coming in on
  // the serial port. The stuff coming in should be in
  // the order YYMMDDwHHMMSS, with an 'x' at the end.
  boolean GotString = false;
  char InChar;
  byte Temp1, Temp2;
  char InString[20];

  byte j=0;
  while (!GotString) {
    if (Serial.available()) {
      InChar = Serial.read();
      InString[j] = InChar;
      j += 1;
      if (InChar == 'x') {
        GotString = true;
      }
    }
  }
  Serial.println(InString);
  // Read Year first
  Temp1 = (byte)InString[0] - '0';
  Temp2 = (byte)InString[1] - '0';
  Year = Temp1*10 + Temp2;
  // now month
  Temp1 = (byte)InString[2] - '0';
  Temp2 = (byte)InString[3] - '0';
  Month = Temp1*10 + Temp2;
  // now date
  Temp1 = (byte)InString[4] - '0';
  Temp2 = (byte)InString[5] - '0';
  Day = Temp1*10 + Temp2;
  // now Day of Week
  DoW = (byte)InString[6] -  '0';
  // now Hour
  Temp1 = (byte)InString[7] - '0';
  Temp2 = (byte)InString[8] - '0';
  Hour = Temp1*10 + Temp2;
  // now Minute
  Temp1 = (byte)InString[9] - '0';
  Temp2 = (byte)InString[10] - '0';
  Minute = Temp1*10 + Temp2;
  // now Second
  Temp1 = (byte)InString[11] - '0';
  Temp2 = (byte)InString[12] - '0';
  Second = Temp1*10 + Temp2;
}


void setup()
{
  // Configuramos el puerto serie
  Serial.begin(9600);

  // Configuramos el conector I2C
  Wire.begin();

  // Configuramos el LCD
  lcd.begin();
  lcd.home();
  lcd.backlight();
}


void lcdPrint2Digit(int digito){
  if(digito < 10)
    lcd.print("0");

  lcd.print(digito);
}

void loop()
{

// If something is coming in on the serial line, it's
  // a time correction so set the clock accordingly.

  if (Serial.available()) { // se han enviado datos por el puerto serie
    GetDateStuff(Year, Month, Date, DoW, Hour, Minute, Second);

    Clock.setClockMode(false);  // set to 24h
    //setClockMode(true); // set to 12h

    Clock.setYear(Year);
    Clock.setMonth(Month);
    Clock.setDate(Date);
    Clock.setDoW(DoW);
    Clock.setHour(Hour);
    Clock.setMinute(Minute);
    Clock.setSecond(Second);
  }



  // send what's going on to the serial monitor.
  // Start with the year
  Serial.print("2");
  if (Century) {      // Won't need this for 89 years.
    Serial.print("1");
  } else {
    Serial.print("0");
  }
  Year = Clock.getYear();
  Month = Clock.getMonth(Century);
  Hour = Clock.getHour(h12, PM);
  Minute = Clock.getMinute();
  Second = Clock.getSecond();
  Date = Clock.getDate();
  DoW = Clock.getDoW();


  Temperature = Clock.getTemperature();
  Serial.print(Year);
  Serial.print(' ');
  // then the month
  Serial.print(Month);
  Serial.print(' ');
  // then the date
  Serial.print(Date);
  Serial.print(' ');
  // and the day of the week
  Serial.print(DoW);
  Serial.print(' ');
  // Finally the hour, minute, and second
  Serial.print(Hour);
  Serial.print(' ');
  Serial.print(Minute);
  Serial.print(' ');
  Serial.print(Second);
  // Add AM/PM indicator
  if (h12) {
    if (PM) {
      Serial.print(" PM ");
    } else {
      Serial.print(" AM ");
    }
  } else {
    Serial.print(" 24h ");
  }
  // Display the temperature
  Serial.print("T=");
  Serial.print(Temperature, 2);
  // Tell whether the time is (likely to be) valid
  if (Clock.oscillatorCheck()) {
    Serial.print(" O+");
  } else {
    Serial.print(" O-");
  }
  Serial.println();

  lcd.setCursor(0, 0);
  lcdPrint2Digit(Hour);
  lcd.print(":");
  lcdPrint2Digit(Minute);
  lcd.print(":");
  lcdPrint2Digit(Second);

  lcd.setCursor(9,0);
  lcd.print("T=");
  lcd.print(Temperature);

  lcd.setCursor(0,1);

  lcdPrint2Digit(Date);
  lcd.print("/");
  lcdPrint2Digit(Month);
  lcd.print("/");
  lcdPrint2Digit(Year);
  
  delay(1000);
}

