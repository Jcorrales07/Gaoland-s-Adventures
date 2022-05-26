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
	this->questionIndex = 0;
	initFont();
	initTexture();
	putQuestInScreen("Presione la tecla A, B, C o D para iniciar\nDe su respuesta de la misma manera", sf::Color(0, 0, 0, 0.5));
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
	questionText.setFont(font);
	questionText.setCharacterSize(30);
	
}

void Ruleta::onSpacePressed(sf::Event& event)
{																					// si la ruleta no esta girando
	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (isSpinning == false)) { 
		btnSpaceSprt.setTextureRect(sf::IntRect(250, 0, 250, 150));
		isSpinning = true;
		this->stateNum = genRandomNum() + 1; // Genera un numero random del 1 al 4
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

void Ruleta::putQuestInScreen(string question, sf::Color color)
{
	questionText.setString(question);
	questionText.setStyle(sf::Text::Bold);
	questionText.setPosition(211.77f, 142.51f);
	questionBackground.setSize(sf::Vector2f(1000, 171.89f));
	questionBackground.setPosition(182.5f, 114.5f);
	questionBackground.setFillColor(color);
	questionBackground.setOutlineColor(sf::Color::Black);
	questionBackground.setOutlineThickness(2.0f);
}

void Ruleta::nextQuestion(vector<string> questions, vector<string> answers, sf::Color color, int index)
{
	putQuestInScreen(questions[index], color);
}

void Ruleta::onKeyAnswerPressed(sf::Event& event, vector<string> questions, vector<string> answers, sf::Color color)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::A ||
			event.key.code == sf::Keyboard::B || 
			event.key.code == sf::Keyboard::C ||
			event.key.code == sf::Keyboard::D) {
			
			if (questionIndex < questions.size()) 
				nextQuestion(questions, answers, color, questionIndex);
			
			questionIndex++;
		}
	}
}

void Ruleta::run()
{
	initWindow();
	
	//ANIMACION DE LA RULETA
	this->animation.setup(&ruletaTexture, sf::Vector2u(6, 1), 0.3f);
	this->boxAnimation.setup(&boxTexture, sf::Vector2u(3, 1), 0.25f);

	while (window.isOpen()) {
		
		//deltaTime para las animaciones
		this->deltaTime = this->timer.restart().asSeconds();
		
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

		//Tecla A || B || C || D presionada
		if (isArtThemeShown) onKeyAnswerPressed(event, art.getQuestions(), art.getAnswers(), sf::Color(118, 189, 209));
		else if (isPoliticsThemeShown) onKeyAnswerPressed(event, politics.getQuestions(), politics.getAnswers(), sf::Color(107, 136, 254));
		else if (isScienceThemeShown) onKeyAnswerPressed(event, science.getQuestions(), science.getAnswers(), sf::Color(0, 0, 0, 0.5));
		else if (isHistoryThemeShown) onKeyAnswerPressed(event, history.getQuestions(), history.getAnswers(), sf::Color(0, 0, 0, 0.5));
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
	window.draw(questionBackground);
	window.draw(questionText);
}

void Ruleta::renderPoliticsTheme()
{
	politics.setBackground(this->themesTextures, sf::IntRect(4098, 0, 1366, 768));
	politics.drawAt(window);
	window.draw(boxSprite);
	window.draw(questionBackground);
	window.draw(questionText);
}

void Ruleta::renderScienceTheme()
{
	science.setBackground(this->themesTextures, sf::IntRect(1366, 0, 1366, 768));
	science.drawAt(window);
	window.draw(boxSprite);
	window.draw(questionBackground);
	window.draw(questionText);
}

void Ruleta::renderHistoryTheme()
{
	history.setBackground(this->themesTextures, sf::IntRect(2732, 0, 1366, 768));
	history.drawAt(window);
	window.draw(boxSprite);
	window.draw(questionBackground);
	window.draw(questionText);
}

int Ruleta::genRandomNum()
{
	return rand() % 4;
}

void Ruleta::setStateTheme()
{
	if (stateNum == 1) {
		window.setTitle("Roulette - Art Questions");
		isArtThemeShown = true; 
		isRouletteShown = false;
		art.setArtQuestions();
		art.setArtAnswers();
	}
	else if (stateNum == 2) { 
		window.setTitle("Roulette - Politics Questions");
		isPoliticsThemeShown = true;
		isRouletteShown = false; 
		politics.setPoliticsQuestions();
		politics.setPoliticsAnswers();
	}
	else if (stateNum == 3) { 
		window.setTitle("Roulette - Science Questions");
		isScienceThemeShown = true;
		isRouletteShown = false;
		science.setScienceQuestions();
		science.setScienceAnswers();
	}
	else if (stateNum == 4) { 
		window.setTitle("Roulette - History Questions");
		isHistoryThemeShown = true;
		isRouletteShown = false; 
		history.setHistoryQuestions();
		history.setHistoryAnswers();
	}
}
