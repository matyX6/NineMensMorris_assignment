#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

enum class TextureResourceType
{
	BACKGROUND,
	BOARD,
	BUTTON_NORMAL,
	BUTTON_PRESSED,
	BUTTON_HOVERED,
	POINT_NORMAL,
	POINT_HOVERED,
	POINT_PRESSED,
	POINT_DISABLED,
	COIN_WHITE_NORMAL,
	COIN_WHITE_HOVER,
	COIN_WHITE_PRESSED,
	COIN_WHITE_DISABLED,
	COIN_BLACK_NORMAL,
	COIN_BLACK_HOVER,
	COIN_BLACK_PRESSED,
	COIN_BLACK_DISABLED,
	COIN_SELECTED,
};

enum class SoundResourceType
{
	BUTTON_PRESSED,
	BUTTON_HOVER,
	COIN_REMOVED,
};

enum class FontResourceType
{
	MAIN,
};

class Resources
{
private:
	std::map<TextureResourceType, sf::Texture> textures;
	std::map<SoundResourceType, sf::SoundBuffer> sounds;
	std::map<FontResourceType, sf::Font> fonts;

	Resources();
	void loadAllResources();

public:
	static Resources& get();
	sf::SoundBuffer& sound(SoundResourceType type);
	sf::Texture& texture(TextureResourceType type);
	sf::Font& font(FontResourceType type);
};
