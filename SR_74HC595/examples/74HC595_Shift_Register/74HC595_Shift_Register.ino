#include "SR_74HC595.h"

#define DS 4 // serialPin
#define OE 0 // outputEnablePin, 0 because is not used.
#define STCP 3 // storageRegisterClockPin/latch
#define SHCP 2 // clockPin/CLK

SR_74HC595Module shiftRegisterModule;

void setup() {
 shiftRegisterModule.configure(DS, OE, STCP, SHCP);
 shiftRegisterModule.enableAutoFlush();
}

void loop() {
  for (int n = 0; n < 255; n++) {
    shiftRegisterModule.write(n);
    delay(25);
  }
}
