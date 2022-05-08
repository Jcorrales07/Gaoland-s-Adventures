#include "StartScreen.h"
#include "SFML/Graphics.hpp"
#include "iostream"

using std::cout;
using std::endl;

StartScreen::StartScreen() 
	: startWindow(sf::VideoMode(1500, 1000), "Welcome")
{
	startWindow.setFramerateLimit(60);
	
	//Cargar la fuente para el texto
	if (!font.loadFromFile("assets/fonts/OcrAExt.ttf"))
		std::cerr << "Error loading font" << std::endl;
}

StartScreen::~StartScreen()
{
	
}

void StartScreen::run()
{
	double screenX = startWindow.getSize().x;
	double screenY = startWindow.getSize().y;
	
	this->background.setSize(sf::Vector2f(screenX, screenY));
	this->startTexture.loadFromFile("assets/img/bgs/pantallaPrincipal.gif");
	this->background.setTexture(&startTexture);

	// hacer funcion que carge el font para el texto

	// Ciclo de vida de la ventana de inicio
	while (startWindow.isOpen()) {
		processEvents();
		update();
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
	}
	
	if (event.type == sf::Event::KeyPressed) {
		cout << "menu" << endl;
	}
}

void StartScreen::update()
{
	
}

void StartScreen::render()
{
	startWindow.clear();
	startWindow.draw(background);
	startWindow.display();
}


