#include "Button.h"
#include "SFML/Graphics.hpp"

Button::Button()
{
}

Button::~Button()
{
}

sf::RectangleShape Button::getRect()
{
	return button;
}

