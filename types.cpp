#include "types.h"


	void set_start_position(Position& b) {
    b.pieces[WHITE][PAWN]   = 0x000000000000FF00ULL;
    b.pieces[WHITE][KNIGHT] = 0x0000000000000042ULL;
    b.pieces[WHITE][BISHOP] = 0x0000000000000024ULL;
    b.pieces[WHITE][ROOK]   = 0x0000000000000081ULL;
    b.pieces[WHITE][QUEEN]  = 0x0000000000000008ULL;
    b.pieces[WHITE][KING]   = 0x0000000000000010ULL;

    b.pieces[BLACK][PAWN]   = 0x00FF000000000000ULL;
    b.pieces[BLACK][KNIGHT] = 0x4200000000000000ULL;
    b.pieces[BLACK][BISHOP] = 0x2400000000000000ULL;
    b.pieces[BLACK][ROOK]   = 0x8100000000000000ULL;
    b.pieces[BLACK][QUEEN]  = 0x0800000000000000ULL;
    b.pieces[BLACK][KING]   = 0x1000000000000000ULL;

    b.sideToMove = WHITE;
    
    b.whiteKingCastle = true;
    b.whiteQueenCastle = true;
    b.blackKingCastle = true;
    b.blackQueenCastle = true;
    
    b.enPassantSquare = -1;
    b.halfmoveClock = 0;
    b.fullMove = 1;
}

Board side_occupation(const Position& position, Colour colour) {
	Board occupied = 0;
		for(int piecetype = PAWN; piecetype < Pieces::NONE; ++piecetype) {
			occupied |= position.pieces[colour][piecetype];
		}
		return occupied;
}

Board total_occupation(const Position& position) {
	Board total = 0;
	for(int i = Colour::WHITE; i <= Colour::BLACK; ++i)
	{
	for(int piecetype = PAWN; piecetype < Pieces::NONE; ++piecetype) {
		total |= position.pieces[i][piecetype];	
		}
	}
	return total;
}


