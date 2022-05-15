#pragma once

#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H


#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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

		//Menu functions
		void 							moveUp();
		void 							moveDown();
		void                            initMenuOptions();
		void                            drawMenuOptions(sf::RenderTarget &window);
		int                             getIndex();
		
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
			
	private:
		//Window
		sf::RenderWindow				principalMenu;
		
		//Menu Options
		sf::Sprite						menuBtns[3];
		sf::Texture						btnTextures;
		int 						    index;
		
		//Menu Background
		sf::Texture						menuTexture;
		sf::Sprite						menuSprite;
		sf::IntRect						rectSourceSprite;
		
		// Music
		sf::Music 					    menuMusic;
		
		//Sound effect
		sf::SoundBuffer					buffer;
		sf::Sound						sound;

		// Window Size
		float                          pWidth, pHeight;

};

#endif // !MENU_SCREEN_H
