#include "SmashBros.h"

SmashBros::SmashBros()
	: smashWindow(sf::VideoMode(1366, 768), "Smash Bros"), playerLife(5), enemyLife(5)
{
	run();
}

SmashBros::~SmashBros() {}

void SmashBros::run()
{
	
	initResources();
	setUpAnimations();

	while (smashWindow.isOpen()) {
		
		deltaTime = this->deltaTimeTimer.restart().asSeconds();
		
		processEvents();
		update();
		render();
		
	}

}

void SmashBros::initResources()
{
	deltaTime = 0.0f;
	loadTextures();
	loadQuestions();
	loadFont();
}

void SmashBros::processEvents()
{
	
	sf::Event event;
	
	while (smashWindow.pollEvent(event)) {
		
		//cerrar la ventana
		if (event.type == sf::Event::Closed) {
			smashWindow.close();
		}

		if (
			event.type == sf::Event::KeyReleased && 
			(event.key.code == sf::Keyboard::A ||
			event.key.code == sf::Keyboard::B  ||
			event.key.code == sf::Keyboard::C  ||
			event.key.code == sf::Keyboard::D)
		) {
			
			if (index < questions.size()) {
				question.setString(questions.at(index));
				isAnswered = false;
				checkAnswers(event);
			} else std::cout << "Ya no hay preguntas" << std::endl;
			
			index++;
		} 
	}

}

void SmashBros::update() 
{
	animIdleMario();
	animIdleBowser();

	if (index == 0) {
		isAnswered = false;
		time.restart();
		scsPassed = 0;
		timerSeconds.setString(std::to_string(scsPassed) + "s");
	} 

	checkTime();
	increaseSeconds();
	resetSeconds();
}

void SmashBros::render()
{
	
	smashWindow.clear();

	// draw section
	smashWindow.draw(backgroundSprite);
	
	//dibujar las vidas de los jugadores
	drawLives(playerLife, heartsPlayer);
	drawLives(enemyLife, heartsEnemy);

	//dibujar texto
	smashWindow.draw(timerSeconds);
	smashWindow.draw(question);
	smashWindow.draw(scoreText);

	//Sprites
	smashWindow.draw(marioSprt);
	smashWindow.draw(bowserSprt);

	smashWindow.display();
	
}

void SmashBros::loadTextures()
{

	if (!backgroundTexture.loadFromFile("assets/img/bgs/finalDestinationBg.jpg")) 
		std::cerr << "ERROR:: no se pudo cargar la textura (bg)" << std::endl;

	backgroundSprite.setTexture(backgroundTexture);
	
	if (!heartTexture.loadFromFile("assets/img/textures/hardcoreHeart2.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (hearts)" << std::endl;
		
	setUpHeartSprites();

	if (!marioTxt.loadFromFile("assets/img/sprts/marioSprt.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (mario)" << std::endl;
	
	marioSprt.setTexture(marioTxt);
	marioSprt.setScale(1.2f, 1.2f);
	marioSprt.setPosition(310, 370); // posicion de mario (KAROL)
	
	if (!bowserTxt.loadFromFile("assets/img/sprts/bowserSprt.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (bowser)" << std::endl;
	
	bowserSprt.setTexture(bowserTxt);
	bowserSprt.setPosition(930, 340); // posicion de bowser (DANI)

}

void SmashBros::loadFont()
{
	
	if (!font.loadFromFile("assets/fonts/OcrAExt.ttf"))
		std::cerr << "Error al cargar la fuente" << std::endl;

	// set up text
	//TIMER
	timerSeconds.setFont(font);
	timerSeconds.setCharacterSize(30);
	timerSeconds.setStyle(sf::Text::Bold);
	
	timerSeconds.setString("0s");
	timerSeconds.setPosition(544.94f, 40);
	timerSeconds.setFillColor(sf::Color::Black);

	//SCORE
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	scoreText.setStyle(sf::Text::Bold);
	string scoretxt = "Score: " + std::to_string(score);
	scoreText.setString(scoretxt);
	scoreText.setPosition(654.51f, 40);
	scoreText.setFillColor(sf::Color::Black);
	
	//QUESTION
	question.setFont(font);
	question.setCharacterSize(25);
	question.setStyle(sf::Text::Bold);
	question.setPosition(213.44f, 102.77f);
	question.setFillColor(sf::Color::Black);
	question.setString("'Instructions'");
}

void SmashBros::setUpHeartSprites()
{
	
	for (int i = 0; i < 5; i++) {
		heartsPlayer[i].setTexture(heartTexture);
		heartsEnemy[i].setTexture(heartTexture);
	}

	//posiciones
	heartsPlayer[0].setPosition(50 * 1, 30);
	heartsPlayer[1].setPosition(50 * 2, 30);
	heartsPlayer[2].setPosition(50 * 3, 30);
	heartsPlayer[3].setPosition(50 * 4, 30);
	heartsPlayer[4].setPosition(50 * 5, 30);

	heartsEnemy[0].setPosition(1056, 30);
	heartsEnemy[1].setPosition(1106, 30);
	heartsEnemy[2].setPosition(1156, 30);
	heartsEnemy[3].setPosition(1206, 30);
	heartsEnemy[4].setPosition(1256, 30);
	
}

void SmashBros::drawLives(int amountLife, sf::Sprite hearts[])
{
	for (int i = 0; i < amountLife; i++)
		smashWindow.draw(hearts[i]);
}

void SmashBros::animIdleMario()
{
	marioIdle.update(0, deltaTime);
	marioSprt.setTextureRect(marioIdle.uvRect);
}

void SmashBros::animIdleBowser()
{
	bowserIdle.update(0, deltaTime);
	bowserSprt.setTextureRect(bowserIdle.uvRect);
}

void SmashBros::loadQuestions()
{
	this->questions.push_back("1. Para algunos de los siguientes filósofos, el criterio de\nverdad es la evidencia sensible: ");
	this->questions.push_back("2. De las siguientes, una de ellas es la corriente filosófica\nque en general tiende a negar la posibilidad de la metafísica\ny a sostener que hay conocimiento únicamente de los fenómenos: ");
	this->questions.push_back("	 3. Para unos de los siguientes filósofos, la\n	 experiencia como única fuente del conocimiento: ");
	this->questions.push_back("		4. Filósofos para quienes la única fuente del\n				conocimiento es la razón: ");
	this->questions.push_back("  5. Filósofos que postulan las ideas innatas en el sujeto: ");
	this->questions.push_back("		6. De los siguientes filósofos selecciones\n			el que no se considera Racionalista: ");
	this->questions.push_back("		7. Es la doctrina que establece que todo\n		nuestros conocimientos provienen de la razón: ");
	this->questions.push_back("		8. Uno de los siguientes filósofos, postula\n			  las ideas innatas en el sujeto: ");
}

void SmashBros::setUpAnimations()
{
	marioIdle.setup(&marioTxt, sf::Vector2u(6, 1), 0.3f);
	bowserIdle.setup(&bowserTxt, sf::Vector2u(5, 1), 0.3f);
}

void SmashBros::increaseSeconds()
{
	if (!(index == 0) && time.getElapsedTime().asSeconds() > scsPassed) {
		scsPassed++;
		timerSeconds.setString(std::to_string(scsPassed) + "s");
	}
}

void SmashBros::resetSeconds()
{
	if (scsPassed >= 11) {
		time.restart();
		scsPassed = 0;
		isAnswered = false;
	} 
}

void SmashBros::checkAnswers(sf::Event& event)
{
	if (index == 1) caseKey(event, sf::Keyboard::A);
	else if (index == 2 || index == 4)	caseKey(event, sf::Keyboard::B);
	else if ( index == 3 || index == 5 || index == 6 || index == 7 || index == 8) caseKey(event, sf::Keyboard::C);
	
	time.restart();
	scsPassed = 0;
	isAnswered = false;
}

void SmashBros::caseKey(sf::Event &event, int codeKey)
{
	if (event.type == sf::Event::KeyReleased && !(event.key.code == codeKey)) playerLife--;
	else enemyLife--;
}

void SmashBros::checkTime()
{
	if (scsPassed == 10 && !isAnswered) {
		playerLife--;
		isAnswered = true;
	}
}
