#include "MenuScreen.h"
#include "SFML/Graphics.hpp"
#include "StartScreen.h"
#include "Menu.h"
#include "SFML/Audio.hpp"
#include "iostream"

using namespace std;

sf::Music mmusic, btnms;

MenuScreen::MenuScreen()
 : PrincipalMenu(VideoMode(1500, 1000), "Principal Menu")
{
	PrincipalMenu.setFramerateLimit(60);
	this->pWidth = PrincipalMenu.getSize().x;
	this->pHeight = PrincipalMenu.getSize().y;
	this->run();
}

MenuScreen::~MenuScreen()
{
	
}

void MenuScreen::run()
{
	//Cargar el sprite de la imagen de fondo
	menuTexture.loadFromFile("assets/img/bgs/menuScreenSS.png");
	this->menuSprite.setTexture(menuTexture);
	IntRect rectSourceSprite(0, 0, 1500, 1000);
	this->menuSprite.setTextureRect(rectSourceSprite);
	
	sf::Clock clock;

	// Tocar musica
	if (!mmusic.openFromFile("Assets/sounds/ForestoftheElves_MainMenu.wav"))
		cout << "ERROR: NO SE PUDO REPRODUCIR LA MUSICA.";
	mmusic.setVolume(50);
	mmusic.setLoop(true);
	mmusic.play();

	while (PrincipalMenu.isOpen()) {
		processEvents();
		update();
		
		if (clock.getElapsedTime().asSeconds() > 0.1f) {
			if (rectSourceSprite.left == 10500) rectSourceSprite.left = 0;
			else rectSourceSprite.left += 1500;

			menuSprite.setTextureRect(rectSourceSprite);
			clock.restart();
		}

		render();
	}
}

void MenuScreen::processEvents()
{
	// Cargar sonido de btn
	if (!btnms.openFromFile("Assets/sounds/botonbip.wav"))
		cout << "ERROR: NO SE PUDO REPRODUCIR EL BIP.";
	Menu menu(1500, 1000);
	sf::Event event;
	while (PrincipalMenu.pollEvent(event)) {
		switch (menu.clicBtn(PrincipalMenu)) {
		case 0:
			cout << "LE DISTE A PLAY" << endl;
			btnms.play();
			break;
		case 1:
			cout << "LE DISTE A opciones" << endl;
			btnms.play();
			break;
		case 2:
			cout << "LE DISTE A PLAY" << endl;
			btnms.play();
			mmusic.stop();
			PrincipalMenu.close();
			break;
		}
	}
}

void MenuScreen::update()
{
	
}

void MenuScreen::render()
{
	Menu menu(1500, 1000);
	PrincipalMenu.clear();
	PrincipalMenu.draw(menuSprite);
	menu.drawMenuImg(PrincipalMenu);
	PrincipalMenu.display();	
}

double MenuScreen::getPWidth()
{
	return this->pWidth;
}

double MenuScreen::getPHeight()
{
	return this->pHeight;
}
