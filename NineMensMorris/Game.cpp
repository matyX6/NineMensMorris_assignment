#include "Game.h"
#include <iostream>

Game::Game()
{
	background.setSize(sf::Vector2f(600.0f, 600.0f));
}


Game::~Game()
{
}

void Game::setBackground(sf::Texture texture)
{
	//set background
	this->backgroundTexture = texture;
	background.setTexture(&backgroundTexture);
	std::cout << "Background set!\n";
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(background);
}
