#ifndef GAOLAND_S_ADVENTURES_STARTSCREEN_H
#define GAOLAND_S_ADVENTURES_STARTSCREEN_H
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

#endif // !GAOLAND_S_ADVENTURES_STARTSCREEN_H

