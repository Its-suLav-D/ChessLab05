#include "piece.h"
#include "board.h"
#include <set>
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "uiDraw.h"

using namespace std;

#pragma once

class Queen: public Piece
{
public:
    Queen(){};
    Queen(int r, int c, bool b): Piece(r,c,b){};
    char getLetter();
    void display(ogstream &gout);
//    set<int> getMoves(const char * board);
};

