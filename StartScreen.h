#pragma once
#include "SFML/Graphics.hpp"

class StartScreen {
	public:
		StartScreen();
		~StartScreen();

	public:
		void						run();
		void						processEvents();
		void						update();	
		void 						render();
		bool						isOpen();
		void						close();

	public:
		void						setText();
		double						getSWidth();
		double						getSHeight();
		
	private:
		sf::RenderWindow			startWindow;
		sf::Font					font;
		sf::Texture                 startTexture;
		sf::Sprite					startSprite;
		sf::Text					welcomeTxt, press2PlayTxt;
		double						sWidth, sHeight;
};

