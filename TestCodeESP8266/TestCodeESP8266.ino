#define GPIO0 0
#define GPIO2 2
#define TX 1
#define RX 3

unsigned long currentTime = 0;
unsigned long lasTime1 = 0;
unsigned long lasTime2 = 0;
bool led1State = false;
bool led2State = false;

void setup()
{
  Serial.begin(9600);
  pinMode(GPIO0, OUTPUT);
  pinMode(GPIO2, OUTPUT);
}

void loop()
{
  currentTime = millis();
  if (currentTime - lasTime1 > 1000)
  {
    led1State = !led1State;
    digitalWrite(GPIO0, led1State);
    lasTime1 = currentTime;
  }
  if (currentTime - lasTime2 > 2000)
  {
    led2State = !led2State;
    digitalWrite(GPIO2, led2State);
    lasTime2 = currentTime;
  }
}
