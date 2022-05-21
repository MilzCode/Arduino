#include <Arduino.h>
#line 1 "C:\\Users\\brsmi\\OneDrive\\Documentos\\Arduino\\TestArduino\\TestArduino.ino"
#include <SoftwareSerial.h>
SoftwareSerial SerialEsp(8, 7); // //pines que conectan a (Tx,RX) del otro dispositivo

String data;



#line 8 "C:\\Users\\brsmi\\OneDrive\\Documentos\\Arduino\\TestArduino\\TestArduino.ino"
void setup();
#line 18 "C:\\Users\\brsmi\\OneDrive\\Documentos\\Arduino\\TestArduino\\TestArduino.ino"
void loop();
#line 30 "C:\\Users\\brsmi\\OneDrive\\Documentos\\Arduino\\TestArduino\\TestArduino.ino"
void sayBtn1();
#line 36 "C:\\Users\\brsmi\\OneDrive\\Documentos\\Arduino\\TestArduino\\TestArduino.ino"
void checkSerialComunication();
#line 8 "C:\\Users\\brsmi\\OneDrive\\Documentos\\Arduino\\TestArduino\\TestArduino.ino"
void setup()
{
  Serial.begin(115200);
  SerialEsp.begin(9600);
  pinMode(2, INPUT_PULLUP) ;
  attachInterrupt(digitalPinToInterrupt(2), sayBtn1, RISING);


}

void loop()
{
  
  checkSerialComunication();
  delay(500);
  if (data.length() > 0)
  {
    Serial.println("Recibido: " + data);
    data = "";
  }
}

void sayBtn1(){
  SerialEsp.print("Desde Arduino");
  delay(200);
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
*/

