#include <iostream>
#include "types.h"
#include "funcs.h"

void printPosition(const Position& position) {
    static const pieceChar symbols[2][6] = {
        {pieceChar::WhitePawn, pieceChar::WhiteKnight, pieceChar::WhiteBishop,
    pieceChar::WhiteRook, pieceChar::WhiteQueen, pieceChar::WhiteKing},
        {pieceChar::BlackPawn, pieceChar::BlackKnight, pieceChar::BlackBishop,
         pieceChar::BlackRook, pieceChar::BlackQueen, pieceChar::BlackKing}
     };

        
            }
        }
    }
}

int main()
{
    Position game;
    set_start_position(game);

    printPosition(total_occupation(game));
	
    return 0;
}
