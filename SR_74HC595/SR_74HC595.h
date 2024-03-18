#ifndef SR_74HC595_H
#define SR_74HC595_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class SR_74HC595 {
public:

  SR_74HC595();

  /* 
    DS = serialPin
    OE = outputEnablePin
    STCP = storageRegisterClockPin = latch
    SHCP = clockPin = CLK
  */
  void init(uint8_t serialPin, uint8_t outputEnablePin, uint8_t storageRegisterClockPin, uint8_t clockPin);

  void write(int value);

  /// @brief Set the Order of bit transfer
  /// @param bitOrder MSBFIRST or LSBFIRST
  void setBitOrder(uint8_t bitOrder);
  void flush();
  void hold();
  void enableAutoFlush();
  void disableAutoFlush();

private:
  uint8_t _serialPin;
  uint8_t _outputEnablePin;
  uint8_t _storageRegisterClockPin;
  uint8_t _clockPin;
  uint8_t _bitOrder = MSBFIRST;
  bool _autoFlush;
};

#endif