//
//  piece.cpp
//  Lab05
//
//  Created by Sulav Dahal on 5/17/22.
//

#include "piece.h"


Piece:: Piece(int row, int col, bool isWhite)
{
    Position p(row, col);
    fWhite = isWhite;
    nMoves =0;
    lastMove = -1;
}
