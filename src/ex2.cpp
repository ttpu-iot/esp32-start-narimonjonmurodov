#include "Arduino.h"

#define GREEN_LED_PIN 27
#define Button_PIN 25

bool ledState = false;
bool lastButtonState = LOW;

void setup(void) 
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(Button_PIN, INPUT); 
    Serial.begin(9600);
}

void loop(void) 
{
    bool ButtonState = digitalRead(Button_PIN);

    if (ButtonState == HIGH && lastButtonState != ButtonState) 
    {
        lastButtonState = ButtonState;
        ledState = !ledState;
        digitalWrite(GREEN_LED_PIN, ledState);

        Serial.println(ledState ? "GREEN=1" : "GREEN=0");
        delay(10);
    } else if (ButtonState == LOW && lastButtonState != ButtonState) 
    {
        lastButtonState = ButtonState;
        delay(10);
    }
}