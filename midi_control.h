#ifndef MIDI_CONTROL_H
#define MIDI_CONTROL_H

#include <MIDI.h>
#include "commons.h"

MIDI_CREATE_DEFAULT_INSTANCE();

int getSlotCC(int button);
void sendToSlot(int button, bool state);

#endif

int getSlotCC(int button) {
    Serial.println("getSlotCC");
    int out = 0;
    int action = buttonActions[button];
    if (action > 5) {
        out = CC_SLOT_B[action - 6];
    } else {
        out = CC_SLOT_A[action];
    }
    return out;
}

void sendToSlot(int button, bool state) {
    Serial.println("sendToSlot");
    int CC = getSlotCC(button);
    int value = 62; // OFF
    if (state) {
        value = 120; // ON
    }
    Serial.print("CC: "); Serial.print(CC); Serial.print(" Value: "); Serial.println(value);
    MIDI.sendControlChange(value, CC, 1);
}