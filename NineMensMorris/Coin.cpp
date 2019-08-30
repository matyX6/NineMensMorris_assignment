#include "Coin.h"

#include "Point.h"

Coin::Coin(int playerIndex, int n, sf::Vector2f position)
{
	background.setSize(sf::Vector2f(30.0f, 30.0f));
	background.setOrigin(sf::Vector2f(15.0f, 15.0f));
	textureSelected.setSize(sf::Vector2f(60.0f, 60.0f));
	textureSelected.setOrigin(sf::Vector2f(30.0f, 30.0f));
	background.setTexture(&Resources::get().texture(TextureResourceType::COIN_WHITE_NORMAL));
	textureSelected.setTexture(&Resources::get().texture(TextureResourceType::COIN_SELECTED));
	soundRemoved.setBuffer(Resources::get().sound(SoundResourceType::COIN_REMOVED));

	this->n = n;
	setPlayerIndex(playerIndex);
	setPosition(position);
	homePosition = position;

	state = CoinState::UNPLACED;
	pressState = PressState2::DISABLED;
}

void Coin::update(sf::RenderWindow & window)
{
	justPressed = false;

	// get mouse state
	justMousePressed = false;
	justMouseReleased = false;
	if (lastMousePressed != isMousePressed()) 
	{
		if (lastMousePressed == false) { justMousePressed = true; }
		else { justMouseReleased = true; }
		lastMousePressed = isMousePressed();
	}

	// press states
	switch (pressState)
	{
	case PressState2::NORMAL:
		if (isMouseOver(window)) 
		{
			if (justMousePressed) 
			{
				pressState = PressState2::PRESSED;
				updateBackground();
			}
			else 
			{
				if (!isMousePressed()) 
				{
					pressState = PressState2::HOVER;
					updateBackground();
				}
			}
		}
		break;
	case PressState2::HOVER:
		if (justMousePressed) 
		{
			pressState = PressState2::PRESSED;
			updateBackground();
		}
		else 
		{
			if (!isMouseOver(window)) 
			{
				pressState = PressState2::NORMAL;
				updateBackground();
			}
		}
		break;
	case PressState2::PRESSED:
		if (!isMouseOver(window))
		{
			pressState = PressState2::NORMAL;
			updateBackground();
		}
		else 
		{
			if (justMouseReleased) 
			{
				pressState = PressState2::NORMAL;
				updateBackground();
				justPressed = true;
				selected = !selected;
			}
		}
		break;
	case PressState2::DISABLED:
		break;
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

sf::Vector2f Coin::getPosition()
{
	return position;
}

bool Coin::isJustPressed()
{
	return justPressed;
}

void Coin::updateBackground()
{
	if (playerIndex == 0)
	{
		switch (pressState)
		{
		case PressState2::NORMAL:
			setBackground(Resources::get().texture(TextureResourceType::COIN_WHITE_NORMAL));
			break;
		case PressState2::HOVER:
			setBackground(Resources::get().texture(TextureResourceType::COIN_WHITE_HOVER));
			break;
		case PressState2::PRESSED:
			setBackground(Resources::get().texture(TextureResourceType::COIN_WHITE_PRESSED));
			break;
		case PressState2::DISABLED:
			if (state == CoinState::UNPLACED) 
			{
				setBackground(Resources::get().texture(TextureResourceType::COIN_WHITE_NORMAL));
			}
			else {
				setBackground(Resources::get().texture(TextureResourceType::COIN_WHITE_DISABLED));
			}
			break;
		}
	}
	else {
		switch (pressState)
		{
		case PressState2::NORMAL:
			setBackground(Resources::get().texture(TextureResourceType::COIN_BLACK_NORMAL));
			break;
		case PressState2::HOVER:
			setBackground(Resources::get().texture(TextureResourceType::COIN_BLACK_HOVER));
			break;
		case PressState2::PRESSED:
			setBackground(Resources::get().texture(TextureResourceType::COIN_BLACK_PRESSED));
			break;
		case PressState2::DISABLED:
			if (state == CoinState::UNPLACED) 
			{
				setBackground(Resources::get().texture(TextureResourceType::COIN_BLACK_NORMAL));
			}
			else 
			{
				setBackground(Resources::get().texture(TextureResourceType::COIN_BLACK_DISABLED));
			}
			break;
		}
	}
}

void Coin::setBackground(sf::Texture & texture)
{
	background.setTexture(&texture);
}

void Coin::enable()
{
	pressState = PressState2::NORMAL;
	updateBackground();
}

void Coin::disable()
{
	pressState = PressState2::DISABLED;
	updateBackground();
}

bool Coin::isEnabled()
{
	return pressState != PressState2::DISABLED;
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
	state = CoinState::UNPLACED;
	updateBackground();
}

int Coin::getPlayerIndex()
{
	return playerIndex;
}

void Coin::remove()
{
	disable();
	deselect();
	setPosition(sf::Vector2f(-1000.0f, -1000.0f));
	setState(CoinState::REMOVED);
	linkedPoint->unlinkCoin();
	unlinkPoint();
	soundRemoved.play();
}

bool Coin::isRemoved()
{
	return (state == CoinState::REMOVED);
}

CoinState Coin::getState()
{
	return state;
}

void Coin::setState(CoinState state)
{
	this->state = state;
	updateBackground();
}

void Coin::linkPoint(Point * point)
{
	linkedPoint = point;
}

Point * Coin::getLinkedPoint()
{
	return linkedPoint;
}

void Coin::unlinkPoint()
{
	linkedPoint = nullptr;
}

bool Coin::hasLinkedPoint()
{
	return (linkedPoint != nullptr);
}

bool Coin::isMouseOver(sf::RenderWindow & window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	return background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat));
}

bool Coin::isMousePressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

void Coin::setPlayerIndex(int playerIndex)
{
	this->playerIndex = playerIndex;

	switch (playerIndex)
	{
	case 0: // white
		background.setTexture(&Resources::get().texture(TextureResourceType::COIN_WHITE_NORMAL));
		break;
	case 1: // black
		background.setTexture(&Resources::get().texture(TextureResourceType::COIN_BLACK_NORMAL));
		break;
	default:
		break;
	}
}
