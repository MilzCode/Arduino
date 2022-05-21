#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>
// sensores
#define TSENSOR A0
#define HSENSOR A1
#define LDRSENSOR A2
// leds
#define LEDTEMPH 10
#define LEDTEMPL 9
#define LEDHUMIDH 11
#define LEDHUMIDL 8
#define LEDLDRH 12
#define LEDLDRL 7
// Rangos de temperatura
#define MAXTEMP 30
#define MINTEMP 20
// Rangos de humedad
#define MAXHUMID 80
#define MINHUMID 60
// Rangos de luz
#define MAXLDR 70
#define MINLDR 50
LiquidCrystal lcd(1, 2, 3, 4, 5, 6);
// utils for FreeRTOS
void Delay(int ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}
void NewTask(void (*task)(), String name, int priority = 2, int stackSize = NULL)
{
    if (stackSize == NULL)
        stackSize = configMINIMAL_STACK_SIZE;
    xTaskCreate(task, name.c_str(), stackSize, NULL, priority, NULL);
}
// variables
int tempSensorValue = 0;
int lastTempSensorValue = 0;
int humSensorValue = 0;
int lastHumSensorValue = 0;
int ldrSensorValue = 0;
int lastLdrSensorValue = 0;
// tasks for FreeRTOS
void temperatureSensorTask()
{
    while (true)
    {
        tempSensorValue = analogRead(TSENSOR);
        float temperatura = map(tempSensorValue, 0, 308, 0, 150);
        temperatura = constrain(temperatura, 0, 150);
        if (temperatura > MAXTEMP)
        {
            digitalWrite(LEDTEMPH, LOW);
            Delay(200);
            digitalWrite(LEDTEMPH, HIGH);
            Delay(200);
        }
        else if (temperatura < MINTEMP)
        {
            digitalWrite(LEDTEMPL, LOW);
            Delay(200);
            digitalWrite(LEDTEMPL, HIGH);
            Delay(200);
        }
        else
        {
            digitalWrite(LEDTEMPH, HIGH);
            digitalWrite(LEDTEMPL, HIGH);
            Delay(200);
        }
    }
}
void humiditySensorTask()
{
    while (true)
    {
        humSensorValue = analogRead(HSENSOR);
        float humedad = map(humSensorValue, 0, 1023, 0, 100);
        humedad = constrain(humedad, 0, 100);

        if (humedad > MAXHUMID)
        {
            digitalWrite(LEDHUMIDH, LOW);
            Delay(200);
            digitalWrite(LEDHUMIDH, HIGH);
            Delay(200);
        }
        else if (humedad < MINHUMID)
        {
            digitalWrite(LEDHUMIDL, LOW);
            Delay(200);
            digitalWrite(LEDHUMIDL, HIGH);
            Delay(200);
        }
        else
        {
            digitalWrite(LEDHUMIDH, HIGH);
            digitalWrite(LEDHUMIDL, HIGH);
            Delay(200);
        }
    }
}
void lightSensorTask()
{
    while (true)
    {
        ldrSensorValue = analogRead(LDRSENSOR);
        float luz = map(ldrSensorValue, 10, 975, 0, 100);
        luz = constrain(luz, 0, 100);
        if (luz > MAXLDR)
        {
            digitalWrite(LEDLDRH, LOW);
            Delay(200);
            digitalWrite(LEDLDRH, HIGH);
            Delay(200);
        }
        else if (luz < MINLDR)
        {
            digitalWrite(LEDLDRL, LOW);
            Delay(200);
            digitalWrite(LEDLDRL, HIGH);
            Delay(200);
        }
        else
        {
            digitalWrite(LEDLDRH, HIGH);
            digitalWrite(LEDLDRL, HIGH);
            Delay(200);
        }
    }
}
void msgTask()
{
    while (true)
    {

        // msg temperatura
        if (abs(tempSensorValue - lastTempSensorValue) > 1)
        {
            float temperatura = map(tempSensorValue, 0, 308, 0, 150);
            temperatura = constrain(temperatura, 0, 150);

            lcd.setCursor(2, 0);
            lcd.print("   ");
            lcd.setCursor(2, 0);
            lcd.print(round(temperatura));
            lastTempSensorValue = tempSensorValue;
        }

        // msg humedad
        if (abs(lastHumSensorValue - humSensorValue) > 51)
        {
            float humedad = map(humSensorValue, 0, 1023, 0, 100);
            humedad = constrain(humedad, 0, 100);
            lcd.setCursor(11, 0);
            lcd.print("   ");
            lcd.setCursor(11, 0);
            lcd.print(round(humedad));
            lastHumSensorValue = humSensorValue;
        }

        // msg luz
        if (abs(lastLdrSensorValue - ldrSensorValue) > 0)
        {
            float luz = map(ldrSensorValue, 10, 975, 0, 100);
            luz = constrain(luz, 0, 100);
            lcd.setCursor(2, 1);
            lcd.print("   ");
            lcd.setCursor(2, 1);
            lcd.print(round(luz));
            lastLdrSensorValue = ldrSensorValue;
        }
        Delay(500);
    }
}
// main
void setup()
{
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.setCursor(5, 0);
    lcd.print("C | H:");
    lcd.setCursor(14, 0);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("L:");
    lcd.setCursor(5, 1);
    lcd.print("%");
    // Default Temp
    lcd.setCursor(2, 0);
    lcd.print("   ");
    // Default Hum
    lcd.setCursor(11, 0);
    lcd.print("   ");
    // Default Luz
    lcd.setCursor(2, 1);
    lcd.print("   ");
    // pinModes
    pinMode(TSENSOR, INPUT);
    pinMode(HSENSOR, INPUT);
    pinMode(LDRSENSOR, INPUT);
    pinMode(LEDTEMPH, OUTPUT);
    pinMode(LEDTEMPL, OUTPUT);
    pinMode(LEDHUMIDH, OUTPUT);
    pinMode(LEDHUMIDL, OUTPUT);
    // tasks
    NewTask(temperatureSensorTask, "temperatureSensorTask");
    NewTask(humiditySensorTask, "humiditySensorTask");
    NewTask(lightSensorTask, "lightSensorTask");
    NewTask(msgTask, "msgTask", 1);
    // Outputs Default
    digitalWrite(LEDHUMIDH, HIGH);
    digitalWrite(LEDHUMIDL, HIGH);
    digitalWrite(LEDTEMPH, HIGH);
    digitalWrite(LEDTEMPL, HIGH);
    digitalWrite(LEDLDRH, HIGH);
    digitalWrite(LEDLDRL, HIGH);
}
void loop()
{
}
