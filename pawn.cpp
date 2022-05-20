#include "pawn.h"

using namespace std;
char Pawn::getLetter()
{
   if (isWhite())
      return 'p'; // lowercase
   else
      return 'P'; //upppercase
}

void Pawn::display(ogstream &gout)
{
 
    gout.drawPawn(position.getLocation(), !fWhite);
}

void Pawn:: getMoves(set<int> & moves , Board & board)
{

    int r;
    int c;
    
    int row = getPosition().getRow();
    int col = getPosition().getCol();
    
    int location = getPosition().getLocation();
    
    // BLACK PAWN
    if(board.getPiece(location)->getLetter() == 'P')
    {
        c = col;
        r = row +2;
        
        // FORWARD TWO BLANK SPACE
        if (row == 1 && board.getPiece(r*8+c)->getLetter() == '_')
           moves.insert(r * 8 + c);
        
        r = row+1;
        // FORWARD ONE BLANK SPACE
        if(r>=0 && r<8 && board.getPiece(r*8+c)->getLetter() == '_')
        {
            moves.insert(r*8+c);
        }
        c= col-1;
        // ATTACK LEFT
        if(board.getPiece(r,c)->isWhite() == true && (board.getPiece(r,c)->getLetter() >= 'a' && board.getPiece(r,c)->getLetter()<='z' )
           )
        {
            moves.insert(r*8+c);
        }
        c= col+1;
        // ATTACK RIGHT
        
        if(board.getPiece(r,c)->isWhite() == true &&(board.getPiece(r,c)->getLetter() >= 'a' && board.getPiece(r,c)->getLetter()<='z' )
           
           )
            moves.insert(r*8+c);
        
        // ENPASSANT DIAGONAL LEFT-- OMG THIS WORKS TOOOOO
        c = col-1;
        r = row;
        if(board.getPiece(r,c)->justMoved(board.getCurrentMove()) &&
               board.getPiece(r,c)->getNMoves() == 1 &&
               board.getPiece(r,c)->isWhite() == true &&
               board.getPiece((r++)*c)->getLetter() == '_'
               )
            {
                moves.insert(r*8+c);
            }
        // ENPASSANT DIAGONAL RIGHT-- OMG THIS WORKS TOOOOO
        
        c = col +1;
        r = row;
        
        if(board.getPiece(r,c)->justMoved(board.getCurrentMove()) &&
               board.getPiece(r,c)->getNMoves() == 1 &&
               board.getPiece(r,c)->isWhite() == true &&
               board.getPiece((r+1)*c)->getLetter() == '_'
               )
            {
                r++;
                moves.insert(r*8+c);
            }
        
        // PAWN PROMOTION
//        c = col;
//        r = row;
//        if(board.getPiece(r,c)->getPosition().getRow() == 7
//           )
//        {
//            board.promoteQ(r,c);
//        }
//
        
    }
    else
    {
        c = col;
        r = row -2;
        
        // FORWARD TWO BLANK SPACE
        if (row == 6 && board.getPiece(r*8+c)->getLetter() == '_')
           moves.insert(r * 8 + c);
        
        r = row-1;
        // FORWARD ONE BLANK SPACE
        if(r>=0 && board.getPiece(r*8+c)->getLetter() == '_')
        {
            moves.insert(r*8+c);
        }
        
        // ATTACK LEFT
        c = col -1;
        if(board.getPiece(r,c)->isWhite() == false && ( board.getPiece(r,c)->getLetter() >= 'A' &&
        board.getPiece(r,c)->getLetter() <= 'Z')
        )
        {
            moves.insert(r*8+c);
        }
        
        // ATTACK RIGHT
        c = col +1;
        if(board.getPiece(r,c)->isWhite() == false && ( board.getPiece(r,c)->getLetter() >= 'A' &&
        board.getPiece(r,c)->getLetter() <= 'Z')
           )
        {
            moves.insert(r*8+c);
        }
        
        // ENPASSANT DIAGONAL LEFT -- OMG THIS WORKS TOOOOO
        c = col -1;
        r= row;
        if(board.getPiece(r,c)->isWhite() == false &&
           board.getPiece(r,c)->justMoved(board.getCurrentMove()) &&
           board.getPiece(r,c)->getNMoves() == 1 &&
           board.getPiece((--r),c)->getLetter() == '_'
           )
        {
            moves.insert(r*8+c);
        }
        
        // ENPASSANT DIAGONAL RIGHT-- OMG THIS WORKS TOOOOO
        c= col +1;
        r = row;
        if(board.getPiece(r,c)->isWhite() == false &&
           board.getPiece(r,c)->justMoved(board.getCurrentMove()) &&
           board.getPiece(r,c)->getNMoves() == 1 &&
           board.getPiece((--r),c)->getLetter() == '_'
           )
        {
            moves.insert(r*8+c);
        }
        
        // PAWN PROMOTION
        
    
        
    }
    
}
