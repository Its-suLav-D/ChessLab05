/*************************************************************
 * 1. Name:
 *      Sulav Dahal and Jeremy Busch
 * 2. Assignment Name:
 *      Lab 05: Chess Code Complete
 * 3. Assignment Description:
 *      The code complete part of the project is all the functionality has been
 *      added and there are just a few bugs to work out
 * 4. What was the hardest part? Be as specific as possible.
 *      Getting the Moves was the hardest part, espeically the pawn.
 *      Also the Castling part was Hard. Not gonna lie it was brutal.
 *      All the Hidden errors and debugging stuff hurt our brain.
 * 5. How long did it take for you to complete the assignment?
 *      We took more than 24 hours and hardly worked on other assignments.
 *      Started working on it from Monday and this is where we stand.
 *****************************************************************/

#include <stdio.h>
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"
#include "board.h"
#include "game.h"
#include "pawn.h"
#include "move.h"
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
    // Cast the Void Pointer to the game object
    Board * board = (Board*)p;
    

    set<int> moves;
    

    if(pUI->getPreviousPosition() >=0 && pUI-> getPreviousPosition() < 64)
    {

        board->getPiece(pUI->getPreviousPosition())->getMoves(moves, *board);
        
        int des = pUI -> getSelectPosition();
        
        if(moves.find(des)!= moves.end())
        {
            cout << "I was here!!" << endl;
            board->move(pUI->getPreviousPosition(),des);
            pUI-> clearSelectPosition();
        }
        
    }
    
    // Draw the Board
    pUI->getPreviousPosition();
    board->display(pUI->getHoverPosition(), pUI->getSelectPosition());
    
    
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
    Board board;
   // set everything into action
//   ui.run(callBack, &demo);
    
    ui.run(callBack,&board);


   return 0;
}
