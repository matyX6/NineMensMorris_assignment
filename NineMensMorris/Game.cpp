#include "Resources.h"
#include "Game.h"
#include <iostream>
#include <string>


Game::Game(): 
	board(sf::Vector2f(100.0f, 50.0f))
{
	background.setSize(sf::Vector2f(600.0f, 600.0f));
	setBackground(Resources::get().texture(TextureResourceType::BACKGROUND));

	// creating menu buttons
	buttons.push_back(new MenuButton(sf::Vector2f(20.0f, 520.0f), "RESTART"));
	buttons.push_back(new MenuButton(sf::Vector2f(460.0f, 520.0f), "QUIT"));

	state = GameState::GAMEOVER;

	textPlayer.setPosition(sf::Vector2f(300.0f, 530.0f));
	textPlayer.setText("");
	textStatus.setPosition(sf::Vector2f(300.0f, 570.0f));
	textStatus.setText("");
}

void Game::update(sf::RenderWindow &window)
{
	// states
	switch (state)
	{
		// -------------------------------------------------------------------------------------------------
	case GameState::PLACING:
		if (board.hasJustSelectedPoint()) 
		{
			// place coin
			board.placeSelectedCoin(board.getJustSelectedPoint());

			// check if new line has formed
			if (board.hasLineWithPlayerIndex(currentPlayerIndex)) 
			{
				// change to REMOVE state
				board.selectPlayerLineCoins(currentPlayerIndex);
				board.disableAllPoints();
				board.enablePlayerPlacedCoins(1 - currentPlayerIndex);
				board.disableLinesWithPlayerIndex(currentPlayerIndex);
				textStatus.setText("REMOVE ENEMY COIN");
				state = GameState::REMOVING;
				return;
			}

			// check count
			if (board.hasUnplacedCoin()) 
			{
				// keep state
				advanceCurrentPlayerIndex();
				board.selectUnplacedCoin(currentPlayerIndex);
				updatePlayerText();
				textStatus.setText("PLACE YOUR COIN");
			}
			else 
			{
				// all done, proceed to MOVING state
				board.disableAllPoints();
				advanceCurrentPlayerIndex();
				board.enablePlayerPlacedCoins(currentPlayerIndex);
				board.setSelectedCoin(nullptr);
				updatePlayerText();
				textStatus.setText("SELECT AND MOVE COIN");
				state = GameState::MOVING;
			}
		}
		break;
		// -------------------------------------------------------------------------------------------------
	case GameState::MOVING:
		if (board.hasJustSelectedCoin()) 
		{
			if (board.hasSelectedCoin()) 
			{
				// undo move intention
				board.getSelectedCoin()->deselect();
				board.setSelectedCoin(nullptr);
				board.disableAllPoints();
				board.enablePlayerPlacedCoins(currentPlayerIndex);
				updatePlayerText();
				textStatus.setText("SELECT AND MOVE COIN");
			}
			else 
			{
				// select new coin
				board.disableAllCoins();
				board.getJustSelectedCoin()->enable(); // allow for undo
				board.setSelectedCoin(board.getJustSelectedCoin());
				board.getJustSelectedCoin()->select();

				//enable neighbouring points
				board.getJustSelectedCoin()->getLinkedPoint()->enableFreeConnectedPoints();
				updatePlayerText();
				textStatus.setText("MOVE YOUR COIN");
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
					board.selectPlayerLineCoins(currentPlayerIndex);
					board.disableAllPoints();
					board.enablePlayerPlacedCoins(1 - currentPlayerIndex);
					board.disableLinesWithPlayerIndex(currentPlayerIndex);
					textStatus.setText("REMOVE ENEMY COIN");
					state = GameState::REMOVING;
					return;
				}

				advanceCurrentPlayerIndex();
				board.enablePlayerPlacedCoins(currentPlayerIndex);

				updatePlayerText();
				textStatus.setText("SELECT AND MOVE COIN");
			}
		}

		break;
		// -------------------------------------------------------------------------------------------------
	case GameState::REMOVING:
		if (board.hasJustSelectedCoin()) 
		{
			//removing enemy coin
			board.getJustSelectedCoin()->remove();
			board.deselectAllCoins();

			//checking for game over
			std::cout << "Enemy coins left: " << board.getNumberOfPlayerUnremovedCoins(1 - currentPlayerIndex) << "\n";
			if (board.getNumberOfPlayerUnremovedCoins(1 - currentPlayerIndex) < 3)
			{
				board.disableAllCoins();
				updatePlayerText();
				textStatus.setText("YOU WIN");
				state = GameState::GAMEOVER;
				return;
			}

			advanceCurrentPlayerIndex();
			updatePlayerText();

			// check if we are still placing coins
			if (board.hasUnplacedCoin()) 
			{
				//we are placing coins, go to placing state
				board.disableAllCoins();
				board.unlinkDisabledCoins();
				board.enableRemainingPoints();
				board.refreshLines();
				board.selectUnplacedCoin(currentPlayerIndex);
				textStatus.setText("PLACE YOUR COIN");
				state = GameState::PLACING;
			}
			else 
			{
				//we are not placing coins, go to moving state
				board.disableAllCoins();
				board.unlinkDisabledCoins();
				board.enablePlayerPlacedCoins(currentPlayerIndex);
				board.refreshLines();
				textStatus.setText("SELECT AND MOVE COIN");
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

	//update children
	board.update(window);
	for (auto button : buttons) 
	{
		button->update(window);
	}
	textPlayer.update(window);
	textStatus.update(window);
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(background);

	//draw children
	board.draw(window);
	for (auto button : buttons) 
	{
		button->draw(window);
	}
	textPlayer.draw(window);
	textStatus.draw(window);
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
	updatePlayerText();
	textStatus.setText("PLACE YOUR COIN");
}

void Game::advanceCurrentPlayerIndex()
{
	currentPlayerIndex++;
	if (currentPlayerIndex >= numberOfPlayers)
	{
		currentPlayerIndex = 0;
	}
}

void Game::updatePlayerText()
{
	switch (currentPlayerIndex)
	{
	case 0: textPlayer.setText("PLAYER 1"); break;
	case 1: textPlayer.setText("PLAYER 2"); break;

	}
}
