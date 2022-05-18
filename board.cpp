//
//  board.cpp
//  Lab05
//
//  Created by Sulav Dahal on 5/17/22.
//

// I get Bad Access when I try to display the Piece in the Board.

#include "board.h"
#include "pawn.h"
#include "space.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"



void Board:: reset()
{

   // Black Down
    for (int i = 8; i < 16; i++)
       {
           Pawn *pawn = new Pawn(0,i,false);
           // It doesn't Assign the location to the Piece
           // After it's done with the Position Class
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

        Knight* knightLeft = new Knight(0, 1, false);
        Knight* knightRight = new Knight(0, 6, false);

        board[1] = knightLeft;
        board[6] = knightRight;

        Bishop * bishopLeft = new Bishop(0, 2, false);
        Bishop * bishopRight = new Bishop(0, 5, false);

        board[2] = bishopLeft;
        board[5] = bishopRight;

        Queen * queen = new Queen(0, 3, false);
        board[3] = queen;

        King * king = new King(0, 4, false);
        board[4] = king;
    
    
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

}


Board :: Board()
{
    reset();
}

void Board:: display()
{
    gout.drawBoard();
    
    for(int i =0; i < 64; i++)
    {
        board[i]->display(gout);
    }
}
