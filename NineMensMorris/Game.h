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
	const int minNumberOfCoins = 3;

	Board board;
	std::vector<MenuButton*> buttons;
	Text textPlayer;
	Text textStatus;
	Text textPlayer1Score;
	Text textPlayer2Score;
	Text textPlayer1Label;
	Text textPlayer2Label;

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
	void updatePlayerScore(int playerIndex, int score);
};
