#include "Resources.h"
#include <iostream>

Resources & Resources::get()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
{
	// load audio resources
	soundButtonPressed.loadFromFile("./audio/button-pressed.wav");
	soundCoinDisabled.loadFromFile("./audio/coin-removed.wav");

	// load texture resources
	textureBackground.loadFromFile("./textures/background.png");
	textureBoard.loadFromFile("./textures/board.png");
	textureButtonNormal.loadFromFile("./textures/button-normal.png");
	textureButtonHover.loadFromFile("./textures/button-hover.png");
	textureButtonPressed.loadFromFile("./textures/button-pressed.png");
	texturePointNormal.loadFromFile("./textures/point-normal.png");
	texturePointHover.loadFromFile("./textures/point-hover.png");
	texturePointPressed.loadFromFile("./textures/point-pressed.png");
	textureCoinWhite.loadFromFile("./textures/coin1.png");
	textureCoinBlack.loadFromFile("./textures/coin2.png");
	textureCoinSelected.loadFromFile("./textures/coin-selected.png");


	// load font resources
	fontMain.loadFromFile("./fonts/Splatch.ttf");

	std::cout << "Resources loaded!\n";
}

sf::SoundBuffer & Resources::sound(AudioResourceType type)
{
	switch (type)
	{
	case AudioResourceType::BUTTON_PRESSED:
		return soundButtonPressed;
	case AudioResourceType::COIN_REMOVED:
		return soundCoinDisabled;
	}
}

sf::Texture & Resources::texture(TextureResourceType type)
{
	switch (type)
	{
	case TextureResourceType::BACKGROUND:
		return textureBackground;
	case TextureResourceType::BOARD:
		return textureBoard;
	case TextureResourceType::BUTTON_NORMAL:
		return textureButtonNormal;
	case TextureResourceType::BUTTON_PRESSED:
		return textureButtonPressed;
	case TextureResourceType::BUTTON_HOVER:
		return textureButtonHover;
	case TextureResourceType::POINT_NORMAL:
		return texturePointNormal;
	case TextureResourceType::POINT_HOVER:
		return texturePointHover;
	case TextureResourceType::POINT_PRESSED:
		return texturePointPressed;
	case TextureResourceType::COIN_WHITE:
		return textureCoinWhite;
	case TextureResourceType::COIN_BLACK:
		return textureCoinBlack;
	case TextureResourceType::COIN_SELECTED:
		return textureCoinSelected;

	}
}

sf::Font & Resources::font(FontResourceType type)
{
	switch (type)
	{
	case FontResourceType::MAIN:
		return fontMain;
	}
}
