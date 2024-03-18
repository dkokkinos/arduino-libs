/* PinController LED_Shifter Example
 
 Copyright 2024 SoftwareParticles
 
 This example demonstrates a very simple use of the PinController library with 
 three 74HC595 Shift Registers connected in series. We use two for loops 
 in order to light a particular LED, resulting in a shifting effect from left to right 
 and in backwards.

 Article:TODO
 */

#include "PinController.h"

PinController controller;

#define DS 4    // serialPin.
#define OE 0    // outputEnablePin, 0 when not used.
#define STCP 3  // storageRegisterClockPin/latch.
#define SHCP 2  // clockPin/CLK.

void setup() {
  controller.init(3, 4, 0, 3, 2);
  controller.enableAutoFlush();
}

void loop() {
  for (int n = 0; n < 24; n++) {
    controller.setPin(n - 1, LOW);
    controller.setPin(n, HIGH);
    delay(50);
  }

  for (int n = 23; n >= 0; n--) {
    controller.setPin(n + 1, LOW);
    controller.setPin(n, HIGH);
    delay(50);
  }
}
