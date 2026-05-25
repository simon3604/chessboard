#pragma once

#include <bitset>
#include <cstdint>

#define CS 5
#define CLK 18
#define DIN 19

void sendMax(uint8_t reg, uint8_t data, uint8_t reg2, uint8_t data2);
void pulseLeds();
void lightPieces(std::bitset<81>& leds);
void testLeds();
