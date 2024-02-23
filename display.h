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

int pinAddA = 5;
int pinAddB = 18;
int pinAddC = 19;

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
    display.println(currentDisplay + 1);
    display.setTextSize(1);
    display.println("INITIALIZING");
    display.display();
    delay(5);
  }
  delay(500);
 
}

void displayLoop() {
  /*
  for (int currentDisplay = 0; currentDisplay < DISPLAYS_N_BUTTONS; ++currentDisplay) {
      selectDisplay(currentDisplay);
      display.clearDisplay();
      display.display();
  }

  for (int currentDisplay = 0; currentDisplay < DISPLAYS_N_BUTTONS; ++currentDisplay) {
      selectDisplay(currentDisplay);
      display.setCursor(0, 5);
      display.setTextSize(2);
      if (displayText[currentDisplay].length() > 0) {
          display.println(displayText[currentDisplay]);
      } else {
          display.println("  EMPTY  ");
      }
      display.display();
  }
  //*/
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