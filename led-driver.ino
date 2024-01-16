#define sensor1 7
#define sensor2 8
#define color A0
#define brightness A1
byte redPin = 3;
byte greenPin = 5;
byte bluePin = 9;
byte colorChoice = 0;

//********************************************************
void lightStairs(void);
int setLEDColor(int colorSetting);

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
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
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
  if (digitalRead(sensor1) == LOW && digitalRead(sensor2) == LOW)
    setColor(0, 0, 0);
  else
    lightStairs();
} // end loop
//*********************************************************
void lightStairs(void)
{
  int colorRead;
  while (digitalRead(sensor1) == HIGH)
  {
    int colorRead = analogRead(color); // read value from potentiometer 1
    colorChoice = setLEDColor(colorRead);
    switch (colorChoice)
    {
    case 0:
      setColor(255, 0, 0);
      break;
    case 1:
      setColor(0, 255, 0);
      break;
    case 2:
      setColor(0, 0, 255);
      break;
    case 3:
      setColor(255, 255, 0);
      break;
    case 4:
      setColor(80, 0, 80);
      break;
    case 5:
      setColor(0, 255, 255);
      break;
    case 6:
      setColor(100, 100, 100);
      break;
    } // end switch
    delay(200);
  }
  delay(50);

  while (digitalRead(sensor2) == HIGH)
  {
    int colorRead = analogRead(color); // read value from potentiometer 1
    colorChoice = setLEDColor(colorRead);
    switch (colorChoice)
    {
    case 0:
      setColor(255, 0, 0);
      break;
    case 1:
      setColor(0, 255, 0);
      break;
    case 2:
      setColor(0, 0, 255);
      break;
    case 3:
      setColor(255, 255, 0);
      break;
    case 4:
      setColor(80, 0, 80);
      break;
    case 5:
      setColor(0, 255, 255);
      break;
    case 6:
      setColor(100, 100, 100);
      break;
    } // end switch
    delay(200);
  } // end while
  delay(50);
} // end lightStairs
//*********************************************************************
int setLEDColor(int colorSetting)
{
  int color = 0; // variable returning the chosen color
  if (colorSetting >= 0 && colorSetting < 150)
    return color = 0; // red
  if (colorSetting >= 140 && colorSetting < 290)
    return color = 1; // green
  if (colorSetting >= 290 && colorSetting < 430)
    return color = 2; // blue
  if (colorSetting >= 430 && colorSetting < 570)
    return color = 3; // yellow
  if (colorSetting >= 570 && colorSetting < 710)
    return color = 4; // purple
  if (colorSetting >= 710 && colorSetting < 850)
    return color = 5; // aqua
  if (colorSetting >= 850 && colorSetting <= 1023)
    return color = 6; // white
}
