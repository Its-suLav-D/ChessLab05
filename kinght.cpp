#include "knight.h"

char Knight:: getLetter()
{
    return isWhite() ? 'n' : 'N';
}

void Knight:: display(ogstream &gout)
{
    gout.drawKnight(position.getLocation(), !fWhite);
}


void Knight:: getMoves(set<int> & moves , Board & Board)
{
    int r;
    int c;
    
    Delta delta[] =
    {
                  {-1,  2}, { 1,  2},
         {-2,  1},                    { 2,  1},
         {-2, -1},                    { 2, -1},
                  {-1, -2}, { 1, -2}
    };
    
    for(int i =0; i < 8; i++)
    {
    
        r = getPosition().getRow() + delta[i].dRow;
        c = getPosition().getCol() + delta[i].dCol;
        
        // Black Knight
        if(!isWhite() && Board.isNotBlack(r, c))
            moves.insert(r*8+c);
        
        // White Knight
        if(isWhite() && Board.isNotWhite(r, c))
            moves.insert(r*8+c);
    }
}
