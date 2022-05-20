#pragma once

#ifndef RULETA_H
#define RULETA_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "stdio.h"
#include "windows.h"
#include "iostream"

using std::cerr;
using std::endl;

class Ruleta
{
	public:
		Ruleta();
		~Ruleta();

	public:
		//Window functions
		void              initWindow();
		void              run();
		void              processEvents();
		void              update();
		void              render();

		//Texturas y font
		void              initTexture();
		void              initFont();

		//Evento para cuando se toque el espacio
		void              onSpacePressed(sf::Event& event);
		void              onSpaceReleased(sf::Event &event);

		//animacion de la ruleta
		void              updateRoulette();
		void              resetClock();
		void              spinRoulette();
		

	private:
		sf::RenderWindow			window;
		sf::Texture					ruletaTexture, bgTexture, btnSpaceTxt;
		sf::Sprite					ruletaSprite, bgSprite, btnSpaceSprt;
		sf::Font					font;
		sf::Text					text;

		//Variables para la animacion de la ruleta
		sf::IntRect                 rectSourceSprite;
		sf::Clock                   timer, clock;
		Animation                   animation;
		float                       deltaTime = 0.0f;
		bool                        isSpinning = false;
};

#endif // !RULETA_H
