/***********************************************************************
 * Source File:
 *    Board : Represents the board in the chess game
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Where the board is draw, pieces are drawn and where all the moves
 *    takes place
 ************************************************************************/
#include "board.h"
#include "pawn.h"
#include "space.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"


// OMG OMG OMG THIS WORKS
void Board::swap(int posFrom, int posTo)
{
    // SWAP THE POINTERS
    Piece * tempP = board[posTo];
    
    Piece *p1 = board[posFrom];
    Piece *p2 = board[posTo];
    
    
    // CHECK FOR ENPASSANT
    if((board[posFrom-1]->isWhite() &&
       board[posFrom-1]->getNMoves() == 1 && board[posTo]->getLetter() == '_') ||
       ( board[posFrom+1]->isWhite() &&
        board[posFrom+1]->getNMoves() ==1 && board[posTo]->getLetter() == '_'
        )
    )
    {
        int movingToCol = posTo % 8;
        
        int r= posTo-1;
        int c = posTo;
  
        Space * newSpace = new Space(r, c, true);
        // Attack Right
        if(movingToCol > posFrom % 8)
        {
          
            board[p2->getPosition().getLocation()] = p1;
            board[p1->getPosition().getLocation()] = tempP;
            
            Piece * tempPiece = board[posFrom+1];
            
            board[posFrom+1] = newSpace;
            
            delete tempPiece;
        }
        else
        {
            // Attack Left
            board[p2->getPosition().getLocation()] = p1;
            board[p1->getPosition().getLocation()] = tempP;
            
            Piece * tempPiece = board[posFrom-1];
            
            board[posFrom-1] = newSpace;
            
            delete tempPiece;
            
        }
    }
    else if (
             (board[posFrom-1]->isWhite() == false &&
                board[posFrom-1]->getNMoves() == 1 && board[posTo]->getLetter() == '_') ||
                ( board[posFrom+1]->isWhite()  == false &&
                 board[posFrom+1]->getNMoves() ==1 && board[posTo]->getLetter() == '_'
                 )
             )
    {
         // Attack RIGHT
        
        int movingToCol = posTo % 8;
        
        int r= posTo-1;
        int c = posTo;
  
        Space * newSpace = new Space(r, c, true);
        
        if(movingToCol > posFrom % 8)
        {
          
            board[p2->getPosition().getLocation()] = p1;
            board[p1->getPosition().getLocation()] = tempP;
            
            Piece * tempPiece = board[posFrom+1];
            
            board[posFrom+1] = newSpace;
            
            delete tempPiece;
        }
        else
        {
            // Attack LEFT
            board[p2->getPosition().getLocation()] = p1;
            board[p1->getPosition().getLocation()] = tempP;
            
            Piece * tempPiece = board[posFrom-1];
            
            board[posFrom-1] = newSpace;
            
            delete tempPiece;
        }
        
    }

    else
    {
        
        board[p2->getPosition().getLocation()]  =  p1;
        
        board[p1->getPosition().getLocation()] = tempP;
        
    }


    
    // UPDATE THE POSITION
    Position  temp = p1->getPosition();
    p1->getPosition() = p2-> getPosition();
    p2->getPosition() = temp;
    
    // Handle Pawn Promotion
    if(posTo / 8 == 7 && board[posTo]->getLetter() =='P')
    {
        int r= posTo / 8;
        int c = posTo % 8;
        this->promoteQ(r, c, false);
    }
    if(posTo / 8 ==0 && board[posTo]->getLetter() == 'p')
    {
        int r = posTo / 8;
        int c= posTo % 8;
        this->promoteQ(r, c, true);
    }
    
    
}

void Board::swapCapture(int posFrom, int posTo)
{
    // Where I wanted to go was opponent Piece
    
    Space * newSpace = new Space(posFrom / 8, posFrom % 8, true);
    
    int row = posTo / 8;
    
    // SWAP THE POINTERS
    Piece * tempP = board[posTo];
    
    Piece *p1 = board[posFrom];
    Piece *p2 = board[posTo];
    
    


   
    board[p2->getPosition().getLocation()]  =  p1;
        
    board[p1->getPosition().getLocation()] = tempP;
        
  
     
    // UPDATE THE POSITION
    Position  temp = p1->getPosition();
    p1->getPosition() = p2-> getPosition();
    p2->getPosition() = temp;
    
    board[p2->getPosition().getLocation()] = newSpace;
    
    delete tempP;
    
    
    if(row == 7 && board[posTo]->getLetter() == 'P')
    {
        int r= posTo / 8;
        int c = posTo % 8;
        this->promoteQ(r, c, false);
    }
    if(row ==0 && board[posTo]->getLetter()== 'p')
    {
        int r = posTo / 8;
        int c= posTo % 8;
        this->promoteQ(r, c, true);
    }
    
}



void Board:: reset()
{

   // Black Down
    for (int i = 8; i < 16; i++)
       {
           Pawn *pawn = new Pawn(0,i,false);
           board[i] = pawn;
       }

       //white UP
    int count =0;
    for (int i = 48; i < 56; i++)
       {
           Pawn *pawn = new Pawn((i/8), count, true);
           board[i] = pawn;
           count++;
       }


    //instantiate spaces
    for (int i = 2; i < 6; i++)
       {
           for (int x = 0; x < 8; x++)
           {
               Space * space = new Space(i, x, true);
               board[(i * 8) + x] = space;
           }
       }
    
    // Black is DOWN
        Rook * rookLeft = new Rook(0, 0, false);
        Rook * rookRight = new Rook(0, 7, false);
        board[0] = rookLeft;
        board[7] = rookRight;
    
    // Delete Me Just Testing the Possible Moves
//        Rook * rookTest = new Rook(2,0,false);
//        board[16] = rookTest;
    

        Knight* knightLeft = new Knight(0, 1, false);
        Knight* knightRight = new Knight(0, 6, false);
        
        board[1] = knightLeft;
        board[6] = knightRight;

        Bishop * bishopLeft = new Bishop(0, 2, false);
        Bishop * bishopRight = new Bishop(0, 5, false);
    
        // DELETE ME I AM TESTING BISHOP
    
//    Bishop * testBishop = new Bishop(2,2,false);
//    board[18] = testBishop;

        board[2] = bishopLeft;
        board[5] = bishopRight;

        Queen * queen = new Queen(0, 3, false);
        board[3] = queen;
    
        // DELET ME I AM TESTING QUEEN
        
//    Queen * testQueen = new Queen(2,4,false);
//    board[20] = testQueen;
    
    
        King * king = new King(0, 4, false);
        board[4] = king;
    
        // DELTE ME I AM TESTING KING
//
//    King * testKing = new King(3,4,false);
//    board[28] = testKing;
    
    
    // ASSIGN WHITE TO BOARD
        Rook * rookLeftWhite = new Rook(7, 0, true);
        Rook * rookRightWhite = new Rook(7, 7, true);
        board[56] = rookLeftWhite;
        board[63] = rookRightWhite;


        Knight* knightLeftWhite = new Knight(7, 1, true);
        Knight *knightRightWhite = new Knight(7, 6, true);
        board[57] = knightLeftWhite;
        board[62] = knightRightWhite;

        Bishop* bishopLeftWhite = new Bishop(7, 2, true);
        Bishop* bishopRightWhite = new Bishop(7, 5, true);
        board[58] = bishopLeftWhite;
        board[61] = bishopRightWhite;

        Queen *queenWhite = new Queen(7, 3, true);
        board[59] = queenWhite;

        King *kingWhite = new King(7, 4, true);
        board[60] = kingWhite;
    

    // TEST PAWN FOR ATTACKING LEFT
    
//    Pawn * testWhitePawn = new Pawn(2,1,true);
//    board[17] = testWhitePawn;

}


Board :: Board():currentMove(0)
{

    reset();
}
// BlACK IS UPPER CASE
bool Board:: isNotBlack(int row, int col)
{
     if (row < 0 || row >= 8 || col < 0 || col >= 8)
       return false;
    
    char letter = board[row*8+col]->getLetter();
    
    return letter == '_' || (letter >= 'a' && letter <= 'z');
}

// WHITE IS LOWER CASE
bool Board:: isNotWhite(int row , int col )

{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   
   char letter = board[row*8+col]->getLetter();
   
   return letter == '_' || (letter >= 'A' && letter <= 'Z');
}

void Board:: display(int posHover, int posSel)
{
    gout.drawBoard();
    gout.drawHover(posHover);
    gout.drawSelected(posSel);
    
    // If the selected Position was valid draw the possible moves;
    if (posSel >=0 && posSel < 64)
    {
        set<int> possible;
        board[posSel]->getMoves(possible, *this);
                
//        for(it = possible.begin(); it != possible.end(); ++it)
        
        //All It needs is a set of INT where the piece can go.
        for(auto itr : possible)
            gout.drawPossible(itr);
                    
    }
    
    for(int i=0; i< 64; i++)
        board[i]->display(gout);
    
//    // DISPLAY KNIGHT
//    board[1]->display(gout);
//    board[6]-> display(gout);
//
//    // DISPLAY KNIGHT
//    board[57]->display(gout);
//    board[62]-> display(gout);
//
//    // Display ROOK
//    board[16]->display(gout);
//
//    // DISPLAY TEST BISHOP
//    board[18]->display(gout);
//
//    // DISPLAY TEST QUEEN
//
//    board[20]->display(gout);
//
//
//    // DISPLAY TEST KING
//
//    board[28]->display(gout);
    
    
}

void Board:: move(int posFrom, int posTo)
{
   
    Piece * checkPiece = board[posTo];
    // SWAP NON CAPTURING MOVE
    if(checkPiece->getLetter() == '_')
    {
         
        this->swap(posFrom,posTo);
    }
   
    else
    {
        Piece * checkP = board[posFrom];
        
        // CHECK FOR CASTLING MOVE
        if( (checkP->getLetter()=='k' || checkP-> getLetter() =='K') &&
           (checkPiece->getLetter() == 'R' || checkPiece->getLetter() == 'r')  &&
           (board[posFrom+1]->getLetter() == '_' &&board[posFrom+2]->getLetter() == '_' )

        )
        {
            if(checkP->getLetter()== 'K')
            {
                if( checkPiece->getLetter() == 'R' &&
                board[posFrom+1]->getLetter() == '_' &&
                checkPiece->getNMoves() == 0 &&
                checkP->getNMoves() == 0)
                {
                    this ->castleK(posFrom, posTo);
                }
            }
            else
            {
                if(checkPiece->getLetter() == 'r' &&  board[posFrom+1]->getLetter() == '_' &&
                   checkPiece->getNMoves() == 0 &&
                   checkP->getNMoves() == 0)
                {
                    this-> castleK(posFrom, posTo);
                }
            }
        }
        
        else
        {
            this->swapCapture(posFrom, posTo);
        }

        
       
    }

    
    board[posTo]->setNMoves(1);
    
}


void Board:: promoteQ(int r, int c, bool white)
{
    Piece * tempPiece = board[r*8+c];
    Queen * newQueen = new Queen(r,c,white);
    board[r*8+c] = newQueen;
    

    delete tempPiece;
    
}

void Board:: castleK(int posFrom, int posTo)
{
    
    int rookNewLoc = posFrom+1;
    int kingNewLoc = posTo-1;
    
    Piece *tempSpace = board[rookNewLoc];
    
    Piece *tempSpaceKing = board[kingNewLoc];
    
    // From is King
    Piece *p1 = board[posFrom];
    
    // To is Rook
    Piece *p2 = board[posTo];
    
    
    // SWAP ROOK WITH SPACE
    board[rookNewLoc] = p2;
    Space * newSpace = new Space(posTo/8, posTo%8, true);
    board[posTo] = newSpace;
    
    board[rookNewLoc]->getPosition() = tempSpace->getPosition();

    

    // SWAP KING WITH ROOK
    
    board[kingNewLoc] = p1;
    Space *newSpaceKing = new Space(posFrom/8, posFrom%8, true);
    board[posFrom] = newSpaceKing;
    
    board[kingNewLoc]->getPosition() = tempSpaceKing->getPosition();
    

}


void Board::capture()
{
    
}


