#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void draw(sf::RenderWindow &window);
	void setBackground(sf::Texture texture);

private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
};

