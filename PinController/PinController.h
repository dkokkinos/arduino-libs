// TODO add header comments with softwareparticles and link
#include "SR_74HC595.h"

#ifndef PinController_H
#define PinController_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class PinController
{
public:
    PinController();

    /*
      DS = serialPin (of first shift register)
      OE = outputEnablePin, 0 if not used.
      STCP = storageRegisterClockPin = latch(of first shift register)
      SHCP = clockPin = CLK (of first shift register)
    */
    void init(int numOfShiftRegisters, uint8_t serialPin, uint8_t outputEnablePin, uint8_t storageRegisterClockPin, uint8_t clockPin);

    void write(long value);
    void setPin(unsigned int pin, int value);

    void hold();
    void flush();
    void enableAutoFlush();
    void disableAutoFlush();

private:
    SR_74HC595 SR_74HC595;

    int *states;
    int _numOfShiftRegisters;
    bool _enableAutoFlush;

    int masks[8] = {
        B00000001,
        B00000010,
        B00000100,
        B00001000,
        B00010000,
        B00100000,
        B01000000,
        B10000000,
    };

    void initializeShiftRegisters();
    void writeChunks(int *states);
};

#endif