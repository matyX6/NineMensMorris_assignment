#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"

enum class GameState
{
	PLACING,
	MOVING,
	REMOVING,
	GAMEOVER
};

class Game
{
private:
	Board board;
	std::vector<Button*> buttons;

	int numberOfPlayers = 2;
	int numberOfCoinsPerPlayer = 9;
	int currentPlayerIndex = -1;
	GameState state;
	sf::RectangleShape background;

public:
	Game();
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void reset();
	void setBackground(sf::Texture &texture);
	void advanceCurrentPlayerIndex();
};
