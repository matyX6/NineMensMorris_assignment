#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "button.h"

int main()
{
	const sf::Vector2i WINDOW_HEADER_OFFSET(8, 32);
	sf::RenderWindow window(sf::VideoMode(600, 600), "NineMensMorris", sf::Style::Close);
	Game game;
	{
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("./textures/background.png");
	game.setBackground(backgroundTexture);
	}

	Button button_reset(sf::Vector2f(20.0f, 520.0f), "RESET");
	Button button_quit(sf::Vector2f(460.0f, 520.0f), "QUIT");

	while (window.isOpen())
	{
		//events
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (button_reset.isJustPressed())
		{
			std::cout << "Restart game!\n";
		}

		//updates
		sf::Vector2i mousePosition = sf::Mouse::getPosition() - window.getPosition() - WINDOW_HEADER_OFFSET;
		button_reset.update(mousePosition);
		button_quit.update(mousePosition);


		//draw
		window.clear();
		game.draw(window);
		button_reset.draw(window);
		button_quit.draw(window);
		window.display();
	}

	return 0;
}