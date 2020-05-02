#pragma once
#include "Game.h"

void Game::initVariables()
{
	window = nullptr;
}

inline void Game::initWindow()
{
	this->video_mode.height = 600;
	this->video_mode.width = 800;
	window = new sf::RenderWindow(video_mode, "Game", sf::Style::Titlebar | sf::Style::Close);
}

inline Game::Game()
{
	initVariables();
	initWindow();
}

inline Game::~Game()
{
	delete window;
}

bool Game::isRunning()
{
	return window->isOpen();
}

inline void Game::update()
{
	/*event poling*/
	while(window->pollEvent(ev))
	{
		switch(ev.type)
		{
		//window close event
		case sf::Event::Closed:
			window->close();
			break;
	
			/*inputs go here*/
		}
	}
}

inline void Game::render()
{
}
