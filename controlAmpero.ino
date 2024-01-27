#include <Arduino_JSON.h>

#include <Preferences.h>
Preferences preferences;
bool ledState;

#include "footswitch.h"
#include "display.h"

void setup() {
  Serial.begin(9600); 
  preferences.begin("controlAmpero", false);
// read the last LED state from flash memory
  ledState = preferences.getBool("state", false); 
  // put your setup code here, to run once:
  displayInit();
  footSetup();
}

void loop() {

  // put your main code here, to run repeatedly:
  footEvent();
  preferences.putBool("state", LOW);
}
