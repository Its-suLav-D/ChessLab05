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
    void display(ogstream *gout);
//    set <Move> getMoves(const char* board);
};

