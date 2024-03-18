#include "SR_74HC595.h"

SR_74HC595::SR_74HC595() { }

void SR_74HC595::init(uint8_t serialPin, uint8_t outputEnablePin, uint8_t storageRegisterClockPin, uint8_t clockPin)
{
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

void SR_74HC595::write(int value)
{
  hold();

  shiftOut(_serialPin, _clockPin, _bitOrder, value);

  if (_autoFlush == true)
    flush();
}

void SR_74HC595::setBitOrder(uint8_t bitOrder)
{
  _bitOrder = bitOrder;
}

void SR_74HC595::hold()
{
  digitalWrite(_storageRegisterClockPin, LOW);
}

void SR_74HC595::flush()
{
  digitalWrite(_storageRegisterClockPin, HIGH);
}

void SR_74HC595::enableAutoFlush()
{
  _autoFlush = true;
}

void SR_74HC595::disableAutoFlush()
{
  _autoFlush = false;
}