#include "display.h"
#include <bitset>
#include "constants.h"


Led mapLed(int r, int c) {

    Led led;

    if (r < 8 && c < 8) {

        led.board = 0;
        led.row = r;
        led.col = c;
    }
    else {

        led.board = 1;


        if (r == 8 && c < 8) {
            led.row = 0;
            led.col = c;
        }

        if (r < 8 && c == 8) {
            led.row = 1;
            led.col = r;
        }

        if (r == 8 && c == 8) {
            led.row = 2;
            led.col = 0;
        }
    }

    return led;
}

void generateSquareMap(SquareLeds squareMap[64]) {
    for (int sq = 0; sq < 64; sq++) {

        int r = sq / 8;
        int c = sq % 8;

        squareMap[sq].leds[0] = mapLed(r, c);
        squareMap[sq].leds[1] = mapLed(r, c + 1);
        squareMap[sq].leds[2] = mapLed(r + 1, c);
        squareMap[sq].leds[3] = mapLed(r + 1, c + 1);
    }
}

void sendMax(uint8_t reg, uint8_t data, uint8_t reg2, uint8_t data2) {

    digitalWrite(CS, LOW);

    SPI.transfer(reg);
    SPI.transfer(data);

    digitalWrite(CS, HIGH);
}

void pulseLeds() {
  for (int i = 0; i < 15; i++) {
    sendMax(0x0A, i, 0x0B, i);
    sleep(6);
  }
}

void lightPieces(std::bitset<81>& leds) {
    for (int i = 0; i < 64; 1++) {
        if ((1ULL << i) & board) {
            for (int j = 0; j < 4; j++) {
                leds |= squareMap[i].leds[j].row * 9 + squareMap[i].leds[j].col;
            } 
            
        }
    }
}





