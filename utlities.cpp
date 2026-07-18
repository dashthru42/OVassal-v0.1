#include "utilities.h"
#include "position.h"
#include "attacks.h"
#include <cctype>
#include <sstream>

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

Position setFEN(std::string fen) {
		//clear the bitboards

		Position board {};

		//although default initialised; to be safe;		
		for(int colour = Colour::WHITE; colour < 2; ++colour){
			for(int piecetype = Pieces::PAWN; piecetype < Pieces::NONE; ++piecetype) {
				board.pieces[colour][piecetype] = 0;
			}
		}

		std::istringstream parsed(fen);
		std::string placement, side_plays, castling, enPassant, halfmove, fullmove;
		parsed >> placement >> side_plays >> castling >> enPassant >> halfmove >> fullmove; 

		if(side_plays.contains('w')){
			board.sideToMove = WHITE;
		}
		else {
				board.sideToMove = BLACK;
			}

		for(const auto& ch : castling) {
			switch(ch){
				case 'K':        board.whiteKingCastle = true; break;
				case 'Q':        board.whiteQueenCastle = true; break;
				case 'k':        board.blackKingCastle = true; break;
				case 'q':        board.blackQueenCastle = true; break;
					default:       break;
			}
		}

		if(enPassant.contains('-')) {
			board.enPassantSquare = -1;
		} else {
        int epFile = enPassant[0] - 'a';     
        int epRank = enPassant[1] - '1';       
        board.enPassantSquare = epRank * 8 + epFile;
    }

		for(const auto& ch : halfmove) {
			board.halfmoveClock = ch - '0';
		}

		for(const auto& ch : fullmove) {
			board.fullMove = ch - '0';
		}

		int rank = 7, file = 0;

		for(auto const& ch : placement){
			if(ch == '/'){
				--rank;
				file = 0;
				continue;
			}
			if(std::isdigit(static_cast<unsigned char>(ch))) {
				file += ch - '0';
				continue;
			}

			int square = (rank * 8) + file;
			std::uint64_t bitmask = 1ULL << square;
			
				switch(ch){
		
				case 'p':    board.pieces[BLACK][PAWN] |= bitmask; break; 
				case 'P':    board.pieces[WHITE][PAWN] |= bitmask; break;
				case 'N':    board.pieces[WHITE][KNIGHT] |= bitmask; break;
				case 'n':    board.pieces[BLACK][KNIGHT] |= bitmask; break;
				case 'B':    board.pieces[WHITE][BISHOP] |= bitmask; break;
				case 'b':    board.pieces[BLACK][BISHOP] |= bitmask; break;
				case 'R':    board.pieces[WHITE][ROOK] |= bitmask; break;
				case 'r':    board.pieces[BLACK][ROOK] |= bitmask; break;
				case 'K':    board.pieces[WHITE][KING] |= bitmask; break;
				case 'k':    board.pieces[BLACK][KING] |= bitmask; break;
				case 'Q':    board.pieces[WHITE][QUEEN] |= bitmask; break;
				case 'q':    board.pieces[BLACK][QUEEN] |= bitmask; break;
					default:   break; 
		}
	}

			return board;
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
