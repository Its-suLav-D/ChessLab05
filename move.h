//
//  move.h
//  Lab05
//
//  Created by Sulav Dahal on 5/17/22.
//


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
    Move();
    string getText();
    Position getSource();
    Position getDestination();
    char getPromotion();
    char getCapture();
    bool getEnPassant();
    bool getCastleK();
    bool getCastleQ();
    bool getWhiteMove();
    void setEnPassant();
    void setCastleQ();
    void setCastleK();
    void isWhiteMove();
    void assign(string s );
    
    // Operators
    

};
