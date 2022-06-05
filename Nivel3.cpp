#include "SFML/Graphics.hpp"
#include "Nivel3.h"
#include "Menu.h"
#include <iostream>
#include "SFML/Audio.hpp"

sf::IntRect rectSourceSprite3(0, 0, 1450, 940);
sf::IntRect IRpersonaje(0, 0, 175, 150);

// Constructor
Nivel3::Nivel3()
	: Nivel3Screen(VideoMode(1500, 1000), "Nivel 3 - Batalla")
{
	Nivel3Screen.setFramerateLimit(60);
	this->pWidth = Nivel3Screen.getSize().x;
	this->pHeight = Nivel3Screen.getSize().y;
	this->run();
}

Nivel3::~Nivel3()
{

}

// Abrir ventana
void Nivel3::run() {
	sf::Event event;
	this->playMusic();
	// Aplicar fondo
	txt.loadFromFile("assets/img/nivel3/nivel3bg.png");
	this->spr.setTexture(txt);
	this->spr.setTextureRect(rectSourceSprite3);
	this->spr.setPosition(Vector2f(50, 50));
	Nivel3Screen.draw(spr);
	Nivel3Screen.display();
	while (Nivel3Screen.isOpen()) {
		// Si hace keypressed en right o left arrow cambia de slides
		while (Nivel3Screen.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed)
				if (sf::Keyboard::isKeyPressed(Keyboard::Escape) || sf::Keyboard::isKeyPressed(Keyboard::Space))
					Nivel3Screen.close();
		}
	}
}

// Tocar musica
void Nivel3::playMusic() {
	if (!n3music.openFromFile("Assets/sounds/nivel3/musicbattle.wav"))
		std::cout << "Error: no musica" << std::endl;
	n3music.play();
	n3music.setLoop(true);
	n3music.setVolume(40);
}