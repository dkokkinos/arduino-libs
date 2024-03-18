#include "PinController.h"

PinController::PinController() { }

void PinController::init(int numOfShiftRegisters, uint8_t serialPin, uint8_t outputEnablePin, uint8_t storageRegisterClockPin, uint8_t clockPin)
{
    _numOfShiftRegisters = numOfShiftRegisters;

    SR_74HC595.init(serialPin, outputEnablePin, storageRegisterClockPin, clockPin);

    initializeShiftRegisters();

    _enableAutoFlush = false;
}

void PinController::initializeShiftRegisters()
{
    states = new int[_numOfShiftRegisters];
    for (size_t i = 0; i < _numOfShiftRegisters; i++)
    {
        states[i] = 0;
        SR_74HC595.write(states[i]);
    }

    SR_74HC595.flush();
}

void PinController::write(long value)
{
    for (int i = 0; i < _numOfShiftRegisters; i++)
    {
        states[i] = value >> 8 * i;
    }

    writeChunks(states);
}

void PinController::setPin(unsigned int pin, int value)
{
    if (pin >= _numOfShiftRegisters * 8)
        return;

    int stateIndex = pin / 8;
    int mask = masks[pin % 8];

    if (value == HIGH)
    {
        states[stateIndex] = states[stateIndex] | mask;
    }
    else if (value == LOW)
    {
        states[stateIndex] = states[stateIndex] & ~mask;
    }

    writeChunks(states);
}

void PinController::writeChunks(int *chunks)
{
    SR_74HC595.hold();

    for (int i = _numOfShiftRegisters; i >= 0; i--)
    {
        SR_74HC595.write(chunks[i]);
    }

    if (_enableAutoFlush)
        SR_74HC595.flush();
}

void PinController::hold()
{
    SR_74HC595.hold();
}

void PinController::flush()
{
    SR_74HC595.flush();
}

void PinController::enableAutoFlush()
{
    _enableAutoFlush = true;
}

void PinController::disableAutoFlush()
{
    _enableAutoFlush = false;
}