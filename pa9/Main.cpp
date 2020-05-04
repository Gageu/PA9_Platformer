#include "Game.h"

int main()
{
    BoidGame game;
    while (game.isRunning())
    {
        game.update();
        game.render();
    }

    return 0;
}