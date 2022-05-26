#pragma once

#ifndef RULETA_H
#define RULETA_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "stdio.h"
#include "windows.h"
#include "iostream"
#include "Theme.h"

using std::cerr;
using std::endl;

class Ruleta
{
	public:
		Ruleta();
		~Ruleta();

	public:
		//Window functions
		void						initWindow();
		void						run();
		void						processEvents();
		void						update();
		void						render();

		//Window states
		void						renderRoulette();
		void						renderArtTheme();
		void						renderScienceTheme();
		void						renderHistoryTheme();
		void						renderPoliticsTheme();

		// Select a theme
		int                         genRandomNum();
		void                        setStateTheme();
		
		//Texturas y font
		void						initTexture();
		void						initFont();

		//Evento para cuando se toque el espacio
		void						onSpacePressed(sf::Event &event);
		void						onSpaceReleased(sf::Event &event);

		//animacion de la ruleta
		void						animationRoulette();
		void						resetClock();
		void						spinRoulette();

		// animacion de la caja
		void                        animationBox();

		// funciones para las preguntas
		void                        putQuestInScreen();
		

	private:
		sf::RenderWindow			window;
		sf::Texture					ruletaTexture, bgTexture, btnSpaceTxt, themesTextures, boxTexture;
		sf::Sprite					ruletaSprite, bgSprite, btnSpaceSprt, boxSprite;
		sf::Font					font;
		sf::Text					text;

		//Variables para la animacion de la ruleta
		sf::Clock                   timer, clock;
		Animation                   animation;
		Animation                   boxAnimation;
		float                       deltaTime = 0.0f;
		bool                        isSpinning = false;

		// Window booleans states
		bool                        isRouletteShown;
		bool						isArtThemeShown = false;
		bool						isScienceThemeShown = false;
		bool						isHistoryThemeShown = false;
		bool						isPoliticsThemeShown = false;
		int                         stateNum;

		// Class states
		Theme						art;
		Theme						science;
		Theme						history;
		Theme						politics;

		// Question variables
		sf::Text					questionText;
		sf::FloatRect               backgroundRect;
		sf::RectangleShape          questionBackground;
};

#endif // !RULETA_H
