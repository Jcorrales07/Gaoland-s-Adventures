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
	ruletaSprite.setTextureRect(sf::IntRect(0, 0, 512, 512));
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

	//backgrounds de los campos
	if(!themesTextures.loadFromFile("assets/img/bgs/themes.png"))
		cerr << "ERROR::COULDN'T LOAD THE THEMES TEXTURE" << endl;

	if(!boxTexture.loadFromFile("assets/img/textures/misteryBoxTexture.png"))
		cerr << "ERROR::COULDN'T LOAD THE BOX TEXTURE" << endl;

	boxSprite.setTexture(boxTexture);
	boxSprite.setTextureRect(sf::IntRect(0, 0, 320, 320));
	boxSprite.setPosition(100, 100);
	boxSprite.setScale(0.18f, 0.18f);
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
{																					// si la ruleta no esta girando
	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (isSpinning == false)) { 
		btnSpaceSprt.setTextureRect(sf::IntRect(250, 0, 250, 150));
		isSpinning = true;
		//this->stateNum = genRandomNum() + 1; // Genera un numero random del 1 al 4
		this->stateNum = 1;
		//std::cout << "El numero es: " << this->stateNum << endl;
	}
}

void Ruleta::onSpaceReleased(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
		btnSpaceSprt.setTextureRect(sf::IntRect(0, 0, 250, 150));
	}
}

void Ruleta::animationRoulette()
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
		animationRoulette();
	} 
}

void Ruleta::animationBox()
{
	boxAnimation.update(0, deltaTime);
	boxSprite.setTextureRect(boxAnimation.uvRect);
}

void Ruleta::putQuestInScreen()
{
	questionText.setString("3. Antes de la consolidación del estado moderno, Italia estuvo divida en pequeñas ciudades-estado normalmente enfrentadas entre si, como es el caso de : ");
	backgroundRect = questionText.getLocalBounds();
	questionBackground.setSize(sf::Vector2f(backgroundRect.width, backgroundRect.height));
	questionBackground.setPosition(221.5f, 114.5f);
	questionBackground.setFillColor(sf::Color::Red);
}

void Ruleta::run()
{
	initWindow();
	//putQuestInScreen();
	
	//ANIMACION DE LA RULETA
	this->animation.setup(&ruletaTexture, sf::Vector2u(6, 1), 0.3f);
	this->boxAnimation.setup(&boxTexture, sf::Vector2u(3, 1), 0.25f);

	while (window.isOpen()) {
		
		//deltaTime para las animaciones
		this->deltaTime = this->timer.restart().asSeconds();
		//std::cout << "Time passed: " << clock.getElapsedTime().asSeconds() << endl;
		
		processEvents();
		update();
		animationBox();
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
	else if (isPoliticsThemeShown) renderPoliticsTheme();
	else if (isScienceThemeShown) renderScienceTheme();
	else if (isHistoryThemeShown) renderHistoryTheme();
	
	//std::cout << "isRouletteShown: " << (isRouletteShown == true) << endl;
	//std::cout << "r art     : " << (isArtThemeShown == true) << endl;
	//std::cout << "r science : " << (isScienceThemeShown == true) << endl;
	//std::cout << "r history : " << (isHistoryThemeShown == true) << endl;
	//std::cout << "r politics: " << (isPoliticsThemeShown == true) << endl;
	
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
	art.setBackground(this->themesTextures, sf::IntRect(0, 0, 1366, 768));
	art.drawAt(window);
	window.draw(boxSprite);
	
	questionText.setFont(font);
	questionText.setString("  3. Antes de la consolidación del estado moderno,\n Italia estuvo divida en pequeñas ciudades-estado\n normalmente enfrentadas entre si, como es el caso \nde : ");
	questionText.setCharacterSize(30);
	questionText.setPosition(236, 139.73f);
	questionBackground.setSize(sf::Vector2f(950, 171.89f));
	questionBackground.setFillColor(sf::Color(150, 150, 150));
	questionBackground.setPosition(221.5f, 114.5f);
	
	window.draw(questionBackground);
	window.draw(questionText);
}

void Ruleta::renderPoliticsTheme()
{
	politics.setBackground(this->themesTextures, sf::IntRect(4098, 0, 1366, 768));
	politics.drawAt(window);
}

void Ruleta::renderScienceTheme()
{
	science.setBackground(this->themesTextures, sf::IntRect(1366, 0, 1366, 768));
	science.drawAt(window);
}

void Ruleta::renderHistoryTheme()
{
	history.setBackground(this->themesTextures, sf::IntRect(2732, 0, 1366, 768));
	history.drawAt(window);
}

int Ruleta::genRandomNum()
{
	return rand() % 4;
}

void Ruleta::setStateTheme()
{
	if (stateNum == 1) {
		isArtThemeShown = true; 
		isRouletteShown = false;
		art.setArtQuestions();
		art.setArtAnswers();
	}
	else if (stateNum == 2) { 
		isPoliticsThemeShown = true;
		isRouletteShown = false;  
		politics.setArtQuestions();
		politics.setArtAnswers();
	}
	else if (stateNum == 3) { 
		isScienceThemeShown = true;
		isRouletteShown = false;
		science.setArtQuestions();
		science.setArtAnswers();
	}
	else if (stateNum == 4) { 
		isHistoryThemeShown = true;
		isRouletteShown = false; 
		history.setArtQuestions();
		history.setArtAnswers();
	}
}
