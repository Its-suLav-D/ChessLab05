

/***********************************************************************
 * Source File:
 *    Rook : Represents a Rook that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of Rook
 ************************************************************************/


#include "rook.h"
#include "uiDraw.h"


using namespace std;
char Rook:: getLetter()
{
    return isWhite() ? 'r' : 'R';
}

void Rook:: display(ogstream & gout)
{
    gout.drawRook(position.getLocation(), !fWhite);
}


void Rook:: getMoves(set<int> & moves , Board & Board)
{
    int r;
    int c;
    // MOVES THAT ROOK CAN TAKE
    Delta delta[] = {
                {0,1},
        {-1,0},        {1,0},
                {0,-1}
    };
    
    for(int i =0; i < 4; i++)
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

    
//    for(int i =0; i < 4; i++)
//    {
//        Position posMove(getPosition(), delta[i]);
//        Move move;
//        while(posMove.isValid() && Board.getPiece(posMove.getLocation())->getLetter() == '_')
//        {
//
//
//            // Current Location
//            move.setSource(getPosition());
//
//            // Current Location
//            move.setDestination(posMove);
//
//            move.setWhiteMove(isWhite());
////
//            moves.insert(move);
//        }
//
//        if(posMove.isValid() && (Board.getPiece(posMove.getLocation())->isWhite() != fWhite  || Board.getPiece(posMove.getLocation())->getLetter() == '_'))
//        {
//            move.setSource(getPosition());
//            move.setDestination(posMove);
//            move.setWhiteMove(isWhite());
//
//            if(Board.getPiece(posMove.getLocation())->getLetter() != '_')
//            {
//                move.setCapture(Board.getPiece(posMove.getLocation())->getLetter());
//            }
//            moves.insert(move);
//            // Moves will have INT of Moves at the end
//        }
//    }
//
  
    
    
}
