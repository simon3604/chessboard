#include "reeds.h"
#include <Arduino.h>

#include <vector>

uint64_t scanBoard()
{
    uint64_t board = 0ULL;
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(reedRows[i], 1);
        sleep(5);
        for (int j = 0; j < 8; j++)
        {
            bool active = digitalRead(reedCols[j]);
            if (active)
            {
                board |= (1ULL << (j + 8 * i));
            }
        }
        digitalWrite(reedRows[i], 0);
    }
    return board;
}

void initPins(std::vector<int> &pins, bool output)
{
    for (int i = 0; i < pins.size(); i++)
    {
        int pin = pins[i];

        if (output)
        {
            pinMode(pin, OUTPUT);
            digitalWrite(pin, 0);
        }
        else
        {
            pinMode(pin, INPUT_PULLUP);
        }
    }
}

void detectMove(uint64_t oldBoard, uint64_t newBoard)
{
    uint64_t diff = oldBoard ^ newBoard;
    while (diff)
    {
        int fromSquare = __builtin_ctzll(diff & oldBoard);
        int toSquare = __builtin_ctzll(diff & newBoard);
        diff ^= (1ULL << fromSquare);
        diff ^= (1ULL << toSquare);

        if (fromSquare != 0)
        {
            SPI.transfer("From: ");
            SPI.transfer(fromSquare);
        }
        if (toSquare != 0)
        {
            SPI.transfer("From: " + String(fromSquare));
            SPI.transfer("To: " + String(toSquare));
        }
    }
}
