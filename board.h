#include "piece.h"
#include "move.h"
#include "position.h"

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

public:
    Board();
    Board(ogstream gout);
    int getCurrentMove(){   return currentMove; }
    bool whiteTurn() {  return currentMove % 2 ==0; }
    void display(int posHover, int posSel);
    const Piece get(Position pos);
    void free();
    void reset();
    void move(Move & Move);
    void display();
    
    // Assignment Operator
    
    // Subscript Operator
    Piece *operator [] (int index)
    {
        return board[index];
    }
        
};
