#include "knight.h"

char Knight:: getLetter()
{
    return isWhite() ? 'n' : 'N';
}

void Knight:: display(ogstream &gout)
{
    gout.drawKnight(position.getLocation(), !fWhite);
}
