#include "Resources.h"
#include <iostream>

Resources & Resources::get()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
{
	loadAllResources();
}

void Resources::loadAllResources()
{
	textures[TextureResourceType::BACKGROUND].loadFromFile("./textures/background.png");
	textures[TextureResourceType::BOARD].loadFromFile("./textures/board.png");
	textures[TextureResourceType::BUTTON_NORMAL].loadFromFile("./textures/button-normal.png");
	textures[TextureResourceType::BUTTON_HOVERED].loadFromFile("./textures/button-hover.png");
	textures[TextureResourceType::BUTTON_PRESSED].loadFromFile("./textures/button-pressed.png");
	textures[TextureResourceType::POINT_NORMAL].loadFromFile("./textures/point-normal.png");
	textures[TextureResourceType::POINT_HOVERED].loadFromFile("./textures/point-hover.png");
	textures[TextureResourceType::POINT_PRESSED].loadFromFile("./textures/point-pressed.png");
	textures[TextureResourceType::POINT_DISABLED].loadFromFile("./textures/point-pressed.png");
	textures[TextureResourceType::COIN_WHITE_NORMAL].loadFromFile("./textures/coin1.png");
	textures[TextureResourceType::COIN_WHITE_HOVER].loadFromFile("./textures/coin1-hover.png");
	textures[TextureResourceType::COIN_WHITE_PRESSED].loadFromFile("./textures/coin1-disabled.png");
	textures[TextureResourceType::COIN_WHITE_DISABLED].loadFromFile("./textures/coin1-disabled.png");
	textures[TextureResourceType::COIN_BLACK_NORMAL].loadFromFile("./textures/coin2.png");
	textures[TextureResourceType::COIN_BLACK_HOVER].loadFromFile("./textures/coin2-hover.png");
	textures[TextureResourceType::COIN_BLACK_PRESSED].loadFromFile("./textures/coin2-disabled.png");
	textures[TextureResourceType::COIN_BLACK_DISABLED].loadFromFile("./textures/coin2-disabled.png");
	textures[TextureResourceType::COIN_SELECTED].loadFromFile("./textures/coin-selected.png");

	sounds[SoundResourceType::BUTTON_PRESSED].loadFromFile("./audio/button-pressed.wav");
	sounds[SoundResourceType::COIN_REMOVED].loadFromFile("./audio/coin-removed.wav");

	fonts[FontResourceType::MAIN].loadFromFile("./fonts/Splatch.ttf");

	std::cout << "Resources loaded!\n";
}

sf::Texture & Resources::texture(TextureResourceType type)
{
	if (textures.count(type) == 0) { std::cout << "Key for texture [" << static_cast<int>(type) << "] not defined.\n"; }
	return textures[type];
}

sf::SoundBuffer & Resources::sound(SoundResourceType type)
{
	if (sounds.count(type) == 0) { std::cout << "Key for sound [" << static_cast<int>(type) << "] not defined.\n"; }
	return sounds[type];
}

sf::Font & Resources::font(FontResourceType type)
{
	if (fonts.count(type) == 0) { std::cout << "Key for font [" << static_cast<int>(type) << "] not defined.\n"; }
	return fonts[type];
}
