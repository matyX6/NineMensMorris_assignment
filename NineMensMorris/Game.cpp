#include "Game.h"
#include <iostream>

Game::Game()
{
	background.setSize(sf::Vector2f(600.0f, 600.0f));
}

void Game::setBackground(sf::Texture texture)
{
	this->backgroundTexture = texture;
	background.setTexture(&backgroundTexture);
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(background);
}
