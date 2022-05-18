#include "queen.h"



char Queen:: getLetter()
{
    return isWhite() ? 'q' : 'Q';
}

void Queen:: display(ogstream & gout)
{
    gout.drawQueen(position.getLocation(), !fWhite);
}
