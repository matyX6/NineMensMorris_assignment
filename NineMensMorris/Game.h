#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Game
{
public:
	Game();
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setBackground(sf::Texture texture);

private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	Button button_reset;
	Button button_quit;
};

