#include <libssh_esp32.h>



#define GPIO0 0
#define GPIO2 2
#define TXD 1
#define RXD 3

void tOnLed()
{
  while (true)
  {
    digitalWrite(GPIO2, HIGH);
    delay(1000);
    digitalWrite(GPIO2, LOW);
    delay(1000);
  }
}

void printMsg()
{
  while (true)
  {
    Serial.print("Hello World!");
    delay(1000);
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(GPIO0, OUTPUT);
  pinMode(GPIO2, OUTPUT);
  xTaskCreate(tOnLed, "tOnLed", 1024, NULL, 1, NULL);
  xTaskCreate(printMsg, "printMsg", 1024, NULL, 1, NULL);
}

void loop()
{
}
