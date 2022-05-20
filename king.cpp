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
        
        // Black Knight
        if(!isWhite() && Board.isNotBlack(r, c))
            moves.insert(r*8+c);
        
        // White Knight
        if(isWhite() && Board.isNotWhite(r, c))
            moves.insert(r*8+c);
        
        // Work on Castling Move
    }
}
