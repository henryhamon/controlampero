#include "footswitch.h"


void setup() {
  Serial.begin(9600); 
  
  // put your setup code here, to run once:
  footSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  footEvent();
}
