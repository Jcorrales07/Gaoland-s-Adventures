#pragma once


#ifndef SMASH_BROS_H
#define SMASH_BROS_H


#include "SFML/Graphics.hpp"
#include "iostream"


class SmashBros
{
	
	private:
		sf::RenderWindow				smashWindow;
		
		sf::Texture						backgroundTexture,
										heartTexture;

		sf::Sprite						backgroundSprite;
		sf::Sprite                      heartsPlayer[5];
		sf::Sprite                      heartsEnemy[5];
		
		void							run();
		void							processEvents();
		void							update();
		void							render();
		
		void							loadTextures();
		void                            setUpHeartSprites();

		//Dinamica de vida
		int                             playerLife;
		int                             enemyLife;

		void                            drawLives(int amountLife, sf::Sprite hearts[]);
		
		
	public:
		SmashBros();
		~SmashBros();

		
		
		

};

#endif // !SMASH_BROS_H
