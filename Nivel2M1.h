#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Nivel2M1 {
	// Private sin el private:
	int globalsec = 0; 
	// Time es el contador nomral, elapsed obtiene el tiempo pasado
	sf::Clock time;
	sf::Time elapsed;
	sf::RenderWindow N2M1Screen;
	sf::Music n2m1music, cartamusic, plymusic;
	sf::Texture txt, plytxt, cartatxt;
	sf::Sprite spr, plyspr, cartaspr;
	double pWidth, pHeight;
public:
	Nivel2M1();
	~Nivel2M1();
	//FUncioens
	void run();
	void playMusicn2();
	double getPWidth();
	double getPHeight();
};