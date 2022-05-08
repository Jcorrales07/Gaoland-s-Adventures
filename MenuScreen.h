#pragma once

#include "SFML/Graphics.hpp"
#include "Menu.h"

class MenuScreen {
	public:
		MenuScreen();
		~MenuScreen();

	public:
		void							run();
		void							processEvents();
		void							update();
		void 							render();
		void							menuScreen();
		double							getPWidth();
		double							getPHeight();
			
	private:
		sf::RenderWindow				PrincipalMenu;
		sf::RectangleShape				background;
		sf::Texture						backgroundTexture;
		double                          pWidth, pHeight;
};

