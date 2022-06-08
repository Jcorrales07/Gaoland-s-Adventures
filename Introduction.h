#pragma once

#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "iostream"

using std::cout;
using std::endl;

class Introduction
{
	private: 
		int							slide; // default: 1
		int							sec;
		
		sf::Clock					time;
		sf::Time					elapsed;
		sf::RenderWindow			IntroWin;
		sf::Texture					txt;
		sf::Sprite                  spr;
		sf::Music                   music;
		sf::Music                   voz;
		sf::IntRect					rectSourceSprite;
		

	public:
		Introduction();
		~Introduction();

		//Funciones
		void                        run();
		void                        processEvents();
		void                        render();
		void						playMusic();
		void						initTextures();
		void						playSlide();
		void						playSlideNext();


	

};

#endif // !INTRODUCTION_H
