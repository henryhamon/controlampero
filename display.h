#ifndef DISPLAY_H
#define DISPLAY_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>

void initDisplay();
void selDisp1();
void selDisp2();
void selDisp3(); 
void selDisp4();
void selDisp5();
void selDisp6();
void selDisp7();
void selDisp8();
void displayLoop();

/// SCL - GPIO22
/// SDA - GPIO21
// Define e Configura Display
#endif

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
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
    selDisp1();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();

    selDisp2();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDisp3(); 
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDisp4();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDisp5();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDisp6();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    selDisp7();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    
    selDisp8();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    // text display tests
    display.setTextSize(2);
    display.setTextColor(WHITE);
}

void displayLoop() {
    selDisp1();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("DRIVE 1");
    display.clearDisplay();

    
    selDisp2();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("DRIVE 2");
    display.clearDisplay();

    
    selDisp3();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("BOOST 1");
    display.clearDisplay();

    
    selDisp4();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("BOOST 2");
    display.clearDisplay();

    
    selDisp5();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("DELAY 1");
    display.clearDisplay();

    
    selDisp6();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("DELAY 2");
    display.clearDisplay();

    
    selDisp7();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("REVERB 1");
    display.clearDisplay();

    
    selDisp8();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("REVERB 2");
    display.clearDisplay();

}


void selDisp1() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, LOW);
}

void selDisp2() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, LOW);
}
void selDisp3() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, LOW);
}
void selDisp4() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, LOW);
}
void selDisp5() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, HIGH);
}
void selDisp6() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, LOW);
    digitalWrite(pinAddC, HIGH);
}

void selDisp7() {
    digitalWrite(pinAddA, LOW);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, HIGH);
}

void selDisp8() {
    digitalWrite(pinAddA, HIGH);
    digitalWrite(pinAddB, HIGH);
    digitalWrite(pinAddC, HIGH);
}