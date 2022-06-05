#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Nivel3 {
	// Private sin el private:
	int vida1, vida2; 
	sf::RenderWindow Nivel3Screen;
	sf::Music n3music;
	sf::Texture txt;
	sf::Sprite spr;
	double pWidth, pHeight;
public:
	Nivel3();
	~Nivel3();
	//FUncioens
	void run();
	void playMusic();
	void close();
	double getPWidth();
	double getPHeight();
};