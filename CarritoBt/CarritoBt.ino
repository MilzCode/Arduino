#define IN1 27
#define IN2 26
#define IN3 33
#define IN4 32

#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "msrb";
const char *password = "321321321";
const char *Host = "http://192.168.43.11:8088/api/";

String fetch()
{
    if ((WiFi.status() == WL_CONNECTED))
    {
        HTTPClient http;
        http.begin(Host);
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            String payload = http.getString();
            http.end();
            return payload;
        }

        else
        {
            Serial.println("Error on HTTP request");
        }

        http.end();
        return "0";
    }
}

String dataGet = "0";

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
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
    dataGet = fetch();
    if (dataGet != "1")
    {
        dataGet = fetch();
    }
    if (dataGet != "1")
    {
        dataGet = fetch();
    }
    if (dataGet != "1")
    {
        delay(1500);
    }
    if (dataGet == "1")
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);

        delay(150);

        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);

        delay(1500);

        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);

        delay(150);

        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        delay(1500);
    }
}