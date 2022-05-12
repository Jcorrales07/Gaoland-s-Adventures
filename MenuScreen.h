#pragma once

#include "include/SFML/Graphics.hpp"
#include "Menu.h"

using namespace sf;

class MenuScreen {
	public:
		MenuScreen();
		~MenuScreen();

	public:
		void							run();
		void							processEvents();
		void							update();
		void 							render();
		
	public:
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

