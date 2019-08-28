#include "Resources.h"
#include <iostream>


Resources & Resources::get()
{
	static Resources instance;
	return instance;
}

sf::SoundBuffer & Resources::sound(AudioResourceType type)
{
	switch (type)
	{
	case AudioResourceType::BUTTON_PRESSED:
			return soundButtonPressed;
	}
}

Resources::Resources()
{
	//load resources
	soundButtonPressed.loadFromFile("./audio/button-pressed.wav");
	std::cout << "Resources loaded!\n";
}
