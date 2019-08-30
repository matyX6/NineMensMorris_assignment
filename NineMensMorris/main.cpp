#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "Resources.h"
#include <time.h>

void instanceSingletons()
{
	Resources::get();
}

int main()
{
	instanceSingletons();
	srand(static_cast<unsigned int>(time(NULL)));

	sf::RenderWindow window(sf::VideoMode(600, 600), "NineMensMorris", sf::Style::Close);

	Game game;

	sf::Event evnt;

	while (window.isOpen())
	{
		//events
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//updates
		game.update(window);


		//draw
		window.clear();
		game.draw(window);
		window.display();
	}

	return 0;
}

