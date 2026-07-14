#include <iostream>
#include <cstdio>
#include "A_BOARDS.h"
#include "types.h"
#include "funcs.h"

void print_bitboard(std::uint64_t bitboard) {
    for(int rank = 8; rank > 0; ++rank) {
        std::cout << rank << '\t';
          for(int file = 0; file < 8; ++file) {
              
          }
    }
}

int main()
{
    Position game;
    set_start_position(game);

	
    return 0;
}
