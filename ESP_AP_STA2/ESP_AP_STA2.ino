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
  server.begin();
}
void loop()
{
  server.handleClient();
}
void homeAP()
{
  server.send(200, "text/html", "<!DOCTYPE html><html lang='en'><head><button id='btn1' class='btn'>HOLA</button><button id='btn2' class='btn'>HOLA</button><style>.btn{width: 100px;height: 100px;background-color: red;cursor: pointer;border-radius: 50%;color: white;font-weight: bold;font-size: 1.5em;margin: 2em;box-shadow: 0 0 10px black;overflow: hidden;}.btn:active{transform: translateY(4px);opacity: 0.5;}body{display: flex;justify-content: center;align-items: center;background-color: #333333;}</style></head><body><script>const a=document.getElementById('btn1'),b=document.getElementById('btn2');let d=!1,e=0;function c(){d&&(a.innerHTML=e,e++),setTimeout(()=>{requestAnimationFrame(c)},10)}a.ontouchstart=function(b){b.preventDefault(),b.stopPropagation(),a.style.backgroundColor='blue',d=!0},a.ontouchend=function(b){b.preventDefault(),b.stopPropagation(),a.style.backgroundColor='red',a.innerHTML='HOLA',d=!1},a.ontouchmove=function(b){if(b.preventDefault(),b.stopPropagation(),d){let c=b.touches[0],e=c.clientX,f=c.clientY,g=a.offsetLeft,h=a.offsetTop,i=a.offsetWidth,j=a.offsetHeight;(e<g||e>g+i||f<h||f>h+j)&&(b.preventDefault(),b.stopPropagation(),a.style.backgroundColor='red',a.innerHTML='HOLA',d=!1)}},b.ontouchstart=function(a){a.preventDefault(),a.stopPropagation(),b.style.backgroundColor='blue'},b.ontouchend=function(a){a.preventDefault(),a.stopPropagation(),b.style.backgroundColor='red'},c()</script></body></html>");
}
