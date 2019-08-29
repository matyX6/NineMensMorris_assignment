#include "Coin.h"

Coin::Coin(int playerIndex, sf::Vector2f position)
{
	background.setSize(sf::Vector2f(30.0f, 30.0f));
	background.setOrigin(sf::Vector2f(15.0f, 15.0f));
	textureSelected.setSize(sf::Vector2f(60.f, 60.0f));
	textureSelected.setOrigin(sf::Vector2f(30.0f, 30.0f));
	background.setTexture(&Resources::get().texture(TextureResourceType::COIN_WHITE));
	textureSelected.setTexture(&Resources::get().texture(TextureResourceType::COIN_SELECTED));
	soundRemoved.setBuffer(Resources::get().sound(SoundResourceType::COIN_REMOVED));

	setPlayerIndex(playerIndex);
	setPosition(position);
	homePosition = position;
}

void Coin::update(sf::RenderWindow & window)
{
	// selected check
	if (!disabled) 
	{
		bool newSelectToggler = false;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		justPressed = false;
		sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
		if (background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat))) 
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
			{
				newSelectToggler = true;
			}
		}

		if (selectToggler != newSelectToggler)
		{
			selectToggler = newSelectToggler;
			if (selectToggler) 
			{
				selected = !selected;
				justPressed = true;
			}
		}
	}
}

void Coin::draw(sf::RenderWindow & window)
{
	window.draw(background);
	if (selected)
	{
		window.draw(textureSelected);
	}
}

void Coin::setPosition(sf::Vector2f position)
{
	this->position = position;
	background.setPosition(position);
	textureSelected.setPosition(position);
}

bool Coin::isJustPressed()
{
	return justPressed;
}

void Coin::setBackground(sf::Texture & texture)
{
	background.setTexture(&texture);
}

void Coin::enable()
{
	disabled = false;
}

void Coin::disable()
{
	disabled = true;
}

bool Coin::isEnabled()
{
	return !disabled;
}

void Coin::select()
{
	selected = true;
}

void Coin::deselect()
{
	selected = false;
}

bool Coin::isSelected()
{
	return selected;
}

void Coin::goHome()
{
	setPosition(homePosition);
}

void Coin::reset()
{
	goHome();
	disable();
	deselect();
	removed = false;
}

int Coin::getPlayerIndex()
{
	return playerIndex;
}

void Coin::remove()
{
	deselect();
	disable();
	setPosition(sf::Vector2f(-1000.0f, -1000.0f));
	removed = true;
	soundRemoved.play();
}

bool Coin::isRemoved()
{
	return removed;
}

void Coin::setPlayerIndex(int playerIndex)
{
	this->playerIndex = playerIndex;

	switch (playerIndex)
	{
	case 0: // white
		background.setTexture(&Resources::get().texture(TextureResourceType::COIN_WHITE));
		break;
	case 1: // black
		background.setTexture(&Resources::get().texture(TextureResourceType::COIN_BLACK));
		break;
	default:
		break;
	}
}

