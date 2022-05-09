#include "StartScreen.h"
#include "SFML/Graphics.hpp"
#include "iostream"
#include "MenuScreen.h"

using std::cout;
using std::endl;
using std::cerr;

StartScreen::StartScreen() 
	: startWindow(sf::VideoMode(1500, 1000), "Welcome to the game!")
{
	this->sWidth = startWindow.getSize().x;
	this->sHeight = startWindow.getSize().y;
	startWindow.setFramerateLimit(60);

	//Cargar la fuente para el texto
	if (!font.loadFromFile("assets/fonts/OcrAExt.ttf"))
		cerr << "Error loading font" << endl;

	setText();
}

StartScreen::~StartScreen()
{
	
}

void StartScreen::run()
{
	
	//Cargar el sprite de la imagen de fondo
	startTexture.loadFromFile("assets/img/bgs/startScreenSS.png");
	this->startSprite.setTexture(startTexture);
	sf::IntRect rectSourceSprite(0, 0, 1500, 1000);
	this->startSprite.setTextureRect(rectSourceSprite);

	sf::Clock clock;

	// Ciclo de vida de la ventana de inicio
	while (startWindow.isOpen()) {
		processEvents();
		update();
		if (clock.getElapsedTime().asSeconds() > 0.10f) {
			if (rectSourceSprite.left == 10500) rectSourceSprite.left = 0;
			else rectSourceSprite.left += 1500;
			
			startSprite.setTextureRect(rectSourceSprite);
			clock.restart();
		}
		render();
	}	
	
}

void StartScreen::processEvents()
{
	sf::Event event;
	// Ciclo de escucha de eventos
	while (startWindow.pollEvent(event)) {

		switch (event.type) {
			// Cualquier tecla que se presione o si se pulsa el boton de cierre
			// se cierra la ventana
			case sf::Event::KeyPressed:
				cout << "Key code pressed: " << event.key.code << endl;
			case sf::Event::Closed:
				startWindow.close();
				break;

			default:
				break;
		}
		
		if (event.type == sf::Event::KeyPressed) {
			MenuScreen m;
			m.run();
		}
	}
	
}

void StartScreen::update()
{
	
}

void StartScreen::render()
{
	
	int num = rand() % 3;
	
	// clear section
	startWindow.clear();
	
	// draw section
	startWindow.draw(startSprite);
	startWindow.draw(welcomeTxt);
	if (num % 2 == 0) // Si es par que muestre el texto
		startWindow.draw(press2PlayTxt);

	// display section
	startWindow.display();
}

bool StartScreen::isOpen()
{
	return startWindow.isOpen();
}

void StartScreen::close()
{
	startWindow.close();
}

// Esta funcion debe ser modificada, con el fin de mostrar
// las imagenes en vez de texto, por mientras... esta el texto
void StartScreen::setText()
{
	//texto estatico
	welcomeTxt.setFont(font);
	welcomeTxt.setString("\tWelcome to \nGaoland's Adventures!");
	welcomeTxt.setCharacterSize(70);
	welcomeTxt.setFillColor(sf::Color::Black);
	// en X es el tamaño de la pantalla entre 3.8, para poder centrarlo ((1500/3.8) = 394.73)
	welcomeTxt.setPosition(sWidth / 3.8, 100);

	press2PlayTxt.setFont(font);
	press2PlayTxt.setString("Press any key to continue");
	press2PlayTxt.setCharacterSize(25);
	press2PlayTxt.setFillColor(sf::Color::Black);
	press2PlayTxt.setPosition(sWidth / 2.4, sHeight - 100);

}

double StartScreen::getSWidth()
{
	return this->sWidth;
}

double StartScreen::getSHeight()
{
	return this->sHeight;
}


