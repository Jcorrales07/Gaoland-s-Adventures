#pragma once

#ifndef OPTIONS_H
#define OPTIONS_H

#include "SFML/Graphics.hpp"

class Options
{
	public:
		Options();
		~Options();

		//Window functions
		void                        initWindow();
		void						run();
		void						processEvents();
		void						update();
		void 						render();
		float						getOWidth();
		float						getOHeight();

		//Text function
		void 						initText();

		//Music control
		void						setMusicVolTo(float musicVol);
	
	private:

		//Window 
		sf::RenderWindow			optionsWindow;
		float						OWidth, OHeight;

		//Texts
		sf::Font					font;
		sf::Text					musicVolTxt;

		//Music control
		float						ptsMusicVol;
		
};

#endif // !OPTIONS_H

