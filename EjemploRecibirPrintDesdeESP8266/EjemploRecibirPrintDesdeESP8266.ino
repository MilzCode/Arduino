/**********************************************************************************
 * TITULO: Código Arduino de comunicación con ESP8266 Serial #1
 * AUTOR: Jhimmy Astoraque Durán
 * DESCRIPCION: Este es el código del capítulo 2 de la serie intermedia ESP82266 del canal.
 * CANAL YOUTUBE: https://www.youtube.com/c/jadsatv
 * © 2018
 * *******************************************************************************/

#include <SoftwareSerial.h>
SoftwareSerial SerialEsp(3, 2); // //pines que conectan a (Tx,RX) del otro dispositivo


char data;

void setup()
{
  Serial.begin(115200);
  SerialEsp.begin(9600);
}

 
void loop()
{
  checkSerialCom();
  delay(500);
}

void checkSerialCom(){

  if(SerialEsp.available() > 0){ // Checks whether data is comming from the serial port
    Serial.print("Recibido: ");
    while(SerialEsp.available() > 0){
      data = (char)SerialEsp.read(); // Reads the data from the serial port
      Serial.print(data);
    }
  }
} // EOF checkSerialCom
