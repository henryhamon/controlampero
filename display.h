#ifndef DISPLAY_H
#define DISPLAY_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include "commons.h"

void initDisplay();
void selDispA();
void selDispB();
void selDispC(); 
void selDispD();
void selDispE();
void selDispF();
void selDispG();
void selDispH();
void displayLoop();

/// SCL - GPIO22
/// SDA - GPIO21
// Define e Configura Display
#endif

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int pinAddA = 19;
int pinAddB = 18;
int pinAddC = 5;

void initDisplay() {
    pinMode(pinAddA, OUTPUT);
    pinMode(pinAddB, OUTPUT);
    pinMode(pinAddC, OUTPUT);

    Serial.println("OLED intialized");
    Wire.begin();
    selDispA();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();

    selDispB();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDispC(); 
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDispD();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDispE();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDispF();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDispG();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    
    selDispH();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    // text display tests
    display.setTextSize(2);
    display.setTextColor(WHITE);
}

void displayLoop() {
    
    for (int currentDisplay = 0; currentDisplay < DISPLAYS_N_BUTTONS; ++currentDisplay) {
        switch (currentDisplay) {
        case 0:
            selDispA();
            break;
        case 1:
            selDispB();
            break;
        case 2:
            selDispC();
            break;
        case 3:
            selDispD();
            break;
        case 4:
            selDispE();
            break;
        case 5:
            selDispF();
            break;
        case 6:
            selDispG();
            break;
        case 7:
            selDispH();
            break;
        default:
            break;
        }
        display.setCursor(0, 0);
        display.setTextSize(2);
        if (displayText[currentDisplay].length() > 0) {
            display.println(displayText[currentDisplay]);
        } else {
            display.println(" ");
        }
        display.clearDisplay();
    }

}


void selDispA() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, LOW);
}

void selDispB() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, LOW);
}
void selDispC() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, LOW);
}
void selDispD() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, LOW);
}
void selDispE() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, HIGH);
}
void selDispF() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, HIGH);
}

void selDispG() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, HIGH);
}

void selDispH() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, HIGH);
}