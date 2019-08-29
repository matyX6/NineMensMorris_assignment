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
	BUTTON_HOVER,
	POINT_NORMAL,
	POINT_HOVER,
	POINT_PRESSED,
	POINT_DISABLED,
	COIN_WHITE,
	COIN_BLACK,
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
