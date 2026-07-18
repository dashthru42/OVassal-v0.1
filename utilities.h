#ifndef UTILITIES_H
#define UTILITIES_H

#include "position.h"
#include <string>

int getLSB(std::uint64_t board);
int getMSB(std::uint64_t board);

bool isSquareOccupied(std::uint64_t board, int sqr);

std::uint64_t getPositiveRay(std::uint64_t board, int square, RayDirection dir);
std::uint64_t getNegativeRay(std::uint64_t board, int square, RayDirection dir);

Position setFEN(std::string fen);

std::string u8Encode(char32_t code);

#endif
