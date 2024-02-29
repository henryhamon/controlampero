#ifndef DISPLAY_H
#define DISPLAY_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include "commons.h"

void tempData();
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
void selectDisplay(const int displayIndex);

/// SCL/SCK - GPIO22
/// SDA     - GPIO21
// Define e Configura Display
#endif

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
/*
int pinAddA = 15;
int pinAddB = 2;
int pinAddC = 4;
//*/
int pinAddA = 14;
int pinAddB = 15;
int pinAddC = 16;


void initDisplay() {
  pinMode(pinAddA, OUTPUT);
  pinMode(pinAddB, OUTPUT);
  pinMode(pinAddC, OUTPUT);
 

  Serial.println("OLED intialized");
  Wire.begin();  
  for (int currentDisplay = 0; currentDisplay < DISPLAYS_N_BUTTONS; ++currentDisplay) {
    selectDisplay(currentDisplay);
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 5);
    display.print("SLOT ");
    //display.print("NONONONO ");
    display.println(currentDisplay + 1);
    display.setTextSize(1);
    display.println("INITIALIZING");
    display.display();
    delay(50);
  }
  delay(500);
 
}

void tempData() {
    presets[0] = {"COMPRESSOR", 0, false, 1 };
    buttonStates[0] = false;
    buttonActions[0] = 0;
    presets[1] = {     "BOOST", 1, false, 1};
    buttonStates[1] = false;
    buttonActions[1] = 1;
    presets[2] = {"CRUNCH",  2,  true, 2};
    buttonStates[2] = true;
    buttonActions[2] = 2;
    presets[3] = {"DISTORT", 3, false, 2};
    buttonStates[3] = false;
    buttonActions[3] = 3;
    presets[4] = {"DELAY 1", 7, true, 3};
    buttonStates[4] = true;
    buttonActions[4] = 8;
    presets[5] = {"DELAY 2", 8, false, 3};
    buttonStates[5] = false;
    buttonActions[5] = 9;
    presets[6] = {"REVERB 1", 9, false, 4};
    buttonStates[6] = false;
    buttonActions[6] = 10;
    presets[7] = {"REVERB 2", 10, false, 4};
    buttonStates[7] = false;
    buttonActions[7] = 11;
}

void displayLoop() {
    if (reloadDisplay) {
        reloadDisplay = false;
        for (int currentDisplay = 0; currentDisplay < DISPLAYS_N_BUTTONS; ++currentDisplay) {
            selectDisplay(currentDisplay);
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(WHITE);
            display.setCursor(0, 5);
            if (presets[currentDisplay].name.length() > 0) {
                display.println(presets[currentDisplay].name);
                display.setTextSize(1);
                if (presets[currentDisplay].action > 6) {
                    display.print("B");
                    display.print(presets[currentDisplay].action - 5);
                } else {
                    display.print("A");
                    display.print(presets[currentDisplay].action + 1);
                }
            } else {
                display.println("  ---  ");
            }
            display.display();
        }
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

void selectDisplay(const int displayIndex) {
  switch (displayIndex) {
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
}