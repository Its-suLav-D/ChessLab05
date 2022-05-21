/***********************************************************************
 * Header File:
 *    Piece : The representation of a Piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Everything we need to know about a piece on the screen
 ************************************************************************/



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
    
    
    virtual ~ Piece(){};

    
    bool isWhite() const    {return this->position.isValid() ? fWhite : false ;}
    int getLastMove() const {return lastMove; }
    int getNMoves()const    {return nMoves;}
    bool isMoved() const    {return getNMoves() !=0; }
    
    Position & getPosition()  {return position;}
    
    bool justMoved(int currentMove) const
    {
        return (currentMove-1 == lastMove);
    }
    
    void setNMoves(int nMove) {nMoves+= nMove;}
    void setLastMove(int currentMove) {lastMove = currentMove;}
    
    // Virtual Methods
    virtual char getLetter()     = 0;
    virtual void display(ogstream  & gout)   = 0;
    virtual void getMoves(set<int> & moves,  Board & board)  = 0;
    
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

