#include "Arduino.h"

#define BUTTON 25
#define LIGHT_SENSOR_PIN 33
#define YELLOW_LED 12

bool is_button_pressed = false;

void setup(void) 
{
    Serial.begin(9600);
    pinMode(BUTTON, INPUT);
    pinMode(YELLOW_LED, OUTPUT);
}

void loop(void){
    bool current_button_state = digitalRead(BUTTON);
    if (current_button_state == HIGH && !is_button_pressed)
    {
        is_button_pressed = true;
        int value = analogRead(LIGHT_SENSOR_PIN);
        Serial.print("snapshot= ");
        Serial.println(value);
        digitalWrite(YELLOW_LED, HIGH);
        delay(200);
        digitalWrite(YELLOW_LED, LOW);
    }
    else if (current_button_state == LOW && is_button_pressed)
    {
        is_button_pressed = false;
        delay(10);
    }
}