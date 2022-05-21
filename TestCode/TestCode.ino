// Comunication uart

// Arduino 1

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(2000);
  Serial.println("Hello World");
  delay(1000);
}

// Arduino 2

void setup()
{

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char c = Serial.read();
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}