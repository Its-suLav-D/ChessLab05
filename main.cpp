//
//  main.cpp
//  Lab05
//
//  Created by Sulav Dahal on 5/17/22.
//

#include <stdio.h>
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"
#include "board.h"
#include "game.h"
#include "pawn.h"
using namespace std;


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/


void callBack( Interface *pUI, void *p)
{
    Game * game = (Game*)p;
    
    ogstream gout;
    game->displayPiece();
        
    
}



/*********************************
 * Initialize the simulation and set it in motion
 *********************************/



#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32


int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
//   Position ptUpperRight;
//   ptUpperRight.setPixelsX(700.0);
//   ptUpperRight.setPixelsY(500.0);
//   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
//   Interface ui(0, NULL,
//      "Demo",   /* name on the window */
//      ptUpperRight);
//
    Interface ui("Chess");
    
//   // Initialize the demo
//   GameState demo(ptUpperRight);
    Game game;
   // set everything into action
//   ui.run(callBack, &demo);
    
    ui.run(callBack,&game);


   return 0;
}
