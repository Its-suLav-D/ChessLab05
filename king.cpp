#include "king.h"

char    King:: getLetter()
{
    return isWhite() ? 'k' : 'K';
}

void King:: display(ogstream * gout)
{
    gout->drawKing(position.getLocation(), fWhite);
}
