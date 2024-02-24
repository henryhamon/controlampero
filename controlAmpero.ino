#include "footswitch.h"
#include "display.h"
#include "led.h"
// #include "database.h"

void setup() {
  Serial.begin(9600); 
  tempData();
  initDisplay();
  initLed();

  footSetup();
  //initDatabase();
}

void loop() {

  // put your main code here, to run repeatedly:
  displayLoop();
  ledLoop();
  footEvent();
}
