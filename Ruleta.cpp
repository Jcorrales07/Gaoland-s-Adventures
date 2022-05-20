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
	//initFont();
	initTexture();
}

void Ruleta::initTexture()
{
	//background
	if(!bgTexture.loadFromFile("assets/img/bgs/bgMarioTexture.png"))
		cerr << "ERROR::COULDN'T LOAD THE BG TEXTURE" << endl;

	bgSprite.setTexture(bgTexture);
	bgSprite.setTextureRect(sf::IntRect(500, 0, 500, 250));
	bgSprite.setScale(2.73f, 3.07f); // que se adapte a la pantalla

	//ruleta
	if (!ruletaTexture.loadFromFile("assets/img/bgs/ruletaTexture.png"))
		cerr << "ERROR::COULDN'T LOAD THE ROULETTE TEXTURE" << endl;
	
	ruletaTexture.setSmooth(true);

	ruletaSprite.setTexture(ruletaTexture);
	ruletaSprite.setTextureRect(sf::IntRect(0, 0, 512, 512));
	ruletaSprite.setPosition(512, 115);
	ruletaSprite.setScale(0.5f, 0.5f);

	//hacer animacion de la ruleta

	//btn Space
	if(!btnSpaceTxt.loadFromFile("assets/img/btns/spaceTexture.png"))
		cerr << "ERROR::COULDN'T LOAD THE SPACE TEXTURE" << endl;

	btnSpaceSprt.setTexture(btnSpaceTxt);
	btnSpaceSprt.setTextureRect(sf::IntRect(0, 0, 250, 150));
	btnSpaceSprt.setScale(0.7f, 0.7f);
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
	window.draw(bgSprite);
	window.draw(ruletaSprite);
	window.draw(btnSpaceSprt);

	window.display();
}
