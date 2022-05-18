//
//  game.cpp
//  Lab05
//
//  Created by Sulav Dahal on 5/17/22.
//

#include <stdio.h>
#include "game.h"

Game:: Game()

{
    boardInstance = new Board();
}
void Game:: displayPiece()
{
    
    this->boardInstance->display();
}
