#include "rook.h"
#include "uiDraw.h"


char Rook:: getLetter()
{
    return isWhite() ? 'r' : 'R';
}

void Rook:: display(ogstream & gout)
{
    gout.drawRook(position.getLocation(), !fWhite);
}
