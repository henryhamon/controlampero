#include <Arduino_JSON.h>

#include "footswitch.h"
#include "display.h"

void setup() {
  Serial.begin(9600); 
  initDisplay();
  footSetup();
}

void loop() {

  // put your main code here, to run repeatedly:
  footEvent();
  displayLoop();
}
