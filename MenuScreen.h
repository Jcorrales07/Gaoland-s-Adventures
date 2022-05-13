#pragma once

#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "Button.h"

class MenuScreen {
	public:
		MenuScreen();
		~MenuScreen();

	public:
		void							run();
		void							processEvents();
		void							update();
		void 							render();

		void 							moveUp();
		void 							moveDown();
		void                            initMenuOptions();
		void                            drawMenuOptions(sf::RenderTarget &window);
		int                             getIndex();
		

	public:
		double							getPWidth();
		double							getPHeight();
			
	private:
		sf::RenderWindow				principalMenu;
		sf::Texture						menuTexture;
		sf::Sprite						menuSprite;
		sf::Texture						btnTextures;
		double                          pWidth, pHeight;

		int 						    index;
		sf::Sprite						menuBtns[3];
};

