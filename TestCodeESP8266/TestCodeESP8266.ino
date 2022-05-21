#include <SoftwareSerial.h>
#define GPIO0 0
#define GPIO2 2
#define TX 1
#define RX 3
SoftwareSerial SerialArduino(GPIO2, GPIO0);

String data;

void setup()
{
  Serial.begin(115200);
  SerialArduino.begin(9600);
  SerialArduino.print("5...");
  delay(1000);
  SerialArduino.print("4...");
  delay(1000);
  SerialArduino.print("3...");
  delay(1000);
  SerialArduino.print("2...");
  delay(1000);
  SerialArduino.print("1...");
  delay(1000);
  SerialArduino.print("Go!");
}

void loop()
{
  checkSerialComunication();
  delay(500);
  if (data.length() > 0)
  {
    Serial.println("Recibido: " + data);
    if (data.indexOf("Desde Arduino") != -1)
    {
      SerialArduino.print("Recibido :D (ESP)");
    }
    data = "";
    SerialArduino.print("Desde ESP");
  }
}

void checkSerialComunication()
{

  if (SerialArduino.available() > 0)
  {
    while (SerialArduino.available() > 0)
    {
      data += (char)SerialArduino.read();
    }
  }
}

/*
Loop Basico:
  void loop()
  {
    SerialArduino.print("Desde ESP");
    delay(1000);
  }
*/