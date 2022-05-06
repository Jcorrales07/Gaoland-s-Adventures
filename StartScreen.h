#pragma once
#include "SFML/Graphics.hpp"

class StartScreen {
	public:
		StartScreen();
		~StartScreen();
		void                        createWindow();

		
	private:
		sf::RectangleShape          background;
		sf::Texture					startTexture;
		sf::Font					font;
		sf::Text					startTxt, press2PlayTxt;
		
	//private:	
		//void                        createWindow();
};

