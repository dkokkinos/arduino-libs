#ifndef EightByEightDisplay_h
#define EightByEightDisplay_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class EightByEightDisplay {
public:
  EightByEightDisplay();
  void init(uint8_t hardwareConfig, const uint8_t rowPins[], const uint8_t columnPins[]);
  void update(const uint8_t pixelsIn[8][8]);
  void refresh();

private:
  uint8_t ROW_ON;
  uint8_t ROW_OFF;
  uint8_t COLUMN_ON;
  uint8_t COLUMN_OFF;

  uint8_t pixels[8][8];

  uint8_t row[8];
  uint8_t col[8];

  void initializeCathodeAndAnodes(uint8_t hardwareConfig);
  void initializePins(const uint8_t rowPins[], const uint8_t columnPins[]);
  void initializePixelMatrix();

  void rowON(uint8_t index);
  void rowOFF(uint8_t index);
  void columnON(uint8_t index);
  void columnOFF(uint8_t index);
  void allColumnsOFF();
};

#endif  //EightByEightDisplay_h
        /// END ///