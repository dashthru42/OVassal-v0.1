//creating attack boards for non-sliding pieces
#ifndef A_BOARDS_H
#define A_BOARDS_H

#include <cstdint>
#include "types.h"

//initialise an array of sixty-four bitboards per piece type; individual attack bitboards will be stored
//which will toggle on attacked squares per given origin point; e.g. KNIGHT_ATTACK[eighteen] = attack_board will toggle
//on the bits of that given bitboard for square eighteen.

//global arrays storing the sixty-four bitboards per position
extern Board KNIGHT_ATTACK[64];
extern Board KING_ATTACK[64];
extern Board PAWNS_ATTACK[2][64];    //since pawn will attack in opposite directions we need a 2d array for white and black

extern Board RAY_ATTACK[64][8]; //array of sixty-four bitboards, one per square, with each square considering every direction {north, sout, east, west, etc..}}

void king_attacks();

void knight_attacks();

void pawns_attack();

void rayAttacks();

Board rookAttacks(Board occupied, int square);

Board bishopAttacks(Board occupied, int square);

Board queenAttacks(Board occupied, int square);


//remember to update this to include sliding pieces
void initialize_attacks();


#endif
