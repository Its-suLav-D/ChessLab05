#include "bishop.h"


char Bishop:: getLetter()
{
    return isWhite() ? 'b' : 'B';
}

void Bishop:: display(ogstream &gout)
{
    gout.drawBishop(position.getLocation(), !fWhite);
}
