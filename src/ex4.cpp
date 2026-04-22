#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33
#define BLUE 14
#define GREEN 27
#define YELLOW 12
#define RED 26

bool B = true;
bool G = true;
bool Y = true;
bool R = true;

void setup(void) 
{
    Serial.begin(9600);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(RED, OUTPUT);
}

void reset_flags(void);
void reset(void);

void loop(void) 
{
    int value = analogRead(LIGHT_SENSOR_PIN);

    if (value >= 0 && value <= 1023)
    {
        reset();
        digitalWrite(BLUE, HIGH);
        if (B) 
        {
            Serial.println("band=BLUE");
            reset_flags();
            B = false;
        }
    } 
    else if (value >= 1024 && value <= 2047)
    {
        reset();
        digitalWrite(GREEN, HIGH);
        if (G) 
        {
            Serial.println("band=GREEN");
            reset_flags();
            G = false;
        }
    } 
    else if (value >= 2048 && value <= 3071)
    {
        reset();
        digitalWrite(YELLOW, HIGH);
        if (Y) 
        {
            Serial.println("band=YELLOW");
            reset_flags();
            Y = false;
        }
    } 
    else if (value >= 3072 && value <= 4095)
    {
        reset();
        digitalWrite(RED, HIGH);
        if (R) 
        {
            Serial.println("band=RED");
            reset_flags();
            R = false;
        }
    }
}

void reset(void) 
{
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
}

void reset_flags(void) 
{
    B = true;
    G = true;
    Y = true;
    R = true;
}