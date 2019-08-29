#include "Resources.h"
#include "Game.h"
#include <iostream>
#include <string>


Game::Game()
	: board(sf::Vector2f(100.0f, 50.0f))
{
	background.setSize(sf::Vector2f(600.0f, 600.0f));
	setBackground(Resources::get().texture(TextureResourceType::BACKGROUND));

	buttons.push_back(new Button(sf::Vector2f(20.0f, 520.0f), "RESTART"));
	buttons.push_back(new Button(sf::Vector2f(460.0f, 520.0f), "QUIT"));

	state = GameState::GAMEOVER;
}

void Game::update(sf::RenderWindow &window)
{
	// states
	switch (state)
	{
		// -------------------------------------------------------------------------------------------------
	case GameState::PLACING:
		if (board.hasJustSelectedPoint()) {
			// place coin
			board.placeSelectedCoin(board.getJustSelectedPoint());

			// check if new line has formed
			if (board.hasLineWithPlayerIndex(currentPlayerIndex)) {
				// change to REMOVE state
				board.disableAllPoints();
				board.enablePlayerCoins(1 - currentPlayerIndex);
				board.disableLinesWithPlayerIndex(currentPlayerIndex);
				state = GameState::REMOVING;
				return;
			}

			// check count
			if (board.hasUnplacedCoin()) {
				// keep state
				advanceCurrentPlayerIndex();
				board.selectUnplacedCoin(currentPlayerIndex);
			}
			else {
				// all done, proceed to MOVING state
				board.disableAllPoints();
				advanceCurrentPlayerIndex();
				board.enablePlayerCoins(currentPlayerIndex);
				board.setSelectedCoin(nullptr);
				state = GameState::MOVING;
			}
		}
		break;
		// -------------------------------------------------------------------------------------------------
	case GameState::MOVING:
		if (board.hasJustSelectedCoin()) {
			if (board.hasSelectedCoin()) {
				// undo move intention
				board.getSelectedCoin()->deselect();
				board.setSelectedCoin(nullptr);
				board.disableAllPoints();
				board.enablePlayerCoins(currentPlayerIndex);
			}
			else {
				// select new coin
				board.disableAllCoins();
				board.getJustSelectedCoin()->enable(); // allow for undo
				board.setSelectedCoin(board.getJustSelectedCoin());
				board.getJustSelectedCoin()->select();

				//enable neighbouring points
				board.getJustSelectedCoin()->getLinkedPoint()->enableFreeConnectedPoints();
			}
		}

		else if (board.hasJustSelectedPoint()) 
		{
			if (board.hasSelectedCoin()) 
			{ // just in case
				board.getSelectedCoin()->deselect();
				board.moveSelectedCoinToPoint(board.getJustSelectedPoint());
				board.disableAllPoints();
				board.disableAllCoins();
				board.refreshLines();

				// check lines
				if (board.hasLineWithPlayerIndex(currentPlayerIndex)) 
				{
					// change to REMOVE state
					board.disableAllPoints();
					board.enablePlayerCoins(1 - currentPlayerIndex);
					board.disableLinesWithPlayerIndex(currentPlayerIndex);
					state = GameState::REMOVING;
					return;
				}

				advanceCurrentPlayerIndex();
				board.enablePlayerCoins(currentPlayerIndex);
			}
		}

		break;
		// -------------------------------------------------------------------------------------------------
	case GameState::REMOVING:
		if (board.hasJustSelectedCoin()) 
		{
			board.getJustSelectedCoin()->remove();
			advanceCurrentPlayerIndex();

			// check if still has to place stuff
			if (board.hasUnplacedCoin()) 
			{
				board.disableAllCoins();
				board.unlinkDisabledCoins();
				board.enableRemainingPoints();
				board.refreshLines();
				board.selectUnplacedCoin(currentPlayerIndex);
				state = GameState::PLACING;
			}
			else 
			{
				board.disableAllCoins();
				board.unlinkDisabledCoins();
				board.enablePlayerCoins(currentPlayerIndex);
				board.refreshLines();
				state = GameState::MOVING;
			}
		}
		break;
		// -------------------------------------------------------------------------------------------------
	case GameState::GAMEOVER:
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
	for (auto button : buttons) 
	{
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
	board.reset();

	// selecting random player
	currentPlayerIndex = rand() % numberOfPlayers;

	board.selectUnplacedCoin(currentPlayerIndex);
	state = GameState::PLACING;
}

void Game::advanceCurrentPlayerIndex()
{
	currentPlayerIndex++;
	if (currentPlayerIndex >= numberOfPlayers)
	{
		currentPlayerIndex = 0;
	}
}
