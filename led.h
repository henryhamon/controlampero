#ifndef LED_H
#define LED_H

#include <Adafruit_NeoPixel.h>
#include "commons.h"

#define LED_PIN 0

Adafruit_NeoPixel pixels(DISPLAYS_N_BUTTONS, LED_PIN);
void initLed();
void ledLoop();
//                   A  B  C  D  E  F  G  H 
int buttonAddr[8] = {3, 2, 1, 0, 4, 5, 6, 7 };
#endif

void initLed()
{
    pinMode(LED_PIN, OUTPUT);
    pixels.begin();

    pixels.clear();
    for (int i = 0; i < DISPLAYS_N_BUTTONS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 255));
        pixels.show();
        delay(100);
    }

    delay(100);
    pixels.clear();
    pixels.show();

}

void ledLoop()
{
    pixels.clear();
    pixels.show();
    for (int i = 0; i < DISPLAYS_N_BUTTONS; i++)
    {
        if (buttonStates[i])
        {
            pixels.setPixelColor(buttonAddr[i], pixels.Color(84, 22, 180));
            pixels.show();
        }
    }
}

uint32_t getRed(){
    return pixels.Color(84, 22, 180);
}