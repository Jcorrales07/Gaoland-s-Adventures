#include "SFML/Graphics.hpp"
#include "Nivel2M1.h"
#include <iostream>
#include "SFML/Audio.hpp"

//sf::IntRect rectSourceSprite(0, 0, 1024, 720);

// Constructor
Nivel2M1::Nivel2M1()
	: N2M1Screen(sf::VideoMode(1024, 720), "Nivel 1 Menu")
{
	N2M1Screen.setFramerateLimit(60);
	this->pWidth = N2M1Screen.getSize().x;
	this->pHeight = N2M1Screen.getSize().y;
	this->run();
}

Nivel2M1::~Nivel2M1()
{

}


void Nivel2M1::run() {
	sf::Event event;
	// play musica
	playMusicn2();
	while (N2M1Screen.isOpen()) {
		// Si hace keypressed en right o left arrow cambia de slides
		while (N2M1Screen.pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				N2M1Screen.close();

		}
	}
}

// Tocar musica
void Nivel2M1::playMusicn2() {
	if (!n2m1music.openFromFile("Assets/sounds/n2m1musica.wav"))
		std::cout << "Error: no musica" << std::endl;
	n2m1music.play();
	n2m1music.setLoop(true);
	n2m1music.setVolume(50);
}

