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

	// load texture resources
	textureBackground.loadFromFile("./textures/background.png");
	textureBoard.loadFromFile("./textures/board.png");
	textureButtonNormal.loadFromFile("./textures/button-normal.png");
	textureButtonHover.loadFromFile("./textures/button-hover.png");
	textureButtonPressed.loadFromFile("./textures/button-pressed.png");

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
