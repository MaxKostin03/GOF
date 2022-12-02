
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include "FileLogger.h"

using namespace std;

extern FileLogger g_logger("log.txt");

//========================================================================================================================

int main(void)
{
   
    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    return 0;
}