/*******************************************************************************************
* Programmers: Ben Kaufmann, Gage Unruh, Nolan Johnson  *
* Class: CptS 122, Spring, 2020; Lab Section X *
* Programming Assignment: PA9 *
* Date: May 3, 2020 *
*******************************************************************************************/

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