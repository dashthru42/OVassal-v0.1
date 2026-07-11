#include "types.h"

void printBoard(const Config& bb)
{
		char board_arr[64];
		std::fill(std::begin(board_arr), std::end(board_arr), '.');

		auto setUp = [&](std::uint64_t bitboard, char ch)
		{
			while(bitboard)
			{
				int square = __builtin_ctzll(bitboard);
				board_arr[square] = ch;
				bitboard &= bitboard - 1;
			}
		};
		
				setUp(bb.whitePawns, 'P');
				setUp(bb.whiteKnights, 'N');
                setUp(bb.whiteKing, 'K');
                setUp(bb.whiteQueen, 'Q');
                setUp(bb.whiteBishops, 'B');
                setUp(bb.whiteRooks, 'R');
                
				setUp(bb.blackPawns, 'p');
                setUp(bb.blackKnights, 'n');
                setUp(bb.blackKing, 'k');
                setUp(bb.blackQueen, 'q');
                setUp(bb.blackBishops, 'b');
                setUp(bb.blackRooks, 'r');

		for(int rank = 7; rank >= 0; --rank)
		{
			std::cout << rank + 1 << "\t";
			for(int file = 0; file < 8; ++file)
				{
					std::cout << board_arr[rank * 8 + file] << " ";		
				}
			std::cout << '\n';
		}

		std::cout << '\n';
		std::cout << "\ta b c d e f g h\n";

}