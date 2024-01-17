#ifndef PARAMS_H
#define PARAMS_H

// AMPERO STOMP 2 MIDI Control Information
#define VL_SLOT_ON 62;
#define VL_SLOT_OFF 65;

const CC_SLOT_A[] = { 48, 49, 50, 51, 52, 53 };
const CC_SLOT_B[] = { 54, 55, 56, 57, 58, 59 };

#define PATCH_UP 27;
#define PATCH_DOWN 26;

#endif
/*
Bank MSB
P00-1 ~ P42-2 CC=0 VL=0-127
P42-3 ~ P85-1 CC=1 VL=0-127
P85-2 ~ P99-3 CC=2 VL=0-43

const decode = (a, b) => {
  if ((a>99)||(b>3)) return undefined
  let cc = 0,
    calculated = (a * 3 + b - 1);
  if (calculated > 127) {
    cc++;
    calculated = calculated - 128;
  }
  if (calculated > 127) {
    cc++;
    calculated = calculated - 128;
  }
  return [cc, calculated]
}

*/

const char effects[] = "{ \
    \"Compressor\": \"RRGGBB\", \
    \"Boost\":    \"RRGGBB\", \
    \"Noise Gate\": \"RRGGBB\", \
    \"FREQ\":     \"RRGGBB\", \
    \"Acoustic\": \"RRGGBB\", \
    \"Filter\":   \"RRGGBB\", \
    \"Auto Filter\": \"RRGGBB\", \
    \"Pitch\":    \"RRGGBB\", \
    \"Special\":  \"RRGGBB\", \
    \"WAH\":      \"RRGGBB\", \
    \"Overdrive\": \"RRGGBB\", \
    \"FUZZ\":     \"RRGGBB\", \
    \"Distortion\": \"RRGGBB\", \
    \"Bass Drive\": \"RRGGBB\", \
    \"AMP\":      \"RRGGBB\", \
    \"Power Amp\": \"RRGGBB\", \
    \"PRE AMP\":  \"RRGGBB\", \
    \"CAB\":      \"RRGGBB\", \
    \"IR\":       \"RRGGBB\", \
    \"EQ\":       \"RRGGBB\", \
    \"Chorus\":   \"RRGGBB\", \
    \"Flanger\":  \"RRGGBB\", \
    \"Vibrato\":  \"RRGGBB\", \
    \"Phaser\":   \"RRGGBB\", \
    \"Tremolo\":  \"RRGGBB\", \
    \"Rotary\":   \"RRGGBB\", \
    \"Expanding\": \"RRGGBB\", \
    \"Slow Attack\": \"RRGGBB\", \
    \"Delay\":    \"RRGGBB\", \
    \"Rever\":    \"RRGGBB\" }";

