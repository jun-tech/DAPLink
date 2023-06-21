#include <Arduino.h>

#define LED 25

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.print(result);

  pinMode(LED, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print("Hello World");

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}