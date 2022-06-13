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

// variables
int tempSensorValue = 0;
int lastTempSensorValue = -999;
int humSensorValue = 0;
int lastHumSensorValue = -999;
int ldrSensorValue = 0;
int lastLdrSensorValue = -999;

bool ledTempStatus = true;
bool ledLuzStatus = true;
bool ledHumStatus = true;

// Task utils

unsigned long lastTimeHum = 0;
unsigned long lastTimeLuz = 0;
unsigned long lastTimeTmp = 0;
/**
 * @brief Funcion que recibe una variable por parametro y compara si ha pasado la cantidad de tiempo especificada en el segundo parametro y devuelve true si asi.
 * Y actualiza el parametro de tiempo.
 *
 * @param t parametrode tipo unsigned long que se verificara si ha pasado el tiempo especificado de tiempo especificada en el segundo parametro y se actualizara de  ser asi.
 * @param delayMs cantidad de tiempo sobre la cual se actulizara el primer parametro y se verificara si ha pasado su cantidad de tiempo respectiva desde la ultima vez que se actualizo el primer parametro.
 * @return true: si ha pasado el tiempo especificado en el segundo parametro.
 * false: si no ha pasado el tiempo especificado en el segundo parametro.
 */
bool cmpTime(unsigned long &t, int delayMs)
{
    if ((millis() - t) >= delayMs)
    {
        t = millis();
        return true;
    }
    else if ((millis() - t) < 0)
    {
        if ((millis() - 0) >= delayMs)
        {
            t = millis();
            return true;
        }
    }
    return false;
}

// Tasks

void temperatureSensorTask()
{
    tempSensorValue = analogRead(TSENSOR);
    float temperatura = map(tempSensorValue, 20, 358, -40, 125);
    temperatura = constrain(temperatura, -40, 125);
    if (temperatura > MAXTEMP)
    {
        if (cmpTime(lastTimeTmp, 500))
        {
            ledTempStatus = !ledTempStatus;
            digitalWrite(LEDTEMPH, ledTempStatus);
            digitalWrite(LEDTEMPL, true);
        }
    }
    else if (temperatura < MINTEMP)
    {
        if (cmpTime(lastTimeTmp, 500))
        {
            ledTempStatus = !ledTempStatus;
            digitalWrite(LEDTEMPH, true);
            digitalWrite(LEDTEMPL, ledTempStatus);
        }
    }
    else
    {
        digitalWrite(LEDTEMPH, true);
        digitalWrite(LEDTEMPL, true);
    }
}

void ldrSensorTask()
{
    ldrSensorValue = analogRead(LDRSENSOR);
    float luz = map(ldrSensorValue, 0, 471, 0, 100);
    luz = constrain(luz, 0, 100);
    if (luz > MAXLDR)
    {
        if (cmpTime(lastTimeLuz, 500))
        {
            ledLuzStatus = !ledLuzStatus;
            digitalWrite(LEDLDRH, ledLuzStatus);
            digitalWrite(LEDLDRL, true);
        }
    }
    else if (luz < MINLDR)
    {
        if (cmpTime(lastTimeLuz, 500))
        {
            ledLuzStatus = !ledLuzStatus;
            digitalWrite(LEDLDRH, true);
            digitalWrite(LEDLDRL, ledLuzStatus);
        }
    }
    else
    {
        digitalWrite(LEDLDRH, true);
        digitalWrite(LEDLDRL, true);
    }
}

void humiditySensorTask()
{
    humSensorValue = analogRead(HSENSOR);
    float humedad = map(humSensorValue, 0, 850, 0, 100);
    humedad = constrain(humedad, 0, 100);
    if (humedad > MAXHUMID)
    {
        if (cmpTime(lastTimeHum, 500))
        {
            ledHumStatus = !ledHumStatus;
            digitalWrite(LEDHUMIDH, ledHumStatus);
            digitalWrite(LEDHUMIDL, true);
        }
    }
    else if (humedad < MINHUMID)
    {
        if (cmpTime(lastTimeHum, 500))
        {
            ledHumStatus = !ledHumStatus;
            digitalWrite(LEDHUMIDH, true);
            digitalWrite(LEDHUMIDL, ledHumStatus);
        }
    }
    else
    {
        digitalWrite(LEDHUMIDH, true);
        digitalWrite(LEDHUMIDL, true);
    }
}

void msgTask()
{
    // msg temperatura
    if (abs(lastTempSensorValue - tempSensorValue) > 1)
    {
        float temperatura = map(tempSensorValue, 20, 358, -40, 125);
        temperatura = constrain(temperatura, -40, 125);

        lcd.setCursor(2, 0);
        lcd.print("   ");
        lcd.setCursor(2, 0);
        lcd.print(round(temperatura));
        lastTempSensorValue = tempSensorValue;
    }

    // msg humedad
    if (abs(lastHumSensorValue - humSensorValue) > 51)
    {
        float humedad = map(humSensorValue, 0, 850, 0, 100);
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
        float luz = map(ldrSensorValue, 0, 471, 0, 100);
        luz = constrain(luz, 0, 100);
        lcd.setCursor(2, 1);
        lcd.print("   ");
        lcd.setCursor(2, 1);
        lcd.print(round(luz));
        lastLdrSensorValue = ldrSensorValue;
    }
};

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
    lcd.setCursor(2, 0);
    lcd.print("   ");
    lcd.setCursor(11, 0);
    lcd.print("   ");
    lcd.setCursor(2, 1);
    lcd.print("   ");

    pinMode(LEDTEMPH, OUTPUT);
    pinMode(LEDTEMPL, OUTPUT);
    pinMode(LEDLDRH, OUTPUT);
    pinMode(LEDLDRL, OUTPUT);
    pinMode(LEDHUMIDH, OUTPUT);
    pinMode(LEDHUMIDL, OUTPUT);

    digitalWrite(LEDTEMPH, true);
    digitalWrite(LEDTEMPL, true);
}

void loop()
{
    temperatureSensorTask();
    ldrSensorTask();
    humiditySensorTask();
    msgTask();
    delay(5);
}