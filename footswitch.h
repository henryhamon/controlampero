
#include <ezButton.h>
#include "commons.h"
#include "midi_control.h"
// #include "database.h"

#define NUM_BUTTONS 10
#define EFX_BUTTONS 8

// Effect Buttons A..H -> 12..33
// btnDown and btnUp 34..35
//                     A   B   C   D   E   F   G   H   Dow  UP
ezButton buttons[] = { 13, 11, 9,  7, 12, 10,  8,  6,  4,  5 }; // Mega
//ezButton buttons[] = { 12, 13, 14, 25, 26, 27, 32, 33, 34, 35 }; // ESP32
bool tuner = false;

void onButtonPressed(int idxBtn) {
  if (idxBtn < EFX_BUTTONS) {
    Serial.print(buttonStates[idxBtn]); Serial.print(" -> "); Serial.println(!buttonStates[idxBtn]);
    buttonStates[idxBtn] = !buttonStates[idxBtn];
    Serial.print(buttonStates[idxBtn]); Serial.print(" <- "); Serial.println(!buttonStates[idxBtn]);
    sendToSlot(idxBtn, buttonStates[idxBtn]);
  }  // else {
    //reloadDisplay = true;
  //}
  if (idxBtn == 9) {
    tuner = !tuner;
    if (tuner) {
      tunerOn();
    } else {
      tunerOff();
    }

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
      Serial.print(i);
      Serial.println(" Btn is pressed");
      onButtonPressed(i);
    }
  }

}
