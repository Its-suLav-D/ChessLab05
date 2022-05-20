
#include "piece.h"
#include "board.h"
#include <set>
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "uiDraw.h"

using namespace std;

#pragma once

class Knight: public Piece
{
public:
    Knight(){};
    Knight(int r, int c, bool b): Piece(r,c,b){};
    char getLetter();
    void display(ogstream &gout);
    void getMoves(set<int> &moves, Board &board);
};
