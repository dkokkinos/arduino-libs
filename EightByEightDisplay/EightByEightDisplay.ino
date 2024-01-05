#include "EightByEightDisplay.h"

EightByEightDisplay display;

int C1 = A2;
int C2 = 7;
int C3 = 6;
int C4 = 12;
int C5 = 4;
int C6 = 11;
int C7 = A4;
int C8 = A5;

// R for Rows
int R1 = 13;
int R2 = A3;
int R3 = 2;
int R4 = 10;
int R5 = 9;
int R6 = 3;
int R7 = 8;
int R8 = 5;

void setup() {

  Serial.begin(9600);

  uint8_t row[8] = {
    R1, R2, R3, R4, R5, R6, R7, R8
  };

  uint8_t col[8] = {
    C1, C2, C3, C4, C5, C6, C7, C8
  };

  display.init(1, row, col);
}

void loop() {

  uint8_t image[8][8] = {
    { LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, LOW },
    { LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW },
    { LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW },
    { LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW },
    { LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW },
    { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW },
    { LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW },
    { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW },
  };

  display.update(image);
  display.refresh();
}
