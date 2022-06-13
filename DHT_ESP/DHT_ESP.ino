/**** Incluir librerías necesarias ****/
#include <ESP8266WiFi.h>
#include <DHT.h>

/*** Definiendo el modelo de sensor y el pin al que estará conectado ***/
#define DHTTYPE DHT11 //DHT21, DHT22
#define DHTPIN  2 // GPIO2

DHT dht(DHTPIN, DHTTYPE, 27); // 11 works fine for ESP8266 threshold => MHZ CPU

/*** Variables para Humedad y Temperatura ****/
float temperatura; // double
float humedad;

void setup()
{
  Serial.begin(115200);
  dht.begin();
  
}// EOF setup()

void loop(){
   temperatura = dht.readTemperature();
   humedad = dht.readHumidity();
   Serial.println("**********************************************************************************");
   Serial.print("Temperatura actual: ");
   Serial.print(temperatura);
   Serial.println("°C");
   Serial.print("Humedad actual: "); 
   Serial.print(humedad, 4);
   Serial.println("%");
   Serial.println("**********************************************************************************");
   Serial.println();
   
   delay(5000);
} // EOF loop()
