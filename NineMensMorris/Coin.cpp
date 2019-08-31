#include "Coin.h"

#include "Point.h"

Coin::Coin(int playerIndex, int n, sf::Vector2f position)
{
	textureNormal = &Resources::get().texture(TextureResourceType::COIN_WHITE_NORMAL);
	textureHovered = &Resources::get().texture(TextureResourceType::COIN_WHITE_HOVERED);
	texturePressed = &Resources::get().texture(TextureResourceType::COIN_WHITE_PRESSED);
	textureDisabled = &Resources::get().texture(TextureResourceType::COIN_WHITE_DISABLED);
	textureNormal2 = &Resources::get().texture(TextureResourceType::COIN_BLACK_NORMAL);
	textureHovered2 = &Resources::get().texture(TextureResourceType::COIN_BLACK_HOVERED);
	texturePressed2 = &Resources::get().texture(TextureResourceType::COIN_BLACK_PRESSED);
	textureDisabled2 = &Resources::get().texture(TextureResourceType::COIN_BLACK_DISABLED);

	rectSelected.setTexture(&Resources::get().texture(TextureResourceType::COIN_SELECTED));
	soundRemoved.setBuffer(Resources::get().sound(SoundResourceType::COIN_REMOVED));

	setSize(sf::Vector2f(30.0f, 30.0f));
	setCentered(true);

	rectSelected.setSize(sf::Vector2f(60.0f, 60.0f));
	rectSelected.setOrigin(sf::Vector2f(30.0f, 30.0f));

	this->n = n;
	setPlayerIndex(playerIndex);
	setPosition(position);
	homePosition = position;

	setCoinState(CoinState::UNPLACED);
	setPressState(PressState::DISABLED);
}

void Coin::update(sf::RenderWindow & window, int delta)
{
	Button::update(window, delta);

	if (justPressed) 
	{
		selected = !selected;
	}

	//smooth movement
	float lerpWeight = 0.02f;
	sf::Vector2f distance = targetPosition - position;
	setPositionSmooth(getPosition() + distance * lerpWeight);
}

void Coin::draw(sf::RenderWindow & window)
{
	Button::draw(window);

	if (selected) 
	{
		window.draw(rectSelected);
	}
}

void Coin::setPosition(sf::Vector2f position)
{
	Button::setPosition(position);
	rectSelected.setPosition(position);
	targetPosition = position;
}

void Coin::setPositionSmooth(sf::Vector2f position)
{
	Button::setPosition(position);
	rectSelected.setPosition(position);
}

void Coin::moveTo(sf::Vector2f position, bool smooth)
{
	if (smooth)
	{
		targetPosition = position;
	}
	else
	{
		setPosition(position);
	}
}

void Coin::updateBackground()
{
	if (playerIndex == 0) 
	{
		switch (pressState)
		{
		case PressState::NORMAL:
			setTexture(*textureNormal);
			break;
		case PressState::HOVERED:
			setTexture(*textureHovered);
			break;
		case PressState::PRESSED:
			setTexture(*texturePressed);
			break;
		case PressState::DISABLED:
			if (coinState == CoinState::UNPLACED) 
			{
				setTexture(*textureNormal);
			}
			else 
			{
				setTexture(*textureDisabled);
			}
			break;
		}
	}
	else 
	{
		switch (pressState)
		{
		case PressState::NORMAL:
			setTexture(*textureNormal2);
			break;
		case PressState::HOVERED:
			setTexture(*textureHovered2);
			break;
		case PressState::PRESSED:
			setTexture(*texturePressed2);
			break;
		case PressState::DISABLED:
			if (coinState == CoinState::UNPLACED) 
			{
				setTexture(*textureNormal2);
			}
			else 
			{
				setTexture(*textureDisabled2);
			}
			break;
		}
	}
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

void Coin::reset()
{
	moveTo(homePosition);
	disable();
	deselect();
	setCoinState(CoinState::UNPLACED);
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
	//setPosition(sf::Vector2f(-1000.0f, -1000.0f));
	moveTo(sf::Vector2f(-1000.0f, -1000.0f));
	setCoinState(CoinState::REMOVED);
	linkedPoint->unlinkCoin();
	unlinkPoint();
	soundRemoved.play();
}

bool Coin::isRemoved()
{
	return (coinState == CoinState::REMOVED);
}

CoinState Coin::getCoinState()
{
	return coinState;
}

void Coin::setCoinState(CoinState state)
{
	coinState = state;
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

void Coin::setPlayerIndex(int playerIndex)
{
	this->playerIndex = playerIndex;

	switch (playerIndex)
	{
	case 0: // white
		setTexture(*textureNormal);
		break;
	case 1: // black
		setTexture(*textureNormal2);
		break;
	default:
		break;
	}
}
