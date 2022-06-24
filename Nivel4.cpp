#include "SFML/Graphics.hpp"
#include "Nivel4.h"
#include <iostream>
#include <stdlib.h>
#include "SFML/Audio.hpp"
#include "MenuScreen.h"

// constructor
Nivel4::Nivel4()
	: Nivel4Screen(sf::VideoMode(1024, 720), "Nivel4 (final)")
{
	Nivel4Screen.setFramerateLimit(60);
	this->pWidth = Nivel4Screen.getSize().x;
	this->pHeight = Nivel4Screen.getSize().y;
	this->run();
}

Nivel4::~Nivel4()
{
}

// abrir ventana en loop y que pase todo
void Nivel4::run() {
	while (Nivel4Screen.isOpen()) {
		while (Nivel4Screen.pollEvent(event)) {
			// Cerrar la ventana
			if (event.type == sf::Event::Closed)
				Nivel4Screen.close();
			// - Eventos de slides de la universidad
			if (f_touruni) {
				// Cambiar de diapositiva
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					if (nslide == 7) {
						f_touruni = false;
						f_prenivel = true;
						nslide = 1;
					}
					else
						nslide++;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && nslide > 1)
					nslide--;
				// tocar sonido
				playSound();
			}
			// - Eventos de slides del prenivel
			if (f_prenivel) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					if (nslide == 1) 
						nslide++;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (nslide == 1) {
						f_prenivel = false;
						f_touruni = true;
						nslide = 6;
					}
				}
				if (event.type == sf::Event::KeyPressed) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && nslide == 2) {
						nslide++;
						playSound();
						f_prenivel = false;
						f_Kant = true;
						std::cout << "nimodo, vamos a ver a Kante\n";
						nslide = 1;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && nslide == 2) {
						nslide++;
						playSound();
						f_prenivel = false;
						f_Descartes = true;
						std::cout << "nimodo, vamos a ver a Descartes\n";
						nslide = 1;
					}
				}
			}
			// - eventos de slides de nivel de Kant
			if (f_Kant) {
				clicLibro();
				if(!music.Playing)
					playMusic(0);
			}
			// - eventos de slides de nivel de Kant de lectura
			if (lectura) {
				if(lpracticaopen)
					nslide = 2;
				if (lpuroopen)
					nslide = 3;
				// salir del modo lectura
				if (event.type == sf::Event::KeyReleased) {
					if (lpracticaopen)
						lpracticaopen = false;
					if (lpuroopen)
						lpuroopen = false;
					lectura = false;
					f_Kant = true;
					nslide = 1;
				}
			}
			// - eventos de slides a nivel de incognita
			if (incognita) {
				if (event.type == sf::Event::KeyPressed) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						nslide = 5;
						next = true;
						incognita = false;
						break;
					}
					else {
						nslide = 6;
						next = true;
						incognita = false;
						break;
					}
				}
			}
			// evento de transicion antes del banco de preguntas
			if (next) {
				if (event.type == sf::Event::KeyReleased) {
					nslide = 7;
					pregunta = true;
					next = false;
				}
			}
			// - eventos de slides a nivel de preguntas
			if (pregunta) {
				nslide = 7;
				// SALIR DEL NIVEL Y VOLVER AL MENU
				if (salida && event.type == sf::Event::KeyReleased) {
					pregunta = false;
					music.stop();
					Nivel4Screen.close();
					MenuScreen ms;
				}
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && npregunta == 1) {
					nslide = 8;
					salida = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && (npregunta == 2 || npregunta == 3 || npregunta == 6)) {
					nslide = 8;
					salida = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && (npregunta == 4 || npregunta == 5)) {
					nslide = 8;
					salida = true;
				}
				// nslide = 9;
			}
			// - eventos de slides de nivel de Kant
			if (f_Descartes) {

			}
		}
		// refresh la pantalla
		sec = elapsed.asSeconds();
		elapsed = time.getElapsedTime();
		if (sec > 0.1f) {
			if (pregunta)
				transitionsec += sec;
			time.restart();
			sec = 0;
			dibujarFondo();
		}
	}
}

// f_touruni, o sea si esta en la uni
void Nivel4::uniNextSlide(int nslide) {
	switch (nslide) {
	case 1:
		txt.loadFromFile("Assets/img/nivel4/uni1.png");
		break;
	case 2:
		txt.loadFromFile("Assets/img/nivel4/uni2.png");
		break;
	case 3:
		txt.loadFromFile("Assets/img/nivel4/uni3.png");
		break;
	case 4:
		txt.loadFromFile("Assets/img/nivel4/uni4.png");
		break;
	case 5:
		txt.loadFromFile("Assets/img/nivel4/uni5.png");
		break;
	case 6:
		txt.loadFromFile("Assets/img/nivel4/uni6.png");
		break;
	case 7:
		txt.loadFromFile("Assets/img/nivel4/uni7.png");
		break;
	case 8:
		txt.loadFromFile("Assets/img/nivel4/uni7.png");
		break;
	}
	spr.setTexture(txt);
	spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2);
	spr.setPosition(pWidth / 2, pHeight / 2);
	Nivel4Screen.draw(spr);
}

// f_touruni, o sea si esta en la uni
void Nivel4::preENextSlide(int nslide) {
	switch (nslide) {
	case 1:
		txt.loadFromFile("Assets/img/nivel4/uni7.png");
		break;
	case 2:
		txt.loadFromFile("Assets/img/nivel4/uni8.png");
		break;
	}
	spr.setTexture(txt);
	spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2);
	spr.setPosition(pWidth / 2, pHeight / 2);
	Nivel4Screen.draw(spr);
}

// f_Kant, o sea si esta en el aula
void Nivel4::KantNextSlide(int nslide) {
	switch (nslide) {
	case 1:
		txt.loadFromFile("Assets/img/nivel4/fondoKant.png");
		break;
	case 2:
		txt.loadFromFile("Assets/img/nivel4/lecturapractica.png");
		break;
	case 3:
		txt.loadFromFile("Assets/img/nivel4/lecturapura.png");
		break;
	case 4: // fase de incognita
		txt.loadFromFile("Assets/img/nivel4/fondoIncognita.png");
		break;
	case 5: // correcto
		txt.loadFromFile("Assets/img/nivel4/fondoIncognita_C.png");
		break;
	case 6: // incorrecto
		txt.loadFromFile("Assets/img/nivel4/fondoIncognita_I.png");
		break;
	case 7: // banco de preguntas
		switch (npregunta) {
		case 1:
			txt.loadFromFile("Assets/img/nivel4/pregunta1.png");
			break;
		case 2:
			txt.loadFromFile("Assets/img/nivel4/pregunta2.png");
			break;
		case 3:
			txt.loadFromFile("Assets/img/nivel4/pregunta3.png");
			break;
		case 4:
			txt.loadFromFile("Assets/img/nivel4/pregunta4.png");
			break;
		case 5:
			txt.loadFromFile("Assets/img/nivel4/pregunta5.png");
			break;
		case 6:
			txt.loadFromFile("Assets/img/nivel4/pregunta6.png");
			break;
		}
		break;
	case 8: // correcta pregunta
		txt.loadFromFile("Assets/img/nivel4/fondoPregunta_C.png");
		break;
	case 9: // incorrecta pregunta
		txt.loadFromFile("Assets/img/nivel4/fondoPregunta_I.png");
		break;
	}
	spr.setTexture(txt);
	spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2);
	spr.setPosition(pWidth / 2, pHeight / 2);
	Nivel4Screen.draw(spr);
}

// Dibujar imagenes o slides dependiendo de la fase del nivel.
void Nivel4::dibujarFondo() {
	Nivel4Screen.clear();
	if (f_touruni)
		uniNextSlide(nslide);
	if (f_prenivel)
		preENextSlide(nslide);
	if (f_Kant) {
		KantNextSlide(nslide);
		dibujarCosas();
	}
	if (lectura || incognita || pregunta) 
		KantNextSlide(nslide);
	Nivel4Screen.display();
}

// Funcion para dibujar el estante y todas las cosas del juego
void Nivel4::dibujarCosas() {
	txtestante.loadFromFile("Assets/img/nivel4/estante.png");
	if (!isMouseInPractica)
		txtlibropractica.loadFromFile("Assets/img/nivel4/libropractica.png");
	else
		txtlibropractica.loadFromFile("Assets/img/nivel4/libropractica_d.png");
	if (!isMouseinPura)
		txtlibropura.loadFromFile("Assets/img/nivel4/libropura.png");
	else
		txtlibropura.loadFromFile("Assets/img/nivel4/libropura_d.png");
	if (!isMouseInHongo)
		txthongo.loadFromFile("Assets/img/nivel4/ch.png");
	else
		txthongo.loadFromFile("Assets/img/nivel4/ch_d.png");
	// cargar sprites
	sprestante.setTexture(txtestante);
	sprlibropractica.setTexture(txtlibropractica);
	sprlibropura.setTexture(txtlibropura);
	sprhongo.setTexture(txthongo);
	// Posicionarlos
	sprestante.setOrigin(sprestante.getLocalBounds().width / 2, sprestante.getLocalBounds().height / 2);
	sprlibropractica.setOrigin(sprlibropractica.getLocalBounds().width / 2, sprlibropractica.getLocalBounds().height / 2);
	sprlibropura.setOrigin(sprlibropura.getLocalBounds().width / 2, sprlibropura.getLocalBounds().height / 2);
	if(!isMouseInHongo)
		sprhongo.setOrigin(sprhongo.getLocalBounds().width / 2, sprhongo.getLocalBounds().height / 2);
	sprestante.setPosition(pWidth / 5, pHeight / 2.5 + 100);
	sprlibropractica.setPosition(sprestante.getLocalBounds().width / 4 - 50, sprestante.getLocalBounds().height - 100);
	sprlibropura.setPosition(sprestante.getLocalBounds().width / 3, sprestante.getLocalBounds().height - 120);
	sprhongo.setPosition(pWidth / 2 + 50, pHeight / 2 + 70);
	// dibujar
	Nivel4Screen.draw(sprestante);
	Nivel4Screen.draw(sprlibropractica);
	Nivel4Screen.draw(sprlibropura);
	Nivel4Screen.draw(sprhongo);
}

// Realiza una accion dependiendo de cual libro cliqueo
void Nivel4::clicLibro() {
	if (sprlibropractica.getGlobalBounds().contains(Nivel4Screen.mapPixelToCoords(sf::Mouse::getPosition(Nivel4Screen)))){
		isMouseInPractica = true;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			lpracticaopen = true;
			lpuroopen = false;
			std::cout << "libro de razon practica\n";
			leer();
		}
		return;
	}
	if (sprlibropura.getGlobalBounds().contains(Nivel4Screen.mapPixelToCoords(sf::Mouse::getPosition(Nivel4Screen)))) {
		isMouseinPura = true;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			lpracticaopen = true;
			lpuroopen = false;
			std::cout << "libro de razon practica\n";
			leer();
		}
		return;
	}
	if (sprhongo.getGlobalBounds().contains(Nivel4Screen.mapPixelToCoords(sf::Mouse::getPosition(Nivel4Screen)))) {
		isMouseInHongo = true;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			lpracticaopen = false;
			lpuroopen = false;
			lectura = false;
			incognita = true;
			nslide = 4;
			std::cout << "Espero estes listo\n";
		}
		return;
	}
	isMouseInHongo = false;
	isMouseInPractica = false;
	isMouseinPura = false;
}

// Deshabilita temporalmente la fase de Kant para leer
void Nivel4::leer() {
	if (lpracticaopen || lpuroopen) {
		lectura = true;
		f_Kant = false;
	}
	playSound();
}
// Reproducir sonidos dependiendo de la fase del juego
void Nivel4::playSound() {
	// fase de tour en la uni
	if (f_touruni) 
		if (nslide > 0 && nslide < 7)
			sound.openFromFile("Assets/sounds/nivel4/pasos.wav");
	// fase de pre nivel donde elige cual lugar
	if (f_prenivel) 
		if (nslide == 3)
			sound.openFromFile("Assets/sounds/nivel4/letsgo.wav");
	if (lectura)
		sound.openFromFile("Assets/sounds/nivel4/pasarpagina.wav");
	// reproducir sonido
	sound.play();
}

// Reproducir musica dependiendo de la fase del juego (Kant o descartes
void Nivel4::playMusic(int eleccion) {
	if (eleccion == 0)
		music.openFromFile("Assets/sounds/nivel4/KantTheme.wav");
	if (eleccion == 1)
		music.openFromFile("Assets/sounds/nivel4/DescartesTheme.wav");
	// reproducir sonido
	music.play();
	music.setVolume(30);
}
