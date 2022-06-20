
void setup()
{
  pinMode(15, OUTPUT);
}

void loop()
{
  digitalWrite(15, true);
  delay(1000);
  digitalWrite(15, false);
  delay(1000);
}
