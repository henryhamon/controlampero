#include "footswitch.h"
#include "display.h"
#include "led.h"

void setup() {
  Serial.begin(9600); 
  initDisplay();
  initLed();

  footSetup();
}

void loop() {

  // put your main code here, to run repeatedly:
  displayLoop();
  ledLoop();
  footEvent();
}
