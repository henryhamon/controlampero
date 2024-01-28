#include "database.h"
#include "footswitch.h"
#include "display.h"

void setup() {
  Serial.begin(9600); 
  databaseSetup();
  initDisplay();
  footSetup();
}

void loop() {

  // put your main code here, to run repeatedly:
  displayLoop();
  footEvent();
}
