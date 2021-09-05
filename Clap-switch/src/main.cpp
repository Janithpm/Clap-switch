#include <Arduino.h>

#define ledPin 3
#define sensorPin 2
int clapCount;
int sensorReading = 0;
bool lightState = false;
long countigRange, detectionRange;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}
void loop()
{
  sensorReading = digitalRead(sensorPin);
  if (sensorReading == 1)
  {
    if ((millis() - countigRange) > 100)
    {
      clapCount++;
      Serial.println(clapCount);
      countigRange = millis();
    }
  }
  if ((millis() - detectionRange) > 1000)
  {
    if (clapCount == 2)
    {
      lightState = !lightState;
      if (lightState)
      {
        digitalWrite(ledPin, HIGH);
      }
      else
      {
        digitalWrite(ledPin, LOW);
      }
    }
    clapCount = 0;
    detectionRange = millis();
  }
}
