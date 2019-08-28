#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"

enum class GameState
{
	PLACE,
	MOVE,
	REMOVE,
	GAMEOVER
};

class Game
{
private:
	Board board;
	std::vector<Button*> buttons;

	int numberOfPlayers;
	int currentPlayerIndex;
	int numberOfCoins;
	int currentNumberOfCoins;
	int numberOfWhiteCoins;
	int numberOfBlackCoins;
	GameState state;
	GameState nextState;
	sf::RectangleShape background;

public:
	Game();
	~Game();
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setBackground(sf::Texture &texture);
	void reset();
	void increaseCurrentNumberOfCoins();
	int getNumberOfPlayerCoins(int playerIndex);
	int getCurrentNumberOfCoins();
	void advanceCurrentPlayerIndex();
};

