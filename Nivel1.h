#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Nivel1 {
	// Private sin el private:
	int slide = 1, sec = 0; // Por default empieza en 1
	// Time es el contador nomral, elapsed obtiene el tiempo pasado
	sf::Clock time;
	sf::Time elapsed;
	sf::RenderWindow Nivel1Screen;
	sf::Music n1music;
	sf::Texture txt;
	sf::Sprite spr;
	double pWidth, pHeight;
public:
	Nivel1();
	~Nivel1();
	//FUncioens
	void run();
	void playMusic();
	void close();
	void playSlide();
	void playSlideNext();
	double getPWidth();
	double getPHeight();
};