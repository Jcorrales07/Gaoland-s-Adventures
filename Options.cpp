#include "Options.h"
#include "iostream"

using std::cout;
using std::endl;
using std::cerr;

Options::Options()
{
	
}

Options::~Options()
{
}

void Options::initWindow()
{
	this->optionsWindow.create(sf::VideoMode(1500, 1000), "Opciones");
	this->optionsWindow.setFramerateLimit(144);
	this->OWidth = optionsWindow.getSize().x;
	this->OHeight = optionsWindow.getSize().y;
	this->optionsWindow.setFramerateLimit(60);
	this->initText();
}

void Options::run()
{
	initWindow();

	while (optionsWindow.isOpen()) {

		processEvents();
		update();
		render();
		
	}
	
}

void Options::processEvents()
{
	sf::Event event;
	// Ciclo de escucha de eventos
	while (optionsWindow.pollEvent(event)) {

		 if (event.type == sf::Event::Closed) {
			optionsWindow.close();
		 }
		 else if (event.type == sf::Event::KeyPressed && 
			 event.key.code == sf::Keyboard::O) {
			
		 }
	}
}

void Options::update()
{
	
}

void Options::render()
{
	optionsWindow.clear(sf::Color(7, 0, 45, 255)); //Color: Azul oscuro

	//Draw section
	optionsWindow.draw(musicVolTxt);

	optionsWindow.display();

}

float Options::getOWidth()
{
	return this->OWidth;
}

float Options::getOHeight()
{
	return this->OHeight;
}

void Options::initText()
{
	if (!font.loadFromFile("Assets/fonts/OcrAExt.ttf"))
		cerr << "Error loading font" << endl;
	
	//Texts
	musicVolTxt.setFont(font);
	musicVolTxt.setString("Music Volume");
	musicVolTxt.setFillColor(sf::Color::White);
	musicVolTxt.setCharacterSize(70);
	musicVolTxt.setPosition(float(OWidth - 1400), 100);

}

void Options::setMusicVolTo(float musicVol)
{
	cout << "Music volume set to: " << musicVol << endl;
	musicVol = musicVol + 1; 
	cout << "Actual Music volume: " << musicVol << endl;
}









