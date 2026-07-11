#ifndef FUNCS_H
#define FUNCS_H

#include <bit>
#include <cstdint>
#include "types.h"

int getLSB(std::uint64_t board);
int getMSB(std::uint64_t board);

bool isSquareOccupied(std::uint64_t board, int sqr);
bool isSquareOccupied(const Config& board, int square);

std::uint64_t getPositiveRay(std::uint64_t board, int square, Direction dir);
std::uint64_t getNegativeRay(std::uint64_t board, int square, Direction dir);
#endif
