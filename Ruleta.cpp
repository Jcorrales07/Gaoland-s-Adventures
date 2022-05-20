#include "Ruleta.h"
#include "iostream"

using std::cout;
using std::cerr;
using std::endl;

Ruleta::Ruleta()
{
	run();
}

Ruleta::~Ruleta()
{
}

void Ruleta::initWindow()
{
	window.create(sf::VideoMode(1366, 768), "Ruleta");
	window.setFramerateLimit(60);
	initFont();
	initTexture();
}

void Ruleta::initTexture()
{
	if (!texture.loadFromFile("assets/img/bgs/ruletaTexture.png"))
		cerr << "ERROR::COULDN'T LOAD THE TEXTURE" << endl;

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 512, 512));
	sprite.setPosition(512, 115);
}

void Ruleta::initFont()
{
	if(!font.loadFromFile("assets/fonts/OcrAExt.ttf"))
		cerr << "Error al cargar la fuente" << endl;

	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setString("Aca va la ruleta");
}

void Ruleta::run()
{
	initWindow();

	while (window.isOpen()) {
		
		processEvents();
		render();
	
	}

}

void Ruleta::processEvents()
{
	sf::Event event;

	while (window.pollEvent(event)) {

		if (event.type == sf::Event::Closed)
			window.close();

	}
}

void Ruleta::render()
{
	window.clear();

	//Draw section
	window.draw(text);
	window.draw(sprite);

	window.display();
}
