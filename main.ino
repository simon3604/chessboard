#include <vector>

#include "Reeds/reeds.h"
#include "Display/display.h"
#include "Board/board.h"
#include "constants.h"
#include "Comm/comm.h"
#include "Utils/settings.h"

#include "BluetoothSerial.h"
#include <SPI.h>
#include <LedControl.h>

BluetoothSerial SerialBT;

LedControl lc = LedControl(11, 13, 10, 2);

void setup()
{
    SerialBT.begin("Chessboard");
    SPI.begin();

    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);

    initPins(reedRows, true);
    initPins(reedCols, false);

    pinMode(CS, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(DIN, OUTPUT);

    SquareLeds squareMap[64];
    generateSquareMap(squareMap);
}

void loop()
{
    // uint64_t newBoard = scanBoard();
    // detectMove(board, newBoard);
    // board = newBoard;
    // if (settings.lightPieces) {
    //     lightPieces(std::bitset<81>(board));
    // }
    testLeds();
}
