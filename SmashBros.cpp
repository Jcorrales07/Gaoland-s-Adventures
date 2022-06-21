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
	loadAnswers();
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
				setAnsForQuestionNumber(index);
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
		reset();
		timerSeconds.setString(std::to_string(scsPassed) + "s");
	} 

	checkTime();
	increaseSeconds();
	resetSeconds();

	updateScore();
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
	drawAnsText();

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
	marioSprt.setPosition(310, 370); // posicion de mario	( KAROL )
	
	if (!bowserTxt.loadFromFile("assets/img/sprts/bowserSprt.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (bowser)" << std::endl;
	
	bowserSprt.setTexture(bowserTxt);
	bowserSprt.setPosition(930, 340); // posicion de bowser ( DANI )

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

	setupAnswers();
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

void SmashBros::reset()
{
	time.restart();
	scsPassed = 0;
	isAnswered = false;
}

void SmashBros::updateScore()
{
	scoretxt = "Score: " + std::to_string(score);
	scoreText.setString(scoretxt);
}

void SmashBros::checkAnswers(sf::Event& event)
{
	if (index == 1) caseKey(event, sf::Keyboard::A);
	else if (index == 2 || index == 4)	caseKey(event, sf::Keyboard::B);
	else if ( index == 3 || index == 5 || index == 6 || index == 7 || index == 8) caseKey(event, sf::Keyboard::C);
	
	reset();
}

void SmashBros::caseKey(sf::Event &event, int codeKey)
{
	if (event.type == sf::Event::KeyReleased && !(event.key.code == codeKey)) {
		playerLife--;
		score -= (rand() % 2000);
	} else {
		enemyLife--;
		score += (rand() % 1900);
	}
}

void SmashBros::checkTime()
{
	if (scsPassed == 10 && !isAnswered) {
		playerLife--;
		isAnswered = true;
	}
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
	this->questions.push_back("		Terminaste las preguntas!!!");
}

void SmashBros::setupAnswers()
{
	for (int i = 0; i < 4; i++) {
		answer[i].setFont(font);
		answer[i].setCharacterSize(25);
		answer[i].setFillColor(sf::Color::Black);
		answer[i].setStyle(sf::Text::Bold);
	}
	
	answer[0].setPosition(400, 160);
	answer[1].setPosition(400, 190);
	answer[2].setPosition(790, 160);
	answer[3].setPosition(790, 190);
}

void SmashBros::loadAnswers()
{
	answers.push_back("A) Empiristas");
	answers.push_back("B) Criticistas");
	answers.push_back("C) Racionalistas");
	answers.push_back("D) Dogmáticos");
	
	answers.push_back("A) Racionalistas");
	answers.push_back("B) Empiristas");
	answers.push_back("C) Escolásticos");
	answers.push_back("D) Escépticos");
	
	answers.push_back("A) Epistemólogos");
	answers.push_back("B) Racionalistas");
	answers.push_back("C) Empiristas");
	answers.push_back("D) Escépticos");
	
	answers.push_back("A) Epistemólogos");
	answers.push_back("B) Racionalistas");
	answers.push_back("C) Empiristas");
	answers.push_back("D) Escépticos");
	
	answers.push_back("A) Empiristas");
	answers.push_back("B) Idealistas");
	answers.push_back("C) Racionalistas");
	answers.push_back("D) Innatistas");
	
	answers.push_back("A) David Hume");
	answers.push_back("B) John Locke");
	answers.push_back("C) Nicolas Malebranch");
	answers.push_back("D) Francis Bacon");
	
	answers.push_back("A) Empirismo");
	answers.push_back("B) Criticismo");
	answers.push_back("C) Racionalismo");
	answers.push_back("D) Epistemología");
	
	answers.push_back("A) George Berkeley");
	answers.push_back("B) David Hume");
	answers.push_back("C) Leibniz");
	answers.push_back("D) Hipatía");
}

void SmashBros::setAnsForQuestionNumber(int index)
{
	if (index == 0) {
		answer[0].setString(answers.at(0));
		answer[1].setString(answers.at(1));
		answer[2].setString(answers.at(2));
		answer[3].setString(answers.at(3));
	}
	else if (index == 1) {
		answer[0].setString(answers.at(4));
		answer[1].setString(answers.at(5));
		answer[2].setString(answers.at(6));
		answer[3].setString(answers.at(7));

		answer[0].setPosition(400, 190);
		answer[1].setPosition(400, 220);
		answer[2].setPosition(790, 190);
		answer[3].setPosition(790, 220);
	}
	else if (index == 2) {
		answer[0].setString(answers.at(8));
		answer[1].setString(answers.at(9));
		answer[2].setString(answers.at(10));
		answer[3].setString(answers.at(11));

		answer[0].setPosition(400, 160);
		answer[1].setPosition(400, 190);
		answer[2].setPosition(790, 160);
		answer[3].setPosition(790, 190);
	}
	else if (index == 3) {
		answer[3].setString(answers.at(12));
		answer[2].setString(answers.at(13));
		answer[1].setString(answers.at(14));
		answer[0].setString(answers.at(15));
	}
	else if (index == 4) {
		answer[0].setString(answers.at(16));
		answer[1].setString(answers.at(17));
		answer[2].setString(answers.at(18));
		answer[3].setString(answers.at(19));
	}
	else if (index == 5) {
		answer[0].setString(answers.at(20));
		answer[1].setString(answers.at(21));
		answer[2].setString(answers.at(22));
		answer[3].setString(answers.at(23));
	}
	else if (index == 6) {
		answer[0].setString(answers.at(24));
		answer[1].setString(answers.at(25));
		answer[2].setString(answers.at(26));
		answer[3].setString(answers.at(27));
	}
	else if (index == 7) {
		answer[0].setString(answers.at(28));
		answer[1].setString(answers.at(29));
		answer[2].setString(answers.at(30));
		answer[3].setString(answers.at(31));
	}
	else for (int i = 0; i < 4; i++) answer[i].setString("");
}

void SmashBros::drawAnsText()
{
	for (int i = 0; i < 4; i++) 
		smashWindow.draw(answer[i]);
}
