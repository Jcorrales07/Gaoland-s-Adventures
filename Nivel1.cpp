#include "SFML/Graphics.hpp"
#include "Nivel1.h"
#include "Nivel2M3.h"
#include "Menu.h"
#include <iostream>
#include "SFML/Audio.hpp"

sf::Music mu, voz;

// Constructor
Nivel1::Nivel1()
	: Nivel1Screen(VideoMode(1024, 720), "Nivel 1")
{
	Nivel1Screen.setFramerateLimit(60);
	this->pWidth = Nivel1Screen.getSize().x;
	this->pHeight = Nivel1Screen.getSize().y;
	this->run();
}

Nivel1::~Nivel1()
{

}


void Nivel1::run() {
	sf::Event event;
	// play musica
	this->playSlide();
	this->playMusic();
	while (Nivel1Screen.isOpen()) {
		// Si hace keypressed en right o left arrow cambia de slides
		while (Nivel1Screen.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(Keyboard::Right) || sf::Keyboard::isKeyPressed(Keyboard::Space)) 
					playSlideNext();
			}
		}
		// Mover slides automaticamente
		sec = elapsed.asSeconds();
		elapsed = time.getElapsedTime();
		if (sec > 25 && slide <= 5) {
			time.restart();
			sec = 0;
			playSlideNext();
			
		}
	}
}

// Tocar musica
void Nivel1::playMusic() {
	if (!n1music.openFromFile("Assets/sounds/musica sacra siglo xv.wav"))
		std::cout << "Error: no musica" << std::endl;
	n1music.play();
	n1music.setLoop(true);
	n1music.setVolume(50);
}

void Nivel1::playSlide() {
	// Slide 1
	// tocar voz de narrador
	if (!voz.openFromFile("Assets/sounds/nivel1/slide 1v.wav"))
		std::cout << "ERROR: NO SE PUDO REPRODUCIR LA MUSICA.";
	voz.setVolume(100);
	if(!voz.getStatus() == sf::SoundSource::Status::Playing)
		voz.play();
	// Display primer slide
	txt.loadFromFile("assets/img/nivel1/slide 1.png");
	this->spr.setTexture(txt);
	this->spr.setOrigin(0.f, 0.f);
	this->spr.scale(1024.f / spr.getTexture()->getSize().x, 720.f / spr.getTexture()->getSize().y);
	std::cout << "Pantalla cargada";
	Nivel1Screen.draw(spr);
	voz.play();
	Nivel1Screen.display();
	// pal segundo slide
	slide++;
}

void Nivel1::playSlideNext() {
	Nivel1Screen.clear();
	switch (slide) {
	case 2:
		if (!voz.openFromFile("Assets/sounds/nivel1/slide 2v.wav"))
			std::cout << "ERROR: NO SE PUDO REPRODUCIR LA MUSICA.";
		txt.loadFromFile("assets/img/nivel1/slide 2.png");
		break;
	case 3:
		if (!voz.openFromFile("Assets/sounds/nivel1/slide 3v.wav"))
			std::cout << "ERROR: NO SE PUDO REPRODUCIR LA MUSICA.";
		txt.loadFromFile("assets/img/nivel1/slide 3.png");
		break;
	case 4:
		if (!voz.openFromFile("Assets/sounds/nivel1/slide 4v.wav"))
			std::cout << "ERROR: NO SE PUDO REPRODUCIR LA MUSICA.";
		txt.loadFromFile("assets/img/nivel1/slide 4.png");
		break;
	case 5:
		if (!voz.openFromFile("Assets/sounds/nivel1/slide 5v.wav"))
			std::cout << "ERROR: NO SE PUDO REPRODUCIR LA MUSICA.";
		txt.loadFromFile("assets/img/nivel1/slide 5.png");
		break;
	}
	// play audio
	voz.setVolume(100);
	voz.setLoop(false);
	voz.play();
	// set fondo de pantalla (imagen o slide)
	this->spr.setTexture(txt);
	//this->spr.scale(1024.f / spr.getTexture()->getSize().x, 720.f / spr.getTexture()->getSize().y);
	Nivel1Screen.draw(spr);
	Nivel1Screen.display();
	// pal segundo slide
	slide++;
	if (slide > 6) {
		n1music.stop();
		voz.stop();
		Nivel1Screen.close();
		Nivel2M3 n2m3;
		// Nivel3 n3;
	}		
}

