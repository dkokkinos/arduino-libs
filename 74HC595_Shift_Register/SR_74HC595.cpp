#include "SR_74HC595.h"

SR_74HC595Module::SR_74HC595Module() {
}

void SR_74HC595Module::configure(uint8_t serialPin, uint8_t outputEnablePin, uint8_t storageRegisterClockPin, uint8_t clockPin) {
  _serialPin = serialPin;
  _outputEnablePin = outputEnablePin;
  _storageRegisterClockPin = storageRegisterClockPin;
  _clockPin = clockPin;

  pinMode(_storageRegisterClockPin, OUTPUT);
  if (_outputEnablePin != 0)
    pinMode(_outputEnablePin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_serialPin, OUTPUT);

  _autoFlush = false;
}

void SR_74HC595Module::write(int value) {
  hold();

  shiftOut(_serialPin, _clockPin, MSBFIRST, value);

  if (_autoFlush == true)
    flush();
}

void SR_74HC595Module::hold() {
  digitalWrite(_storageRegisterClockPin, LOW);
}

void SR_74HC595Module::flush() {
  digitalWrite(_storageRegisterClockPin, HIGH);
}

void SR_74HC595Module::enableAutoFlush() {
  _autoFlush = true;
}

void SR_74HC595Module::disableAutoFlush() {
  _autoFlush = false;
}