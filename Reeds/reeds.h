#pragma once

#include <vector>
#include <cstdint>


std::vector<int> reedRows{3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> reedCols{11, 12, 13, 14, 15, 16, 17, 18};

uint64_t scanBoard();
void initPins(std::vector<int>& pins, bool output);