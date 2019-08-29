#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

enum class AudioResourceType
{
	BUTTON_PRESSED,
	BUTTON_HOVER,
	COIN_REMOVED
};

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
	COIN_WHITE,
	COIN_BLACK,
	COIN_SELECTED
};

enum class FontResourceType
{
	MAIN
};
class Resources
{
private:
	sf::SoundBuffer soundButtonPressed;
	sf::SoundBuffer soundButtonHover;
	sf::SoundBuffer soundCoinDisabled;

	sf::Texture textureBackground;
	sf::Texture textureBoard;
	sf::Texture textureButtonNormal;
	sf::Texture textureButtonHover;
	sf::Texture textureButtonPressed;
	sf::Texture texturePointNormal;
	sf::Texture texturePointHover;
	sf::Texture texturePointPressed;
	sf::Texture textureCoinWhite;
	sf::Texture textureCoinBlack;
	sf::Texture textureCoinSelected;

	sf::Font fontMain;

	Resources();

public:
	static Resources& get();
	sf::SoundBuffer& sound(AudioResourceType type);
	sf::Texture &texture(TextureResourceType type);
	sf::Font &font(FontResourceType type);
};

