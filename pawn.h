/***********************************************************************
 * Header File:
 *    Pawn : The representation of a Pawn
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Everything we need to know about a pawn on the screen
 ************************************************************************/



#include "piece.h"
#include "board.h"
#include <set>
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "uiDraw.h"

using namespace std;

#pragma once
class Pawn: public Piece
{
public:
    Pawn(){};
    Pawn(int r, int c, bool b): Piece{r,c,b} { };

    char getLetter();
    void display(ogstream &gout);
    void getMoves(set<int> &moves, Board &board);
};

