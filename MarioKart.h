//Game.h***
#pragma once

#ifndef MARIO_KART_H
#define MARIO_KART_H

#include "SFML/Graphics.hpp"
#include "Car.h"
#include "BadCar.h"


class MarioKart
{
	private:
		//Window variables
		sf::RenderWindow				gameWindow;
		float							wWidth,
										wHeight;

		// Text variables for info actual game
		sf::Font						font;
		sf::Text						separator;
		sf::Text						scoreTxt,
										valScoreTxt,
										highScoreTxt,
										valHiScoreTxt,
										livesTxt,
										valLivesTxt,
										levelTxt,
										valLevelTxt,
										speedTxt,
										valSpeedTxt;

		//Game Variables
		int 							score = 0,
										highScore = 0,
										lives = 3,
										level = 0,
										maxLevel = 10,
										actualSpeed = 0,
										maxSpeed = 10;

		Car*							myCar; //Carro que el usuario mueve
		BadCar*							badCar; //Carro que se mueve de forma aleatoria


		//Textures
		sf::Texture						textures;
		sf::Sprite						roadSprite;

		// animacion
		sf::IntRect                     roadRect;

	public:
		MarioKart();
		~MarioKart();

		//Window functions
		void							run();
		void							initWindow();
		void							processEvents();
		void							render();
		void  							update();
		sf::RenderWindow&				getWindow();

		//Text functions
		void							initText();
		void                            renderText();

		//Texture functions // Render Functions
		void							initTextures();

		// Car functions
		void                            initCar();
		void                            renderCar();
		void                            deleteCar();
		void                            procesarColiciones();
		void                            nextLevel();
		void                            movementRoad();
};


#endif // !MARIO_KART_H
