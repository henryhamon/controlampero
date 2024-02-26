#ifndef LED_H
#define LED_H

#include <Adafruit_NeoPixel.h>
#include "commons.h"
#include "colors.h"

// #define LED_PIN 0 // ESP32
#define LED_PIN 3

Adafruit_NeoPixel pixels(DISPLAYS_N_BUTTONS, LED_PIN);
void initLed();
void ledLoop();
//                   A  B  C  D  E  F  G  H 
int buttonAddr[8] = {3, 2, 1, 0, 4, 5, 6, 7 };


uint32_t getGreen();
uint32_t getLightGreen();
uint32_t getBlue();
uint32_t getLightBlue();
uint32_t getRed();
uint32_t getDarkRed();
uint32_t getPurple();
uint32_t getDarkPurple();

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
            uint32_t color;
            color = pixels.Color(84, 22, 180);
            if (presets[i].type == 1) {
                color = getBlue();
            }
            if (presets[i].type == 2) {
                color = getRed();
            }
            if (presets[i].type == 3) {
                color = getDarkPurple();
            }
            if (presets[i].type == 4) {
                color = getGreen();
            }
            pixels.setPixelColor(buttonAddr[i], color);
            pixels.show();
        }
    }
}

uint32_t getGreen(){
    return pixels.Color(0, 107, 0);
}
uint32_t getLightGreen(){
    return pixels.Color(63, 97, 96);
}
uint32_t getBlue(){
    return pixels.Color(0, 0, 204);
}
uint32_t getLightBlue(){
    return pixels.Color(64, 99, 117);
}
uint32_t getRed(){
    return pixels.Color(204, 0, 0);
}
uint32_t getDarkRed(){
    return pixels.Color(126, 78, 78);
}
uint32_t getPurple(){
    return pixels.Color(128, 0, 128);
}

uint32_t getDarkPurple(){
    return pixels.Color(76, 0, 153);
}