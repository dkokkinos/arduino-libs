#include "EightByEightDisplay.h"

EightByEightDisplay::EightByEightDisplay() {
}

void EightByEightDisplay::init(uint8_t hardwareConfig, const uint8_t rowPins[], const uint8_t columnPins[]) {
  initializeCathodeAndAnodes(hardwareConfig);
  initializePins(rowPins, columnPins);
  initializePixelMatrix();

  for (uint8_t i = 0; i < 8; i++) {
    row[i] = rowPins[i];
  }

  for (uint8_t i = 0; i < 8; i++) {
    col[i] = columnPins[i];
  }
}

void EightByEightDisplay::update(const uint8_t pixelsIn[8][8]) {
  for (uint8_t r = 0; r < 8; r++) {
    for (uint8_t c = 0; c < 8; c++) {
      pixels[r][c] = pixelsIn[r][c];
    }
  }
}

void EightByEightDisplay::refresh() {
  for (int r = 0; r < 8; r++) {
    allColumnsOFF();
    rowON(r);

    for (int c = 0; c < 8; c++) {
      int pixelState = pixels[r][c];

      if (pixelState == HIGH) columnON(c);
      else columnOFF(c);
    }

    // Let the LEDs of this row light up for a while.
    delayMicroseconds(50);
    rowOFF(r);
  }
}

void EightByEightDisplay::initializeCathodeAndAnodes(uint8_t hardwareConfig) {
  switch (hardwareConfig) {
    case 0:  // Row Common cathode, Column Common anode
      ROW_ON = LOW;
      ROW_OFF = HIGH;

      COLUMN_ON = HIGH;
      COLUMN_OFF = LOW;
      break;

    case 1:  // Row Common anode, Column Common cathode
      ROW_ON = HIGH;
      ROW_OFF = LOW;

      COLUMN_ON = LOW;
      COLUMN_OFF = HIGH;
      break;
  }
}

void EightByEightDisplay::initializePins(const uint8_t rowPins[], const uint8_t columnPins[]) {
  for (int i = 0; i < 8; i++) {
    pinMode(columnPins[i], OUTPUT);
    pinMode(rowPins[i], OUTPUT);

    rowOFF(i);
  }
}

void EightByEightDisplay::initializePixelMatrix() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = LOW;
    }
  }
}

void EightByEightDisplay::rowON(uint8_t index) {
  digitalWrite(row[index], ROW_ON);
}

void EightByEightDisplay::rowOFF(uint8_t index) {
  digitalWrite(row[index], ROW_OFF);
}

void EightByEightDisplay::columnON(uint8_t index) {
  digitalWrite(col[index], COLUMN_ON);
}

void EightByEightDisplay::columnOFF(uint8_t index) {
  digitalWrite(col[index], COLUMN_OFF);
}

void EightByEightDisplay::allColumnsOFF() {
  digitalWrite(col[0], COLUMN_OFF);
  digitalWrite(col[1], COLUMN_OFF);
  digitalWrite(col[2], COLUMN_OFF);
  digitalWrite(col[3], COLUMN_OFF);
  digitalWrite(col[4], COLUMN_OFF);
  digitalWrite(col[5], COLUMN_OFF);
  digitalWrite(col[6], COLUMN_OFF);
  digitalWrite(col[7], COLUMN_OFF);
}
