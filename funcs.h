#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"
#include <string>

int getLSB(std::uint64_t board);
int getMSB(std::uint64_t board);

bool isSquareOccupied(std::uint64_t board, int sqr);

std::uint64_t getPositiveRay(std::uint64_t board, int square, RayDirection dir);
std::uint64_t getNegativeRay(std::uint64_t board, int square, RayDirection dir);


std::uint64_t setFEN(Position bitboard, std::string fen);

std::string u8Encode(char32_t code);

#endif
