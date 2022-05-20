#include "piece.h"
#include "move.h"
#include "position.h"
#include "uiInteract.h"

using namespace std;

#pragma once


class Board
{
private:
    //member variables
    Piece* board[64];
    ogstream gout;
    void assertBoard();
    int currentMove; // Which Move I am currently On
    void swap(Position &pos1, Position &pos2);
    void swap(int pos1, int pos2);
    void swapCapture(int posFrom, int posTo); 
public:
    Board();
    Board(ogstream gout);
    int getCurrentMove(){   return currentMove; }
    bool whiteTurn() {  return currentMove % 2 ==0; }
    void display(int posHover,int posSel);
    Piece * get(Position pos){return board[pos.getLocation()];}
    Piece * getPiece(int pos) {return board[pos]; };
    
 
    Piece ** getBoard(){return board;};
    
    Piece* getPiece(int row, int col)
    {
        return board[row*8+col];
    }
    
    bool isNotBlack(int row, int col);
    bool isNotWhite(int row, int col);
    
    void free();
    void reset();
    void move(int posFrom, int posTo);
    void displayPieces();
    
    void promoteQ(int r, int c, bool white);
    
    void capture();
    
   
    // Assignment Operator
    
    // Subscript Operator
    Piece *operator [] (int index)
    {
        return board[index];
    }
    
        
};
