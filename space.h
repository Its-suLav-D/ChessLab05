
#include "board.h"
#include <fstream>        // for IFSTREAM
#include <string>
#include <set>
#include "uiDraw.h"
using namespace std;

#pragma once
class Space : public Piece
{
public:
    Space(){};
    Space(int r, int c, bool b): Piece(r,c,b){};
    char getLetter();
    void display(ogstream &gout);
//    set <int> getMoves(const char * board);
};
