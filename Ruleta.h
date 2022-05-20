#pragma once

#ifndef RULETA_H
#define RULETA_H

#include "SFML/Graphics.hpp"

class Ruleta
{
	public:
		Ruleta();
		~Ruleta();

	public:
		void              initWindow();
		void              initTexture();
		void              initFont();
		void              run();
		void              processEvents();
		void              render();

	private:
		sf::RenderWindow			window;
		sf::Texture					ruletaTexture, bgTexture, btnSpaceTxt;
		sf::Sprite					ruletaSprite, bgSprite, btnSpaceSprt;
		sf::Font					font;
		sf::Text					text;
	
};

#endif // !RULETA_H
