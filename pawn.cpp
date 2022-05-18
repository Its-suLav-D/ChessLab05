#include "pawn.h"


char Pawn::getLetter()
{
   if (isWhite())
      return 'p'; // lowercase
   else
      return 'P'; //upppercase
}

void Pawn::display(ogstream *gout)
{
   // not evven going to deal with that yet.
    gout->drawPawn(position.getLocation(), fWhite);
}
