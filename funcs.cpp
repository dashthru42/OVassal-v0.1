#include "funcs.h"
#include "types.h"

int getLSB(std::uint64_t board) {
    return std::countr_zero(board);
}

int getMSB(std::uint64_t board) {
	if(board == 0) return -1;
	else 
		return 63 - __builtin_clzll(board);
}

bool isSquareOccupied(std::uint64_t board, int square) {
   return (board & (1ULL << square)) != 0;
}
bool isSquareOccupied(const Config& board, int square) {
    return (board.allPieces & (1ULL << square)) != 0;
}


