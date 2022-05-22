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

		//Window states
		void                            renderMainMenu();
		void                            renderOptions();

	public:
		//Menu functions
		void 							moveUp();
		void 							moveDown();
		void                            initMenuOptions();
		void                            drawMenuOptions(sf::RenderTarget &window);
		int                             getIndex();
	
		// volume funcs
		void                            volUp();
		void                            volDown();
		
	public:
		//Text function
		void 							initText();

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

		//Window states
		bool							isMainMenuTrue = true;
		bool                            isOptionsTrue = false;

		//Menu Options
		sf::Sprite						menuBtns[3];
		sf::Texture						btnTextures;
		int 						    index;

		// Option menu
		//Texts
		sf::Font						font;
		sf::Text						musicVolTxt,
										keyInstructionsTxt,
										musicVolValTxt,
				                        arrowKeyLeft,
										arrowKeyRight,
										exitOptionsTxt;

		//Menu Background
		sf::Texture						menuTexture;
		sf::Sprite						menuSprite;
		sf::IntRect						rectSourceSprite;
		
		// Music
		sf::Music 					    menuMusic;
		int								musicPts;
		
		//Sound effect
		sf::SoundBuffer					buffer;
		sf::Sound						sound;

};

#endif // !MENU_SCREEN_H
