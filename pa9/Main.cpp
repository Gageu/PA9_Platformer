#include "Game.h"

int main()
{
    BoidGame game = BoidGame(4);
    while (game.isRunning())
    {
       game.update();
       game.render();
    }

    return 0;
}