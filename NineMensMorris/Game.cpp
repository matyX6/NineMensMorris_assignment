#include "Game.h"
#include "Button.h"
#include "Resources.h"
#include <iostream>

Game::Game()
	: board(sf::Vector2f(100.0f, 50.0f))
{
	background.setSize(sf::Vector2f(600.0f, 600.0f));
	setBackground(Resources::get().texture(TextureResourceType::BACKGROUND));

	buttons.push_back(new Button(sf::Vector2f(20.0f, 520.0f), "RESTART"));
	buttons.push_back(new Button(sf::Vector2f(460.0f, 520.0f), "QUIT"));
}

Game::~Game()
{
	for (auto button : buttons) {
		delete button;
	}
}

void Game::update(sf::RenderWindow &window)
{
	board.update(window);
	for (auto button : buttons) {
		button->update(window);
	}

	// check button presses
	for (auto button : buttons) {
		// ignore if button not pressed
		if (!button->isJustPressed()) { continue; }

		// make decision based on button text
		std::string text = button->getText().toAnsiString();
		if (text == "RESTART") {
			std::cout << "Restart Game!\n";
		}
		else if (text == "QUIT") {
			std::cout << "Quit game!\n";
			window.close();
		}
	}
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(background);

	board.draw(window);
	for (auto button : buttons) {
		button->draw(window);
	}
}

void Game::setBackground(sf::Texture &texture)
{
	background.setTexture(&texture);
}
