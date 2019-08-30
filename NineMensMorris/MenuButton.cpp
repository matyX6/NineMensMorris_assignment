#include "MenuButton.h"

MenuButton::MenuButton()
{
	textureNormal = &Resources::get().texture(TextureResourceType::BUTTON_NORMAL);
	textureHovered = &Resources::get().texture(TextureResourceType::BUTTON_HOVERED);
	texturePressed = &Resources::get().texture(TextureResourceType::BUTTON_PRESSED);

	setSize(sf::Vector2f(120.0f, 60.0f));
	text.setFont(Resources::get().font(FontResourceType::MAIN));
	text.setCharacterSize(16);

	setPressState(PressState::NORMAL);
}

void MenuButton::draw(sf::RenderWindow &window)
{
	Button::draw(window);
	window.draw(text);
}

void MenuButton::setText(sf::String string)
{
	text.setString(string);
	centerText();
}

sf::String MenuButton::getText()
{
	return text.getString();
}

void MenuButton::centerText() {
	sf::Vector2f textureHalfSize(rect.getGlobalBounds().width * 0.5f,
		rect.getGlobalBounds().height * 0.5f);
	sf::Vector2f textHalfSize(text.getGlobalBounds().width * 0.5f,
		text.getGlobalBounds().height * 0.5f);
	sf::Vector2f offsetFix(0.0f, text.getLocalBounds().top);
	text.setPosition(position + textureHalfSize - textHalfSize - offsetFix);
}
