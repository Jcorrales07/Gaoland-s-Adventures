#include "Introduction.h"
#include "Ruleta.h"
#include "SFML/Graphics.hpp"

Introduction::Introduction() 
	: IntroWin(sf::VideoMode(1366, 768), "Introduction")
{
	IntroWin.setFramerateLimit(60);
	this->slide = 1;
	this->run();
}


Introduction::~Introduction()
{

}

void Introduction::run() {
	this->initTextures();
	this->playSlide();
	this->playMusic();

	while (IntroWin.isOpen()) {
		processEvents();
		render();
	}
}

void Introduction::processEvents()
{
	sf::Event event;

	// Si hace keypressed en right o left arrow cambia de slides
	while (IntroWin.pollEvent(event)) {
		
		if (event.type == sf::Event::Closed)
			IntroWin.close();

		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
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

void Introduction::render()
{
	IntroWin.clear();
	IntroWin.draw(spr);
	IntroWin.display();
}

void Introduction::playMusic() {
	if (!music.openFromFile("assets/sounds/musicaSacra.wav"))
		std::cout << "Error: no musica" << std::endl;
	
	music.setLoop(true);
	music.setVolume(50);
	music.play();
}

void Introduction::initTextures()
{
	if (!txt.loadFromFile("assets/img/bgs/slides.png"))
		cout << "Error: no se pudo cargar la imagen" << endl;

	this->spr.setTexture(txt);
}

void Introduction::playSlide() {
	// Slide 1
	// tocar voz de narrador
	if (!voz.openFromFile("assets/sounds/nivel1/slide1v.wav"))
		cout << "ERROR: NO SE PUDO REPRODUCIR LA MUSICA." << endl;

	voz.setVolume(100);
	voz.play();
	
	this->spr.setTextureRect(sf::IntRect(0, 0, 1366, 768));

	// pal segundo slide
	slide++;
}

void Introduction::playSlideNext() {

	switch (slide) {

	case 2:

		if (!voz.openFromFile("assets/sounds/nivel1/slide2v.wav"))
			std::cout << "ERROR: voz slide 2" << std::endl;

		rectSourceSprite = sf::IntRect(1366, 0, 1366, 768);
		break;

	case 3:

		if (!voz.openFromFile("assets/sounds/nivel1/slide3v.wav"))
			std::cout << "ERROR: voz slide 3" << std::endl;

		rectSourceSprite = sf::IntRect(1366 * 2, 0, 1366, 768);
		break;

	case 4:

		if (!voz.openFromFile("assets/sounds/nivel1/slide4v.wav"))
			std::cout << "ERROR: voz slide 4" << std::endl;

		rectSourceSprite = sf::IntRect(1366 * 3, 0, 1366, 768);
		break;

	case 5:

		if (!voz.openFromFile("assets/sounds/nivel1/slide5v.wav"))
			std::cout << "ERROR: voz slide 5" << std::endl;

		rectSourceSprite = sf::IntRect(1366 * 4, 0, 1366, 768);
		break;
	}
	
	// play audio
	voz.setVolume(100);
	voz.setLoop(false);
	voz.play();

	// set fondo de pantalla (imagen o slide)
	this->spr.setTextureRect(rectSourceSprite);

	// pal segundo slide
	slide++;

	if (slide > 6) {
		voz.pause();
		music.pause();
		IntroWin.close();
		Ruleta ruleta;
	}
}