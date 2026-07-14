#include "funcs.h"
#include "types.h"
#include "A_BOARDS.h"

int getLSB(std::uint64_t board) {
		if(board == 0) return -1;
		else {
			return std::countr_zero(board);
		}
}

int getMSB(std::uint64_t board) {
	if(board == 0) return -1;
	else{
			return 63 - __builtin_clzll(board);
		} 
}

char lower(char ch) {
	char low;
	return low = ch | ' ';
}

bool isSquareOccupied(std::uint64_t board, int square) {
   return (board & (1ULL << square)) != 0;
}

std::uint64_t getPositiveRay(std::uint64_t board, int square, RayDirection dir)
{
	std::uint64_t attacking = RAY_ATTACK[square][dir];
	std::uint64_t blocker = attacking & board; //intersection of attack rays and current position function
	//is being called from; we try to find any valid blockers

//eliminate the squares/bits from RAY_ATTACK that are past any blocker
	if(blocker) {
		int blockerSquare = getLSB(blocker);
		attacking ^= RAY_ATTACK[blockerSquare][dir];
	}	
	return attacking;
}

//do the same here but with MSB; this is what distinguishes positive vs. negative

std::uint64_t getNegativeRay(std::uint64_t board, int square, RayDirection dir)
{
	std::uint64_t attacking = RAY_ATTACK[square][dir];
	std::uint64_t blocker = attacking & board;

	if(blocker){
		int blockerSquare = getMSB(blocker);
		attacking ^= RAY_ATTACK[blockerSquare][dir];
	}

	return attacking;
}
