#define GPIO0 0
#define GPIO2 2
#define TX 1
#define RX 3

void setup()
{
  // Opcional si no funcion a usa el FUNCTION_3
  // pinMode(TX, FUNCTION_3);
  pinMode(TX, OUTPUT);
  // pinMode(RX, FUNCTION_3);
  pinMode(RX, OUTPUT);
}

void loop()
{
  digitalWrite(TX, true);
  if (digitalRead(TX))
  {
    digitalWrite(RX, true);
    delay(500);
    digitalWrite(RX, false);
    delay(500);
    digitalWrite(RX, true);
    delay(500);
    digitalWrite(RX, false);
    delay(500);
  }
  digitalWrite(TX, false);
  delay(1000);
}