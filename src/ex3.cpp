#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
    int value = analogRead(LIGHT_SENSOR_PIN);

    Serial.print("raw=");
    Serial.println(value);

    delay(500);
}