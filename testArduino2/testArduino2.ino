#include <DHT.h>
#include <DHT_U.h>

// Arduino sensor de temperatura dHt 11 en el pin 7

DHT dht(7, DHT11);

void setup()
{
  Serial.begin(9600);
  pinMode(7,INPUT);
  dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
  delay(2000);
}
