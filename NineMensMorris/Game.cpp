#include "Game.h"
#include "Button.h"
#include "Resources.h"
#include <iostream>

Game::Game()
	: board(sf::Vector2f(100.0f, 50.0f))
{
	numberOfPlayers = 2;
	numberOfCoins = 18;

	background.setSize(sf::Vector2f(600.0f, 600.0f));
	setBackground(Resources::get().texture(TextureResourceType::BACKGROUND));

	buttons.push_back(new Button(sf::Vector2f(20.0f, 520.0f), "RESTART"));
	buttons.push_back(new Button(sf::Vector2f(460.0f, 520.0f), "QUIT"));

	state = GameState::GAMEOVER;
	nextState = GameState::GAMEOVER;
}

Game::~Game()
{
	for (auto button : buttons) 
	{
		delete button;
	}
}

void Game::update(sf::RenderWindow &window)
{
	// states
	switch (state)
	{
	case GameState::PLACE:
		if (board.hasJustPlacedCoin()) 
		{
			// check lines
			// check count
			switch (currentPlayerIndex) 
			{
			case 0:
				numberOfWhiteCoins++;
			case 1:
				numberOfBlackCoins++;
			}
			currentNumberOfCoins++;

			if (!(currentNumberOfCoins < numberOfCoins)) 
			{
				board.disableAllPoints();
				advanceCurrentPlayerIndex();
				state = GameState::MOVE;
			}
			else 
			{
				advanceCurrentPlayerIndex();
				board.selectCoinFromStack(currentPlayerIndex, currentNumberOfCoins / 2);
			}
		}
		break;
	case GameState::MOVE:
		break;
	case GameState::REMOVE:
		break;
	case GameState::GAMEOVER:
		break;
	default:
		break;
	}

	// menu buttons
	for (auto button : buttons) 
	{
		// ignore if button not pressed
		if (!button->isJustPressed()) { continue; }

		// make decision based on button text
		std::string text = button->getText().toAnsiString();
		if (text == "RESTART") 
		{
			reset();
		}
		else if (text == "QUIT") 
		{
			window.close();
		}
	}

	board.update(window);
	for (auto button : buttons) {
		button->update(window);
	}
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(background);

	board.draw(window);
	for (auto button : buttons) 
	{
		button->draw(window);
	}
}

void Game::setBackground(sf::Texture &texture)
{
	background.setTexture(&texture);
}

void Game::reset()
{
	numberOfWhiteCoins = 0;
	numberOfBlackCoins = 0;
	currentNumberOfCoins = 0;

	// selecting random player
	currentPlayerIndex = rand() % numberOfPlayers;

	board.reset();
	board.selectCoinFromStack(currentPlayerIndex, currentNumberOfCoins / 2);

	state = GameState::PLACE;
}

void Game::increaseCurrentNumberOfCoins()
{
	currentNumberOfCoins++;
}

int Game::getNumberOfPlayerCoins(int playerIndex)
{
	switch (playerIndex)
	{
	case 0:
		return numberOfWhiteCoins;
		break;
	case 1:
		return numberOfBlackCoins;
		break;
	}
}

int Game::getCurrentNumberOfCoins()
{
	return currentNumberOfCoins;
}

void Game::advanceCurrentPlayerIndex()
{
	currentPlayerIndex++;
	if (currentPlayerIndex >= numberOfPlayers)
	{
		currentPlayerIndex = 0;
	}
}
