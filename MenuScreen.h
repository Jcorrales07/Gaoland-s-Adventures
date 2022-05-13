#pragma once

#include "SFML/Graphics.hpp"
#include "Menu.h"

using namespace sf;

class MenuScreen {
	public:
		MenuScreen();
		~MenuScreen();

		void							run();
		void							processEvents();
		void							update();
		void 							render();
		
		double							getPWidth();
		double							getPHeight();
			
	private:
		RenderWindow					PrincipalMenu;
		RectangleShape					background;
		Texture							menuTexture;
		Sprite							menuSprite;
		Texture							backgroundTexture;
		double                          pWidth, pHeight;
};

