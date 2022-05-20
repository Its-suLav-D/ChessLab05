//
//  move.h
//  Lab05
//
//  Created by Sulav Dahal on 5/17/22.
//

#include <string>
#include "position.h"
#include <set>
using namespace std;

#pragma  once
class Move
{
private:
    Position source;
    Position destination;
    
    char piece;
    char capture;
    bool enpassant;
    bool castleK;
    bool castleQ;
    bool isWhite;
    string error;
public:
    Move(){};
    string getText();
    Position getSource(){return source; }
    Position getDestination(){return destination; }
    char getPromotion();
    // from | to | x
    // 'x' Means Capture
    char getCapture(){return capture;}
    bool getEnPassant();
    bool getCastleK();
    bool getCastleQ();
    bool getWhiteMove(){return isWhite; }
    
    // Setters
    void setEnPassant();
    void setCastleQ();
    void setCastleK();
    void isWhiteMove();
    void setCapture(char c){capture = c;}
    void assign(string s );
    
    
    void setSource(Position & pos){source = pos;}
    void setDestination(Position &pos){destination = pos;}
    void setWhiteMove(bool white)
    {
        isWhite = white;
    }
    
    // Operators
    bool operator < ( Move & left)
    {
        return source.getLocation() < left.source.getLocation();
    }

};
