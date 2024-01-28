#ifndef SR_74HC595_H
#define SR_74HC595_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class SR_74HC595Module {
public:

  SR_74HC595Module();

  /* 
    DS = serialPin
    OE = outputEnablePin
    STCP = storageRegisterClockPin = latch
    SHCP = clockPin = CLK
  */
  void configure(uint8_t serialPin, uint8_t outputEnablePin, uint8_t storageRegisterClockPin, uint8_t clockPin);

  void write(int value);
  void flush();
  void hold();
  void enableAutoFlush();
  void disableAutoFlush();

private:
  uint8_t _serialPin;
  uint8_t _outputEnablePin;
  uint8_t _storageRegisterClockPin;
  uint8_t _clockPin;

  bool _autoFlush;
};

#endif