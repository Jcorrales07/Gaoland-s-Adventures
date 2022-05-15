#include "StartScreen.h"
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
	this->startWindow.setFramerateLimit(60);
}

StartScreen::~StartScreen()
{
	
}

void StartScreen::run()
{
	//Cargar los titulos
	initTitles();

	//Cargar el sprite de la imagen de fondo
	initBackground();

	sf::Clock clock;

	// Ciclo de vida de la ventana de inicio
	while (startWindow.isOpen()) {
		processEvents();
		update();
		
		if (clock.getElapsedTime().asSeconds() > 0.10f) {
			
			if (this->rectSourceSprite.left == 10500) this->rectSourceSprite.left = 1500;
			else this->rectSourceSprite.left += 1500;
			
			startSprite.setTextureRect(this->rectSourceSprite);
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

		if (event.type == sf::Event::KeyPressed) {
			startWindow.close();
			MenuScreen menuScreen;
		}
		else if (event.type == sf::Event::Closed) {
			startWindow.close();
		}
		
	}
	
}

void StartScreen::update()
{
	
}

void StartScreen::render()
{
	
	int num = rand() % 4;
	
	// clear section
	startWindow.clear();
	
	// draw section
	startWindow.draw(startSprite);
	startWindow.draw(titleSprite);
	if (num % 2 == 0) // Si es par que muestre el texto
		startWindow.draw(press2PlaySprite);

	// display section
	startWindow.display();
}

void StartScreen::initBackground()
{
	startTexture.loadFromFile("assets/img/bgs/startScreenSS.png");
	this->startSprite.setTexture(startTexture);
	this->rectSourceSprite.left = 0;
	this->rectSourceSprite.top = 0;
	this->rectSourceSprite.width = 1500;
	this->rectSourceSprite.height = 1000;
	this->startSprite.setTextureRect(rectSourceSprite);
}

void StartScreen::initTitles()
{
	if (!titleTexture.loadFromFile("Assets/img/titles/titleTextures.png"))
		cerr << "Error loading the titles texture" << endl;

	this->titleSprite.setTexture(titleTexture);
	this->titleSprite.setTextureRect(sf::IntRect(0, 0, 500, 250));
	// en X es el tamaño de la pantalla entre 3.8, para poder centrarlo ((1500/3.8) = 394.73)
	this->titleSprite.setPosition(sWidth / 3, 25);

	this->press2PlaySprite.setTexture(titleTexture);
	this->press2PlaySprite.setTextureRect(sf::IntRect(0, 250, 500, 150));
	press2PlaySprite.setPosition(sWidth / 3, sHeight - 250);
}

float StartScreen::getSWidth()
{
	return this->sWidth;
}

float StartScreen::getSHeight()
{
	return this->sHeight;
}


