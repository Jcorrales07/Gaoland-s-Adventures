#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string.h>

class Nivel2M3 {
	// Private sin el private:
	int globalsec = 0;
	// Time es el contador nomral, elapsed obtiene el tiempo pasado
	std::string tiempo, vidas;
	sf::Font f;
	sf::Text t;
	sf::Clock time;
	sf::Time elapsed;
	sf::RenderWindow N2M3Screen;
	sf::Music n2m3music, cartamusic, plymusic, preguntamusic;
	sf::Texture txt, blocktxt[5], auxtxt;
	sf::Sprite spr, blockspr[5], auxspr;
	double pWidth, pHeight;
	void dibujarFondo(int frame); 
	void dibujarBloque(int numerobloques);
	void dibujarPregunta();
	void setText();
	void playMusic();
	void refresh();
	void setRandom();
	void mostrarResultado(bool escorrecto);
	void Tiempo(int sec);
	int clicBtn(sf::RenderWindow& window);
public:
	Nivel2M3();
	~Nivel2M3();
	//FUncioens
	void run();
	void close();
	double getPWidth();
	double getPHeight();
};
