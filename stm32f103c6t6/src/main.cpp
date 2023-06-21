#include <Arduino.h>

#if defined(STM32F103x6)
// blue pill
#define LED PC13
#elif defined(STM32F103xB)
// black pill
#define LED PB12
#endif

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}