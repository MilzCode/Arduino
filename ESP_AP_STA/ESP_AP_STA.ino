#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define SSIDAP "ESP01-01"
#define PASSAP "321321321"
#define SSID "Piso1NSNet"
#define PASS "Panconqueso2.4"

ESP8266WebServer server(80);

void homeAP();

void setup()
{
  Serial.begin(115200);
  // Setting mode ESP8266
  WiFi.mode(WIFI_AP_STA);
  // Setting AP
  WiFi.softAP(SSIDAP, PASSAP);

  while (!WiFi.softAP(SSIDAP, PASSAP))
  {
    delay(100);
  }

  // Setting STA
  bool conectado = false;
  WiFi.begin(SSID, PASS);
  byte intentos = 0;
  while (WiFi.status() != WL_CONNECTED && SSID != "false")
  {
    conectado = true;
    Serial.print("Intento: ");
    Serial.println(intentos);
    delay(1000);
    intentos++;
    if (intentos > 15)
    {
      conectado = false;
      break;
    }
  }
  Serial.println("MODO AP");
  Serial.println("Access point Creado");
  Serial.print("IP address host: ");
  Serial.println(WiFi.softAPIP());
  if (conectado)
  {
    Serial.println("MODO STA");
    Serial.println("Conectado a " + String(SSID));
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else
  {
    Serial.println("MODO STA");
    Serial.println("No se pudo conectar a: " + String(SSID));
  }
  server.on("/", homeAP);
  server.on("/args", handleGenericArgs);
  server.begin();
}
void loop()
{
  server.handleClient();
}
void homeAP()
{
  server.send(200, "text/plain", "Hola mundo");
}

void handleGenericArgs()
{ // Handler

  String message = "Number of args received :";
  message += server.args(); // Get number of parameters
  message += "\n";          // Add a new line

  for (int i = 0; i < server.args(); i++)
  {

    message += "Arg nº" + (String)i + " –> "; // Include the current iteration value
    message += server.argName(i) + ": ";      // Get the name of the parameter
    message += server.arg(i) + "\n";          // Get the value of the parameter
  }

  server.send(200, "text / plain", message); // Response to the HTTP request
}
