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
	this->isRouletteShown = true;
	initFont();
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
	if (!ruletaTexture.loadFromFile("assets/img/textures/ruletaTexture.png"))
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
}

void Ruleta::onSpacePressed(sf::Event& event)
{																						// si la ruleta no esta girando
	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (isSpinning == false)) { 
		btnSpaceSprt.setTextureRect(sf::IntRect(250, 0, 250, 150));
		isSpinning = true;
		//Gen a number
		this->stateNum = genRandomNum() + 1;
		std::cout << "El numero es: " << this->stateNum << endl;
	}
}

void Ruleta::onSpaceReleased(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
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
		this->isSpinning = false;
		this->clock.restart();
		setStateTheme();
	}
}

void Ruleta::spinRoulette()
{
	if (isSpinning && this->clock.getElapsedTime().asSeconds() < 4) {
		updateRoulette();
	} 
}

void Ruleta::run()
{
	initWindow();
	
	//ANIMACION DE LA RULETA
	this->animation.setup(&ruletaTexture, sf::Vector2u(6, 1), 0.3f);

	while (window.isOpen()) {
		
		//deltaTime para las animaciones
		this->deltaTime = this->timer.restart().asSeconds();
		//std::cout << "Time passed: " << clock.getElapsedTime().asSeconds() << endl;
		
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
	
	// draw section
	if (isRouletteShown) renderRoulette();
	else if (isArtThemeShown) renderArtTheme();
	else if (isScienceThemeShown) renderScienceTheme();
	else if (isHistoryThemeShown) renderHistoryTheme();
	else if (isPoliticsThemeShown) renderPoliticsTheme();
	
	std::cout << "r art     : " << (isArtThemeShown == true) << endl;
	std::cout << "r science : " << (isScienceThemeShown == true) << endl;
	std::cout << "r history : " << (isHistoryThemeShown == true) << endl;
	std::cout << "r politics: " << (isPoliticsThemeShown == true) << endl;
	
	window.display();
}

void Ruleta::renderRoulette()
{
	window.draw(bgSprite);
	window.draw(ruletaSprite);
	window.draw(btnSpaceSprt);
}

void Ruleta::renderArtTheme()
{
	text.setString("Art");
	text.setPosition(100, 100);
	window.draw(text);
}

void Ruleta::renderScienceTheme()
{
	text.setString("Science");
	text.setPosition(300, 100);
	window.draw(text);
}

void Ruleta::renderHistoryTheme()
{
	text.setString("History");
	text.setPosition(500, 100);
	window.draw(text);
}

void Ruleta::renderPoliticsTheme()
{
	text.setString("Politics");
	text.setPosition(700, 100);
	window.draw(text);
}

int Ruleta::genRandomNum()
{
	return rand() % 4;
}

void Ruleta::setStateTheme()
{
	if (stateNum == 1) isArtThemeShown = true;
	else if (stateNum == 2) isScienceThemeShown = true;
	else if (stateNum == 3) isHistoryThemeShown = true;
	else if (stateNum == 4) {
		isPoliticsThemeShown = true;
		isHistoryThemeShown = false;
	}
	isRouletteShown = false;
}
