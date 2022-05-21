#include <SoftwareSerial.h>
SoftwareSerial SerialEsp(3, 2); // //pines que conectan a (Tx,RX) del otro dispositivo

String data;

void setup()
{
  Serial.begin(115200);
  SerialEsp.begin(9600);
}

void loop()
{
  checkSerialComunication();
  delay(500);
  if (data.length() > 0)
  {
    Serial.println("Recibido: " + data);
    data = "";
    SerialEsp.print("Desde Arduino");
    
  }
}

void checkSerialComunication()
{

  if (SerialEsp.available() > 0)
  {
    while (SerialEsp.available() > 0)
    {
      data += (char)SerialEsp.read();
    }
  }
}

/*
A veces la comunicacion se corta (aunque poco frecuente) y la data se recibe mal ejemplo:
  Recibido: Hello World
  Recibido: Hell
  Recibido: o World
  Recibido: Hello World
  Recibido: Hello World

Posible Idea para solucionarlo:
  Utilizar un tag de apertura y cierre para identificar el inicio y fin de la data y solo alli limpiar la data,
  y confirmar el recibido.

A veces la información (caracteres) se corrompen (aunque poco frecuente) y la data se recibe mal lo que podria afectar al recibo del tag, ejemplo:
  Recibido: Desde ESP
  Recibido: Desde ESP
  Recibido: D敁
  Recibido: ESP
  Recibido: Desde ESP
  Recibido: Desde ESP
Posible Idea para solucionarlo:
  Enviar la misma data más de una vez, y verificar que se reciba correctamente.
*/

*/