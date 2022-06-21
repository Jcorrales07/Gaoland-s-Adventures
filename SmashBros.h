#pragma once


#ifndef SMASH_BROS_H
#define SMASH_BROS_H

#include "Animation.h"
#include "SFML/Graphics.hpp"
#include "iostream"
#include "string"
#include <vector>


using std::vector;
using std::string;

class SmashBros
{
	
	//Variables
	private:
		sf::RenderWindow				smashWindow;
		
		sf::Texture						backgroundTexture;
		sf::Sprite						backgroundSprite;
		
		//vidas 
		sf::Texture						heartTexture;
		sf::Sprite                      heartsPlayer[5];
		sf::Sprite                      heartsEnemy[5];

		//Dinamica de vida
		int                             playerLife;
		int                             enemyLife;

		// puntos
		int                             score;

		// Texto
		sf::Font   						font;
		
		sf::Text						timerSeconds;
		sf::Text						scoreText;
		sf::Text                        question;

		//delta time
		sf::Clock						deltaTimeTimer;
		float							deltaTime;

		//Mario animation
		sf::Texture						marioTxt;
		sf::Sprite						marioSprt;
		Animation						marioIdle;

		void                            animIdleMario();

		//Bowser animation
		sf::Texture						bowserTxt;
		sf::Sprite						bowserSprt;
		Animation						bowserIdle;

		void                            animIdleBowser();
		
		// vector de preguntas
		vector<string>					questions;
		
		
	//Funciones
	private:
		void                            initResources();
		
		void							run();
		void							processEvents();
		void							update();
		void							render();
		
		void							loadTextures();

		void                            loadFont();
		
		void                            setUpHeartSprites();
		
		void                            drawLives(int amountLife, sf::Sprite hearts[]);

		//preguntas
		void                            loadQuestions();
		
		//animaciones
		void                            setUpAnimations();

		
	public:
		SmashBros();
		~SmashBros();

};

#endif // !SMASH_BROS_H
