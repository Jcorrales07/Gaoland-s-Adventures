#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

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
		RenderWindow				startWindow;
		Font						font;
		Texture						startTexture;
		Sprite						startSprite;
		Text						welcomeTxt, press2PlayTxt;
		double						sWidth, sHeight;
};

