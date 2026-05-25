

#pragma once

#include <iostream>
#include <array>
#include <atomic>
#include <vector>
inline int squareToFile(int square) {
    return square % 8;
};


inline int squareToRank(int square) {
    return square / 8;
};


using u64 = uint64_t;

enum Color {WHITE, BLACK};
enum Piece {WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK, NONE};






//Files
constexpr u64 FILE_A  = 0x0101010101010101ULL;
constexpr u64 FILE_B  = (FILE_A << 1);
constexpr u64 FILE_C  = (FILE_A << 2);
constexpr u64 FILE_D  = (FILE_A << 3);
constexpr u64 FILE_E  = (FILE_A << 4);
constexpr u64 FILE_F  = (FILE_A << 5);
constexpr u64 FILE_G  = (FILE_A << 6);
constexpr u64 FILE_H  = (FILE_A << 7);


//Ranks
constexpr u64 RANK_1 = 0x00000000000000FFULL;
constexpr u64 RANK_2 = RANK_1 << 8;
constexpr u64 RANK_3 = RANK_1 << 16;
constexpr u64 RANK_4 = RANK_1 << 24;
constexpr u64 RANK_5 = RANK_1 << 32;
constexpr u64 RANK_6 = RANK_1 << 40;
constexpr u64 RANK_7 = RANK_1 << 48;
constexpr u64 RANK_8 = RANK_1 << 56;



struct Board {
    u64 pieces[12];

    // Occupancies
    u64 all_white;
    u64 all_black;
    u64 all;

    Color sideToMove;
    

    
    int castlingRights;

    // En passant
    int enPassantSquare = -1;

    // Half-move clock (50-move rule)
    int halfmoveClock;
    int fullmoveNumber;


    u64 hash;
};

extern u64 board;







