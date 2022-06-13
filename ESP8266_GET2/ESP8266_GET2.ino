#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#define SSID "VTR-8631326"
#define PASS "cdJqkmxV7ddk"
#define HOST "https://apimocha.com/esptest"

String requestData(String Type, String host, String route = "", String query = "")
{
  if (WiFi.status() == WL_CONNECTED)
  {
    WiFiClientSecure client;
    client.setInsecure();
    HTTPClient https;
    https.begin(client, host + route + "?" + query);
    https.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpCode = https.sendRequest(Type.c_str());
    if (httpCode > 0)
    {
      String payload = https.getString();
      https.end();
      return payload;
    }
    else
    {
      https.end();
      return "ERR_CODE(" + Type + "):" + String(httpCode);
    }
  }
  return "NO_CONNECTION";
}

void setup()
{
  Serial.begin(115200);
  delay(10);
  WiFi.begin(SSID, PASS);
  Serial.print("Conectando a:");
  Serial.println(SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi conectado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  Serial.println("GET");
  String payload = requestData("GET", HOST, "/info", "id=1&type=1");
  Serial.println(payload);
  delay(4000);
  Serial.println("POST");
  payload = requestData("POST", HOST, "/info", "id=1&type=1");
  Serial.println(payload);
  delay(4000);
  Serial.println("PUT");
  payload = requestData("PUT", HOST, "/info", "id=1&type=1");
  Serial.println(payload);
  delay(4000);
  Serial.println("DELETE");
  payload = requestData("DELETE", HOST, "/info", "id=1&type=1");
  Serial.println(payload);
  delay(4000);
}
