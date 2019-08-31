#pragma once
#include <SFML/Graphics.hpp>
#include "MenuButton.h"
#include "Board.h"
#include "Text.h"

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
	const int numberOfCoinsPerPlayer = 9;

	Board board;
	std::vector<MenuButton*> buttons;
	Text textPlayer;
	Text textStatus;

	const int numberOfPlayers = 2;
	int currentPlayerIndex = -1;
	GameState state;
	sf::RectangleShape background;

public:
	Game();
	void update(sf::RenderWindow &window, int delta);
	void draw(sf::RenderWindow &window);

	void reset();
	void setBackground(sf::Texture &texture);
	void advanceCurrentPlayerIndex();
	void updatePlayerText();
};
