// board representation, bitboard

#ifndef MY_BOARD_H
#define MY_BOARD_H

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <bit> //for std::countr_zero

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

struct Config
{
	enum class squareMappings
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

	//declare the twelve bitboards, add methods later
	
	using Board = std::uint64_t;	//alias for bitboards

// BITBOARDS

// white
Board whitePawns   = 0x000000000000FF00ULL; // rank 
Board whiteKnights = 0x0000000000000042ULL; // b1 g1
Board whiteBishops = 0x0000000000000024ULL; // c1 f1
Board whiteRooks   = 0x0000000000000081ULL; // a1 h1
Board whiteQueen   = 0x0000000000000008ULL; // d1
Board whiteKing    = 0x0000000000000010ULL; // e1

// black
Board blackPawns   = 0x00FF000000000000ULL; // rank 
Board blackKnights = 0x4200000000000000ULL; // b8 g8
Board blackBishops = 0x2400000000000000ULL; // c8 f8
Board blackRooks   = 0x8100000000000000ULL; // a8 h8
Board blackQueen   = 0x0800000000000000ULL; // d8
Board blackKing    = 0x1000000000000000ULL; // e8

Board whitePieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueen | whiteKing;
Board blackPieces = blackPawns | blackKnights | blackBishops | blackRooks | blackQueen | blackKing;

Board allPieces = whitePieces | blackPieces;


	//composite boards, can't store as members bc will only be valid for
	//starting position, need to either have a function that recalibrates
	//on command, or an automated function for any change,
	//have to figure this out soon. 
	
	
//board with no pieces
	Board noPieces = 0ULL;


//attack tables/functions
//possible mode: attack/move by update of bitboard, relocation

//Board whiteKnights >> 0x000...2ULL -> func moveTo(Config& board) :: [ >> square... if occupied then error Not legal move]

	friend void printBoard(const Config& bb); 
}; 

#endif
