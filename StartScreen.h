#pragma once
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
		
		// Background
		sf::Texture                 startTexture;
		sf::Sprite					startSprite;
		sf::IntRect					rectSourceSprite;

		//Titles
		sf::Texture					titleTexture;
		sf::Sprite					titleSprite;
		sf::Sprite					press2PlaySprite;
		
		float						sWidth, sHeight;
};

