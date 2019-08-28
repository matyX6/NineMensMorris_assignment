#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

enum class AudioResourceType
{
	BUTTON_PRESSED,
	BUTTON_HOVER

};
class Resources
{
private:
	sf::SoundBuffer soundButtonPressed;
	sf::SoundBuffer soundButtonHover;
	Resources();

public:
	static Resources& get();
	sf::SoundBuffer& sound(AudioResourceType type);
};

