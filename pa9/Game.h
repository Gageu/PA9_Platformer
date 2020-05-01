#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

void Game::initVariables()
{
	this->Window = nullptr;
}

inline void Game::initWindow()
{
	this->Window = new sf::RenderWindow(sf::VideoMode(600, 600), "Game", sf::Style::Titlebar | sf::Style::Close);
}

inline Game::Game()
{
}

inline Game::~Game()
{
}

inline void Game::update()
{
}

inline void Game::render()
{
}
