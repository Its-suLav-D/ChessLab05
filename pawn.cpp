#include "pawn.h"


char Pawn::getLetter()
{
   if (isWhite())
      return 'p'; // lowercase
   else
      return 'P'; //upppercase
}

void Pawn::display(ogstream &gout)
{
 
    gout.drawPawn(position.getLocation(), !fWhite);
}

//void Pawn:: getMoves(set<Move> & moves , Board & Board)
//{
//
//}
