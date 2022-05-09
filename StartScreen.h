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
		sf::RectangleShape			background;
		sf::Texture					startTexture;
		sf::Font					font;
		sf::Text					welcomeTxt, press2PlayTxt;
		double						sWidth, sHeight;
};

