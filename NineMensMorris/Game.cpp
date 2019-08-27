#include "Game.h"
#include "Button.h"
#include <iostream>

Game::Game()
	:button_reset(sf::Vector2f(20.0f, 520.0f), "RESTART"),
     button_quit(sf::Vector2f(460.0f, 520.0f), "QUIT")
{
	background.setSize(sf::Vector2f(600.0f, 600.0f));
}

void Game::setBackground(sf::Texture texture)
{
	this->backgroundTexture = texture;
	background.setTexture(&backgroundTexture);
}

void Game::update(sf::RenderWindow &window)
{
	button_reset.update(window);
	button_quit.update(window);

	if (button_reset.isJustPressed())
	{
		std::cout << "Reset pressed!\n";
	}
	if (button_quit.isJustPressed())
	{
		window.close();
	}
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(background);

	button_reset.draw(window);
	button_quit.draw(window);
}
