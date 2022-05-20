#include "queen.h"



char Queen:: getLetter()
{
    return isWhite() ? 'q' : 'Q';
}

void Queen:: display(ogstream & gout)
{
    gout.drawQueen(position.getLocation(), !fWhite);
}


void Queen:: getMoves(set<int> & moves , Board & Board)
{
    
    int r;
    int c;
    
    Delta  delta[] =
    {
       {-1,  1}, {0,  1}, {1,  1},
       {-1,  0},          {1,  0},
       {-1, -1}, {0, -1}, {1, -1}
    };
    
    for(int i =0; i < 8; i++)
    {
        r = getPosition().getRow() + delta[i].dRow;
        c = getPosition().getCol() + delta[i].dCol;
        
        while(r>=0 && r <8 && c>=0 && c < 8 && Board.getPiece(r*8+c)->getLetter() == '_')
        {
            moves.insert(r*8+c);
            r += delta[i].dRow;
            c += delta[i].dCol;
        }
        
        
        // Black Knight
        if(!isWhite() && Board.isNotBlack(r, c))
            moves.insert(r*8+c);
        
        // White Knight
        if(isWhite() && Board.isNotWhite(r, c))
            moves.insert(r*8+c);
    }
    
}
