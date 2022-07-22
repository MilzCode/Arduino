#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "Piso1NSNet";
const char *password = "Panconqueso2.4";

void fetch(String type, String url, String params = "")
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.begin(url + "?" + params);
        if (type == "GET")
        {
            int httpCode = http.GET();
            if (httpCode > 0)
            {
                String payload = http.getString();
                Serial.println(payload);
            }
            else
            {
                Serial.println("Error on HTTP request");
            }
        }
        else if (type == "POST")
        {
            http.addHeader("Content-Type", "application/json");
            int httpCode = http.POST("{\"name\":\"John\",\"age\":30,\"car\":null}");

            if (httpCode > 0)
            {
                String payload = http.getString();
                Serial.println(payload);
            }
            else
            {
                Serial.println("Error on HTTP request");
            }
        }
        http.end();
    }
}

void setup()
{

    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    Serial.println("Connected to the WiFi network");
}

void loop()
{
    fetch("GET", "http://192.168.1.123:3000/api", "id=1&type=1");
    delay(6000);
    fetch("POST", "http://192.168.1.123:3000/api", "id=1&type=1");
    delay(6000);
}