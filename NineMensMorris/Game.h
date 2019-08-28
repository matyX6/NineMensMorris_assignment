#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"

class Game
{
private:
	Board board;
	std::vector<Button*> buttons;

	sf::RectangleShape background;

public:
	Game();
	~Game();
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setBackground(sf::Texture &texture);
};

