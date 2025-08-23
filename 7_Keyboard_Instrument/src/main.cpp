#include <Arduino.h>

int notes[] = {262, 294, 330, 349};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int keyValue = analogRead(A0);
  Serial.println(keyValue);

  if (keyValue == 1023)
  {
    tone(8, notes[0]);
  }
  else if (keyValue >= 1000 && keyValue <= 1010)
  {
    tone(8, notes[1]);
  }
  else if (keyValue >= 930 && keyValue <= 940)
  {
    tone(8, notes[2]);
  }
  else if (keyValue >= 505 && keyValue <= 515)
  {
    tone(8, notes[3]);
  }
  else if (keyValue >= 5 && keyValue <= 10)
  {
    tone(8, notes[3]);
  }
  else
  {
    noTone(8);
  }
}
