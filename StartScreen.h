#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "SFML/Graphics.hpp"

class StartScreen {
	public:
		StartScreen();
		~StartScreen();

	public:
		//Window functions
		void						run();
		void						processEvents();
		void						update();	
		void 						render();
		float						getSWidth();
		float						getSHeight();
		
		// Background function
		void 						initBackground();
		
		// Titles function
		void						initTitles();
		

	private:
		
		// Window
		sf::RenderWindow			startWindow;
		float						sWidth, sHeight;
		
		// Background
		sf::Texture                 startTexture;
		sf::Sprite					startSprite;
		sf::IntRect					rectSourceSprite;

		//Titles
		sf::Texture					titleTexture;
		sf::Sprite					titleSprite;
		sf::Sprite					press2PlaySprite;
		
};

#endif // !STARTSCREEN_H
