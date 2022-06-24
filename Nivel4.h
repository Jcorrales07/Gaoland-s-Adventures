#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Nivel4 {
	// Variables y funciones generales
	int nslide = 1;
	float sec, transitionsec = 0.0f;
	double pWidth, pHeight;
	sf::RenderWindow Nivel4Screen;
	sf::Clock time;
	sf::Time elapsed;
	sf::Sprite spr, auxspr;
	sf::Texture txt, auxtxt;
	sf::Music music, sound;
	sf::Event event;
	sf::Text text;
	sf::Font f;
	void playMusic(int eleccion);
	void playSound();
	void dibujarFondo();
	// Variables y funciones para fase 1 - slides
	bool f_touruni = true;
	void uniNextSlide(int nslide);
	// Variables y funciones para fase 2 - pre-encuentro
	bool f_prenivel = false;
	void preENextSlide(int nslide);
	// VAriables y funciones para fase 3 - nivel Kant/Descartes
	int npregunta;
	bool f_Kant = false, f_Descartes = false, lectura = false,
		lpracticaopen = false, lpuroopen = false, isMouseInHongo = false,
		isMouseInPractica = false, isMouseinPura = false,
		incognita = false, pregunta = false, salida = false, next = false;
	void KantNextSlide(int nslide);
	void DescartesNextSlide(int nslide);
	void dibujarCosas();
	void clicLibro();
	void leer();
	void responderIncognita();
	sf::Texture txtestante, txtlibropractica, txtlibropura, txthongo;
	sf::Sprite sprestante, sprlibropractica, sprlibropura, sprhongo;
public:
	Nivel4();
	~Nivel4();
	//FUncioens
	void run();
	void close();
	double getPWidth();
	double getPHeight();
};
