#include"position.h"
#include "uiDraw.h"
#include <set>
#pragma once


using namespace std;


class Move;
class Board;

class Piece
{
protected:
    Position position;
    bool fWhite;
    int nMoves;
    int lastMove;
    
public:
    // Constructors
    Piece(){};
    Piece(int r, int c, bool white=true);
    
    Piece(const Piece &piece)   {*this = piece;}
    

    
    bool isWhite() const    {return fWhite;}
    int getLastMove() const {return lastMove; }
    int getNMoves()const    {return nMoves;}
    bool isMoved() const    {return getNMoves() !=0; }
    
    const Position & getPosition() const {return position;}
    
    bool justMoved(int currentMove) const
    {
        return (currentMove-1 == lastMove);
    }
    
    void setLastMove(int currentMove) {lastMove = currentMove;}
    
    // Virtual Methods
    virtual char getLetter()     = 0;
    virtual void display(ogstream  & gout)   = 0;
//    virtual void getMoves(set<Move> & moves, const Board & board)    = 0;
    
    // Operators
    bool operator == (char letter)  {   return getLetter() == letter;   }
    bool operator != (char letter)  {   return getLetter() != letter;   }
    
    
    
    // Assignment Operator Position
    const Piece& operator = (const Position &rhs)
    {
        // Increase the Move for the Piece
        nMoves++;
        position = rhs;
        return *this;
    }
    
    // Assignment Operator Piece
    const Piece& operator = (const Piece& rhs);

};

