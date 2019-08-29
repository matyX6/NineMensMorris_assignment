#include "Button.h"

Button::Button(){}

Button::~Button()
{
	std::cout << "Button " << text.getString().toAnsiString() << " destroyed!\n";
}

Button::Button(sf::Vector2f position, sf::String text)
{
	background.setSize(sf::Vector2f(120.0f, 60.0f));
	soundPressed.setBuffer(Resources::get().sound(SoundResourceType::BUTTON_PRESSED));
	this->text.setFont(Resources::get().font(FontResourceType::MAIN));
	justPressed = false;
	setState(ButtonState::NORMAL);
	setText(text);
	setPosition(position);
}

void Button::update(sf::RenderWindow &window)
{
	// hover & press states
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	justPressed = false;
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	ButtonState newState = ButtonState::NORMAL;
	if (background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat))) 
	{
		newState = ButtonState::HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
		{
			newState = ButtonState::PRESSED;
		}
	}
	if (state != newState) 
	{
		setState(newState);
	}
}

void Button::draw(sf::RenderWindow &window)
{
	window.draw(background);
	window.draw(text);
}

bool Button::isJustPressed()
{
	return justPressed;
}

void Button::setBackground(sf::Texture &texture)
{
	background.setTexture(&texture);
}

sf::Vector2f Button::getPosition()
{
	return position;
}

void Button::setPosition(sf::Vector2f position)
{
	this->position = position;

	background.setPosition(position);
	centerText();
}

void Button::setText(sf::String string)
{
	text.setString(string);
	text.setCharacterSize(16.0f);
	centerText();
}

sf::String Button::getText()
{
	return text.getString();
}

void Button::setState(ButtonState state) 
{
	this->state = state;

	switch (state)
	{
	case ButtonState::NORMAL:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_NORMAL));
		break;
	case ButtonState::HOVER:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_HOVER));
		break;
	case ButtonState::PRESSED:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_PRESSED));
		justPressed = true;
		soundPressed.play();
		break;
	default:
		break;
	}
}

void Button::centerText() 
{
	sf::Vector2f textureHalfSize(background.getGlobalBounds().width * 0.5f,
		background.getGlobalBounds().height * 0.5f);
	sf::Vector2f textHalfSize(text.getGlobalBounds().width * 0.5f,
		text.getGlobalBounds().height * 0.5f);
	sf::Vector2f offsetFix(0.0f, text.getLocalBounds().top);
	text.setPosition(position + textureHalfSize - textHalfSize - offsetFix);
}
