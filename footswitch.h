#include <ezButton.h>
#include "commons.h"

#define NUM_BUTTONS 10
#define EFX_BUTTONS 8
#define NUM_LEDS 8

// Effect Buttons A..H -> 12..33
// btnDown and btnUp 34..35
//                     A   B   C   D   E   F   G   H   Dow  UP
ezButton buttons[] = { 12, 13, 14, 25, 26, 27, 32, 33, 34, 35 };

void onButtonPressed(int idxBtn) {
  if (idxBtn < EFX_BUTTONS) {
    buttonStates[idxBtn] = !buttonStates[idxBtn];
    //updateLED(buttonIndex);
  }
}

void footSetup() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].setDebounceTime(50);
  }

}

void footEvent() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].loop();
    
    if (buttons[i].isPressed()) {
      Serial.println("Btn is pressed");
      onButtonPressed(i);
    }
  }

}