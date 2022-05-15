#pragma once

#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H


#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Options.h"

class MenuScreen {
	public:
		MenuScreen();
		~MenuScreen();

	public:
		//Window functions
		void							run();
		void							processEvents();
		void							update();
		void 							render();

	public:
		//Menu functions
		void 							moveUp();
		void 							moveDown();
		void                            initMenuOptions();
		void                            drawMenuOptions(sf::RenderTarget &window);
		int                             getIndex();
	
	public:
		//Menu background
		void                            initBackground();

		//Music function
		void                            initMusic();
		
		//Sound effect
		void                            initSoundEffect();
		void							playSoundEffect();

	public:
		float							getPWidth();
		float							getPHeight();
		
	// Variables	
	private:
		//Window
		sf::RenderWindow				principalMenu;
		float							pWidth, pHeight;

		//Menu Options
		sf::Sprite						menuBtns[3];
		sf::Texture						btnTextures;
		bool							isPressed;
		int 						    index;

		Options 						options;
		
		//Menu Background
		sf::Texture						menuTexture;
		sf::Sprite						menuSprite;
		sf::IntRect						rectSourceSprite;
		
		// Music
		sf::Music 					    menuMusic;
		float							musicPts;
		
		//Sound effect
		sf::SoundBuffer					buffer;
		sf::Sound						sound;

};

#endif // !MENU_SCREEN_H
