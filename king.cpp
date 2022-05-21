/***********************************************************************
 * Source File:
 *    King : Represents a King that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of King 
 ************************************************************************/



#include "king.h"

char    King:: getLetter()
{
    return isWhite() ? 'k' : 'K';
}

void King:: display(ogstream  &gout)
{
    gout.drawKing(position.getLocation(), !fWhite);
}


void King:: getMoves(set<int> & moves , Board & Board)
{
    int r;
    int c;
    
    int space_1;
    int space_2;
    int space_3;
    
    Delta  delta[] =
    {
        {-1,  1}, {0,  1}, {1,  1},
        {-1,  0},          {1,  0},
        {-1, -1}, {0, -1}, {1, -1}
     };
    
    for(int i = 0; i < 8; i++)
    {
        r = getPosition().getRow() + delta[i].dRow;
        c = getPosition().getCol() + delta[i].dCol;
        
        // Black King
        if(!isWhite() && Board.isNotBlack(r, c))
            moves.insert(r*8+c);
        
        // White King
        if(isWhite() && Board.isNotWhite(r, c))
            moves.insert(r*8+c);
    }
    int row = getPosition().getRow();
    int col = getPosition().getCol();
    
    space_1 = getPosition().getCol()+1;
    space_2 =getPosition().getCol()+2;
    space_3 = getPosition().getCol() + 3;
    // Black King Check Castling Move RIGHT
    if(!isWhite() &&
       row ==0 &&
       Board.getPiece(row,space_1)->getLetter() == '_' &&
       Board.getPiece(row,space_2)->getLetter() == '_' &&
       Board.getPiece(row, col)->getNMoves() == 0 &&
       Board.getPiece(row,space_3)->getLetter() == 'R' &&
       Board.getPiece(row,space_3)->getNMoves() == 0
       )
    {
        moves.insert(row*8+space_3);
    }
    
    // White KING CASTLING MOVE LEFT
    space_1 = getPosition().getCol()+1;
    space_2 =getPosition().getCol()+2;
    space_3 = getPosition().getCol()+ 3;
    
    if(isWhite() &&
       Board.getPiece(row,space_1)->getLetter() == '_' &&
       Board.getPiece(row,space_2)->getLetter() == '_' &&
       Board.getPiece(row,col)->getNMoves() == 0 &&
       Board.getPiece(row,space_3)->getLetter() == 'r' &&
       Board.getPiece(row,space_3)-> getNMoves() == 0
       )
        
    {
        moves.insert(row*8+space_3);
    }
    
    
}
