#include <iostream>
#include <cstdio>
#include "A_BOARDS.h"
#include "types.h"
#include "funcs.h"

void print_bitboard(uint64_t bb) {
    for (int rank = 7; rank >= 0; rank--) {
        printf("%d  ", rank + 1);
        for (int file = 0; file < 8; file++)
            printf("%c ", (bb >> (rank * 8 + file)) & 1 ? '1' : '.');
        printf("\n");
    }
    printf("   a b c d e f g h\n\n");
}

int main()
{
	initialize_attacks();
	print_bitboard(RAY_ATTACK[19][RAY_NORTH]);

    return 0;
}
