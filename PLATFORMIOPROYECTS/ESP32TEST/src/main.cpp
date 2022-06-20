#include <Arduino.h>

void setup()
{
  pinMode(15, OUTPUT);
}

void loop()
{
  digitalWrite(15, true);
  delay(500);
  digitalWrite(15, false);
  delay(500);
}