#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"

class Button
{	
	public:
		Button();
		~Button();

		sf::RectangleShape getRect();
		

	private:
		sf::RectangleShape button;
		sf::Sprite idleSprite;
		sf::Sprite hoverSprite;

};

#endif // !1
