#define czujnik1 7
#define czujnik2 8
#define kolor A0
#define jasnosc A1
byte redPin = 3;
byte greenPin = 5;
byte bluePin = 9;
byte wyborKoloru = 0;
//********************************************************
void zapalSchody(void);
int ustawKolorLED(int ustawkolor);
inline void setColor(byte red, byte green, byte blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

//********************************************************
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(czujnik1, INPUT);
  pinMode(czujnik2, INPUT);
  setColor(255, 0, 0); // red
  delay(2000);
  setColor(0, 255, 0); // green
  delay(2000);
  setColor(0, 0, 255); // blue
  delay(2000);
  setColor(255, 255, 0); // yellow
  delay(2000);
  setColor(80, 0, 80); // purple
  delay(2000);
  setColor(0, 255, 255); // aqua
  delay(2000);
}
//*********************************************************
void loop()
{
  if (digitalRead(czujnik1) == LOW && digitalRead(czujnik2) == LOW) setColor(0, 0, 0);
  else zapalSchody();
}//koniec loop
//*********************************************************
void zapalSchody(void)
{
  int odczytKoloru;
  while (digitalRead(czujnik1) == HIGH)
  {
    int odczytKoloru = analogRead(kolor); //odczytaj wartosc z potencjometru 1
    wyborKoloru = ustawKolorLED(odczytKoloru);
    switch (wyborKoloru)
    {
      case 0: setColor(255, 0, 0); break;
      case 1: setColor(0, 255, 0); break;
      case 2: setColor(0, 0, 255); break;
      case 3: setColor(255, 255, 0); break;
      case 4: setColor(80, 0, 80); break;
      case 5: setColor(0, 255, 255); break;
      case 6: setColor(100, 100, 100); break;
    }//koniec switch
    delay(200);
  }
  delay(50);

  while (digitalRead(czujnik2) == HIGH)
  {
    int odczytKoloru = analogRead(kolor); //odczytaj wartosc z potencjometru 1
    wyborKoloru = ustawKolorLED(odczytKoloru);
    switch (wyborKoloru)
    {
      case 0: setColor(255, 0, 0); break;
      case 1: setColor(0, 255, 0); break;
      case 2: setColor(0, 0, 255); break;
      case 3: setColor(255, 255, 0); break;
      case 4: setColor(80, 0, 80); break;
      case 5: setColor(0, 255, 255); break;
      case 6: setColor(100, 100, 100); break;

    }//koniec switch
    delay(200);
  }//koniec while
  delay(50);
 
}//koniec zapalSchody
//*********************************************************************
int ustawKolorLED(int ustawkolor)
{
  int kolor = 0; //zmienna zwracajaca wybrany kolor
  if (ustawkolor >= 0 && ustawkolor < 150) return kolor = 0; //czerwony
  if (ustawkolor >= 140 && ustawkolor < 290) return kolor = 1; //zielony
  if (ustawkolor >= 290 && ustawkolor < 430) return kolor = 2; //nibieski
  if (ustawkolor >= 430 && ustawkolor < 570) return kolor = 3; //żółty
  if (ustawkolor >= 570 && ustawkolor < 710) return kolor = 4; //fioletowy
  if (ustawkolor >= 710 && ustawkolor < 850) return kolor = 5; //morski
  if (ustawkolor >= 850 && ustawkolor <= 1023) return kolor = 6; //biały
}




