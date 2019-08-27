#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "NineMensMorris", sf::Style::Close);
	Game game;

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("./textures/background.png");
	game.setBackground(backgroundTexture);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		game.draw(window);
		window.display();
	}

	return 0;
}