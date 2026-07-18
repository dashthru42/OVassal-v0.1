// board representation, bitboard

#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <bit> //for std::countr_zero

using Board = std::uint64_t;

enum squareMappings
	{
	
	a1 = 0, b1, c1, d1, e1, f1, g1, h1, 
	a2, b2, c2, d2, e2, f2, g2, h2, 
	a3, b3, c3, d3, e3, f3, g3, h3, 
	a4, b4, c4, d4, e4, f4, g4, h4, 
	a5, b5, c5, d5, e5, f5, g5, h5, 
	a6, b6, c6, d6, e6, f6, g6, h6, 
	a7, b7, c7, d7, e7, f7, g7, h7, 
	a8, b8, c8, d8, e8, f8, g8, h8 = 63, 

	max_squares
	};

enum class Direction {
	//set direction constants for rays and other purposes
	NORTH = 8,
	SOUTH = -8,
	EAST = 1,
	WEST = -1,
	NORTHEAST = 9,
	NORTHWEST = 7,
	SOUTHEAST = -7,
	SOUTHWEST = -9
};

enum RayDirection {

	RAY_NORTH,
	RAY_SOUTH,
	RAY_EAST,
	RAY_WEST,
	RAY_NORTHEAST,
	RAY_NORTHWEST,
	RAY_SOUTHEAST,
	RAY_SOUTHWEST
};

enum Colour {
	WHITE,
	BLACK
};

enum Pieces {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,

	NONE
};

enum class pieceChar : char32_t  {
		WhiteKing   = U'♔', // 0x2654
    WhiteQueen  = U'♕', // 0x2655
    WhiteRook   = U'♖', // 0x2656
    WhiteBishop = U'♗', // 0x2657
    WhiteKnight = U'♘', // 0x2658
    WhitePawn   = U'♙', // 0x2659
    
	 	BlackKing   = U'♚', // 0x265A
    BlackQueen  = U'♛', // 0x265B
    BlackRook   = U'♜', // 0x265C
    BlackBishop = U'♝', // 0x265D
    BlackKnight = U'♞', // 0x265E
    BlackPawn   = U'♟'  // 0x265F		
};

struct Position
{
	Board pieces[2][6];

	Colour sideToMove;

	int halfmoveClock;

	int fullMove;

	int enPassantSquare = -1;
	
	bool whiteKingCastle;
	bool whiteQueenCastle;
	bool blackKingCastle;
	bool blackQueenCastle;
};
 
void set_start_position(Position& b);
Board side_occupation(const Position& position, Colour colour);
Board total_occupation(const Position& position);


#endif
