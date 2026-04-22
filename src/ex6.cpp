#include "Arduino.h"
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

#define BLUE 14
hd44780_I2Cexp lcd;
bool blueState = false;

void setup() {
    pinMode(BLUE, OUTPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("B -> BLUE ON");
    lcd.setCursor(0, 1);
    lcd.print("b -> BLUE OFF");
}

void loop() {
    if (Serial.available() > 0) {
        char cmd = Serial.read();

        if (cmd == 'B' && !blueState) {
            digitalWrite(BLUE, HIGH);
            Serial.println("BLUE=1");
            blueState = true;

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Cmd: ");
            lcd.print(cmd);
            lcd.setCursor(0, 1);
            lcd.print("BLUE ON");
        }
        else if (cmd == 'b' && blueState) {
            digitalWrite(BLUE, LOW);
            Serial.println("BLUE=0");
            blueState = false;

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Cmd: ");
            lcd.print(cmd);
            lcd.setCursor(0, 1);
            lcd.print("BLUE OFF");
        }
    }
}