#include "A_BOARDS.h"
#include "types.h"
#include "funcs.h"

//helper function we can call on to check wrap-around issues and toggle bits on for the attack boards.
//makes it easier to initialise attack boards later.

Board KNIGHT_ATTACK[64];
Board KING_ATTACK[64];
Board PAWNS_ATTACK[2][64];
Board RAY_ATTACK[64][8];


static void toggleOn(std::uint64_t& attacking, int rank, int file)
{
    if(rank >= 0 && rank < 8 && file >= 0 && file < 8) {
        attacking |= 1ULL << (rank * 8 + file);
    }
}

void king_attacks() 
{
    //calculate attacked squares per any given square
    for(int square = 0; square < 64; ++square) {
        
        Board attack = 0;   //the bitboard for, or rather relative TO, the square, important to reset it at this point in the loop
        int rank = square / 8, file = square % 8;

        //for any given square we calculate pseudolegal moves based on the king's geometric movements
        //we are not checking legality yet
        for(int direction_rank = -1; direction_rank < 2; ++direction_rank) {
            for(int direction_file = -1; direction_file < 2; ++direction_file) {
                
                if(direction_rank == 0 && direction_file == 0) {
                    continue;   //a skip for if the king decides to not move
                } 
                
                toggleOn(attack, rank + direction_rank, file + direction_file);
            }
        }
        KING_ATTACK[square] = attack;            
    }
}

void knight_attacks()
{
    for(int square = 0; square < 64; ++square) {
        
        Board attack = 0;
        int rank = square / 8, file = square % 8;

        const int direction_rank[] = {2, 2, -2, -2, -1, -1, 1, 1};
        const int direction_file[] = {1, -1, 1, -1, 2, -2, 2, -2};
        //possible variations for a knight's move

        //cycle through and toggle on the knight's 8 available pseudolegal moves if they're bounded
        for(int i = 0; i < 8; ++i) {
            toggleOn(attack, rank + direction_rank[i], file + direction_file[i]);
        }

        KNIGHT_ATTACK[square] = attack;
    }
}

void pawns_attack()
{
    for(int square = 0; square < 64; ++square) {
        int rank = square / 8, file = square % 8;

        //we need to initialise for the two different-coloured pawn sets
        const int directions[2] = {1, -1};

        for(int i = 0; i < 2; ++i) {
            Board attack = 0;
            toggleOn(attack, rank + directions[i], file - 1);
            toggleOn(attack, rank + directions[i], file + 1); //for both diagonals attacked
            PAWNS_ATTACK[i][square] = attack;
        }
    }   
}


//pre-compute five hundred and twelve attack tables in a[sixty four][eight] two dimensional array per square per direction from that square, for all possible sliding piece combinations; make sure to reset the empty attack board at the very top of each loop

void rayAttacks() 
{
	for(int square = 0; square < 64; ++square) {

		int rank = square / 8;
		int file = square % 8;

		//north
		{
			Board attack = 0ULL;
		for(int r = rank + 1, f = file; r < 8; ++r) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_NORTH] = attack;
			}	
		}

		//south
		{
			Board attack = 0ULL;
		for(int r = rank -1, f = file; r >= 0; --r) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_SOUTH] = attack;
			}
		}

		//east
		{
			Board attack = 0ULL;
		for(int r = rank, f = file + 1; f < 8; ++f) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_EAST] = attack;
			}
		}

		//west
		{
			Board attack = 0ULL;
		for(int r = rank, f = file - 1; f >= 0; --f) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_WEST] = attack;
			}
		}

		//northeast
		{
			Board attack = 0ULL;
		for(int r = rank + 1, f = file + 1; r < 8 && f < 8; ++r, ++f) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_NORTHEAST] = attack;
			}
		}

		//northwest
		{
			Board attack = 0ULL;
		for(int r = rank + 1, f = file - 1; r < 8 && f >= 0; ++r, --f) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_NORTHWEST] = attack;
			}
		}

		//southeast
		{
			Board attack = 0ULL;		
		for(int r = rank -1, f = file + 1; r >= 0 && f < 8; --r, ++f) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_SOUTHEAST] = attack;
			}	
		}

		//southwest
		{
			Board attack = 0ULL;
		for(int r = rank - 1, f = file - 1; r >= 0 && f >= 0; --r, --f) {
			toggleOn(attack, r, f);
			RAY_ATTACK[square][RAY_SOUTHWEST] = attack;
			}
		}
	}

}

Board rookAttacks(Board occupied, int square) {
	Board rook_attack = 0;
	rook_attack |= getPositiveRay(occupied, square, RAY_NORTH) |
	               getNegativeRay(occupied, square, RAY_SOUTH) |
	               getPositiveRay(occupied, square, RAY_EAST) |
	               getNegativeRay(occupied, square, RAY_WEST);

	return rook_attack;
}

void initialize_attacks()
{
    king_attacks();
    knight_attacks();
    pawns_attack();
    rayAttacks();
}
