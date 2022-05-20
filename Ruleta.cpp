#include "Ruleta.h"
#include "Animation.h"



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
	rectSourceSprite.left = 0;
	rectSourceSprite.top = 0;
	rectSourceSprite.width = 512;
	rectSourceSprite.height = 512;
	ruletaSprite.setTextureRect(rectSourceSprite);
	ruletaSprite.setPosition(512, 266);
	ruletaSprite.setScale(0.7f, 0.7f);

	//hacer animacion de la ruleta

	//btn Space
	if(!btnSpaceTxt.loadFromFile("assets/img/btns/spaceTexture.png"))
		cerr << "ERROR::COULDN'T LOAD THE SPACE TEXTURE" << endl;

	btnSpaceSprt.setTexture(btnSpaceTxt);
	btnSpaceSprt.setTextureRect(sf::IntRect(0, 0, 250, 150));
	btnSpaceSprt.setPosition(1046, 516);
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

void Ruleta::onSpacePressed(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::Space) {
		btnSpaceSprt.setTextureRect(sf::IntRect(250, 0, 250, 150));
		isSpinning = true;
		clock;
	}
}

void Ruleta::onSpaceReleased(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased &&
		event.key.code == sf::Keyboard::Space) {
		btnSpaceSprt.setTextureRect(sf::IntRect(0, 0, 250, 150));
	}
}

void Ruleta::updateRoulette()
{
	animation.update(0, deltaTime);
	ruletaSprite.setTextureRect(animation.uvRect);
}

void Ruleta::resetClock()
{
	if (this->clock.getElapsedTime().asSeconds() > 5) {
		this->clock.restart();
		this->isSpinning = false;
	}
}

void Ruleta::spinRoulette()
{
	if (isSpinning && this->clock.getElapsedTime().asSeconds() < 4)
		updateRoulette();
}

void Ruleta::run()
{
	initWindow();
	
	//ANIMACION DE LA RULETA
	this->animation.setup(&ruletaTexture, sf::Vector2u(6, 1), 0.3f);

	while (window.isOpen()) {
		
		//deltaTime para las animaciones
		this->deltaTime = this->timer.restart().asSeconds();
		std::cout << "Time passed: " << clock.getElapsedTime().asSeconds() << endl;
		
		processEvents();
		update();
		render();
	}

}

void Ruleta::processEvents()
{
	sf::Event event;

	while (window.pollEvent(event)) {

		// Close window: exit
		if (event.type == sf::Event::Closed)
			window.close();

		//Tecla space presionada
		onSpacePressed(event);
		
		//Tecla space soltada
		onSpaceReleased(event);
	}
}

void Ruleta::update()
{
	resetClock();
	spinRoulette();
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
