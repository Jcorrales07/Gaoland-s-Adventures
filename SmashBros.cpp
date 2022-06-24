#include "SmashBros.h"

SmashBros::SmashBros()
	: smashWindow(sf::VideoMode(1366, 768), "Smash Bros"), playerLife(5), enemyLife(5)
{
	run();
}

SmashBros::~SmashBros() = default;

void SmashBros::run()
{
	
	initResources();
	setUpAnimations();

	while (smashWindow.isOpen()) {
		
		deltaTime = this->deltaTimeTimer.restart().asSeconds();
		
		processEvents();
		update();

		if (isNotificationShown) renderNotification();
		else render();
		
	}

}

void SmashBros::initResources()
{
	isNotificationShown = true;
	deltaTime = 0.0f;
	loadTextures();
	loadQuestions();
	loadAnswers();
	loadFont();
	loadSounds();
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

		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
			isNotificationShown = false;
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

	if (playerLife == 0) {
		isNotificationShown = true;
		bgMusic.stop();
		notificationSprt.setTextureRect(sf::IntRect(1366, 0, 1366, 768));
	}
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

	//mario
	smashWindow.draw(marioSprtIdle);
	//smashWindow.draw(marioSprtDolido);
	//smashWindow.draw(marioSprtAtacando);
	//smashWindow.draw(marioSprtCorriendo);
	//smashWindow.draw(marioSprtCorriendoAtras);
	//smashWindow.draw(marioSprtCelebrando);

	//bowser
	smashWindow.draw(bowserSprtIdle);
	//smashWindow.draw(bowserSprtDolido);
	//smashWindow.draw(bowserSprtAtacando);
	//smashWindow.draw(bowserSprtCorriendo);
	//smashWindow.draw(bowserSprtCorriendoAtras);

	smashWindow.display();
}

void SmashBros::renderNotification()
{
	smashWindow.clear();

	smashWindow.draw(notificationSprt);

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

	setMarioTextures();

	setBowserTextures();

	if (!notificationTxt.loadFromFile("assets/img/bgs/notificacionesSmashBros.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (notificacionesSmashBros)" << std::endl;

	notificationSprt.setTexture(notificationTxt);
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
	scoretxt = "Score: " + std::to_string(score);
	scoreText.setString(scoretxt);
	scoreText.setPosition(654.51f, 40);
	scoreText.setFillColor(sf::Color::Black);
	
	//QUESTION
	question.setFont(font);
	question.setCharacterSize(25);
	question.setStyle(sf::Text::Bold);
	question.setPosition(213.44f, 102.77f);
	question.setFillColor(sf::Color::Black);
	question.setString("'Presiona la tecla A para iniciar el juego! Buena suerte!!'");

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

void SmashBros::setMarioTextures()
{

	if (!marioTxts[0].loadFromFile("assets/img/sprts/mario/marioIdle.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (mario)" << std::endl;

	marioSprtIdle.setTexture(marioTxts[0]);
	marioSprtIdle.setScale(1.2f, 1.2f);
	marioSprtIdle.setPosition(310, 370); // posicion de mario	( KAROL )

	if (!marioTxts[1].loadFromFile("assets/img/sprts/mario/marioDolido.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (mario)" << std::endl;

	marioSprtDolido.setTexture(marioTxts[1]);
	marioSprtDolido.setPosition(310, 370); // posicion de mario	( KAROL )

	if (!marioTxts[2].loadFromFile("assets/img/sprts/mario/marioAtacando.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (mario)" << std::endl;

	marioSprtAtacando.setTexture(marioTxts[1]);
	marioSprtAtacando.setPosition(310, 370); // posicion de mario	( KAROL )

	if (!marioTxts[3].loadFromFile("assets/img/sprts/mario/marioCorriendo.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (mario)" << std::endl;

	marioSprtCorriendo.setTexture(marioTxts[3]);
	marioSprtCorriendo.setPosition(310, 370); // posicion de mario	( KAROL )

	if (!marioTxts[4].loadFromFile("assets/img/sprts/mario/marioCorriendoAtras.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (mario)" << std::endl;

	marioSprtCorriendoAtras.setTexture(marioTxts[4]);
	marioSprtCorriendoAtras.setPosition(310, 370); // posicion de mario	( KAROL )

	if (!marioTxts[5].loadFromFile("assets/img/sprts/mario/marioCelebrando.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (mario)" << std::endl;

	marioSprtCelebrando.setTexture(marioTxts[5]);
	marioSprtCelebrando.setPosition(310, 370); // posicion de mario	( KAROL )

}

void SmashBros::setBowserTextures()
{

	if (!bowserTxts[0].loadFromFile("assets/img/sprts/bowser/bowserIdle.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (bowser)" << std::endl;

	bowserSprtIdle.setTexture(bowserTxts[0]);
	bowserSprtIdle.setPosition(930, 340); // posicion de bowser ( DANI )

	if (!bowserTxts[1].loadFromFile("assets/img/sprts/bowser/bowserDolido.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (bowser)" << std::endl;

	bowserSprtDolido.setTexture(bowserTxts[1]);
	bowserSprtDolido.setPosition(930, 340); // posicion de bowser ( DANI )

	if (!bowserTxts[2].loadFromFile("assets/img/sprts/bowser/bowserAtacando.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (bowser)" << std::endl;

	bowserSprtAtacando.setTexture(bowserTxts[2]);
	bowserSprtAtacando.setPosition(930, 340); // posicion de bowser ( DANI )

	if (!bowserTxts[3].loadFromFile("assets/img/sprts/bowser/bowserCorriendo.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (bowser)" << std::endl;

	bowserSprtCorriendo.setTexture(bowserTxts[3]);
	bowserSprtCorriendo.setPosition(930, 340); // posicion de bowser ( DANI )

	if (!bowserTxts[4].loadFromFile("assets/img/sprts/bowser/bowserCorriendoAtras.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (bowser)" << std::endl;

	bowserSprtCorriendoAtras.setTexture(bowserTxts[4]);
	bowserSprtCorriendoAtras.setPosition(930, 340); // posicion de bowser ( DANI )
}

void SmashBros::animIdleMario()
{
	marioIdle.update(0, deltaTime);
	marioSprtIdle.setTextureRect(marioIdle.uvRect);
}

void SmashBros::animHarmedMario()
{
	marioDolido.update(0, deltaTime);
	marioSprtDolido.setTextureRect(marioDolido.uvRect);
}

void SmashBros::animAttackMario()
{
	marioAtacando.update(0, deltaTime);
	marioSprtAtacando.setTextureRect(marioAtacando.uvRect);
}

void SmashBros::animRunMario()
{
	marioCorriendo.update(0, deltaTime);
	marioSprtCorriendo.setTextureRect(marioCorriendo.uvRect);
}

void SmashBros::animRunBackMario()
{
	marioCorriendo.update(0, deltaTime);
	marioSprtCorriendoAtras.setTextureRect(marioCorriendo.uvRect);
}

void SmashBros::animCelebrationMario()
{
	marioCelebrando.update(0, deltaTime);
	marioSprtCelebrando.setTextureRect(marioCelebrando.uvRect);
}

void SmashBros::attackMario()
{
	int x = 310;
	while (!marioSprtCorriendo.getGlobalBounds().intersects(bowserSprtIdle.getGlobalBounds())) {
		x++;

		marioSprtCorriendo.setPosition(x, 370);

	}


}

// BOWSER

void SmashBros::animIdleBowser()
{
	bowserIdle.update(0, deltaTime);
	bowserSprtIdle.setTextureRect(bowserIdle.uvRect);
}

void SmashBros::animHarmedBowser()
{
	bowserDolido.update(0, deltaTime);
	bowserSprtDolido.setTextureRect(bowserDolido.uvRect);
}

void SmashBros::animAttackBowser()
{
	bowserAtacando.update(0, deltaTime);
	bowserSprtAtacando.setTextureRect(bowserAtacando.uvRect);
}

void SmashBros::animRunBowser()
{
	bowserCorriendo.update(0, deltaTime);
	bowserSprtCorriendo.setTextureRect(bowserCorriendo.uvRect);
}

void SmashBros::animRunBackBowser()
{
	bowserCorriendoAtras.update(0, deltaTime);
	bowserSprtCorriendoAtras.setTextureRect(bowserCorriendoAtras.uvRect);
}

void SmashBros::setUpAnimations()
{
	marioIdle.setup(&marioTxts[0], sf::Vector2u(6, 1), 0.3f);
	marioDolido.setup(&marioTxts[1], sf::Vector2u(8, 1), 0.3f);
	marioAtacando.setup(&marioTxts[2], sf::Vector2u(10, 1), 0.3f);
	marioCorriendo.setup(&marioTxts[3], sf::Vector2u(8, 1), 0.3f);
	marioCorriendoAtras.setup(&marioTxts[4], sf::Vector2u(8, 1), 0.3f);
	marioCelebrando.setup(&marioTxts[5], sf::Vector2u(8, 1), 0.3f);


	bowserIdle.setup(&bowserTxts[0], sf::Vector2u(5, 1), 0.3f);
	bowserCorriendo.setup(&bowserTxts[1], sf::Vector2u(6, 1), 0.3f);
	bowserCorriendoAtras.setup(&bowserTxts[2], sf::Vector2u(6, 1), 0.3f);
	bowserAtacando.setup(&bowserTxts[3], sf::Vector2u(4, 1), 0.3f);
	bowserDolido.setup(&bowserTxts[4], sf::Vector2u(2, 1), 0.3f);
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

void SmashBros::loadSounds()
{
	if (!bgMusic.openFromFile("assets/sounds/nivel3/smBattleMusic.wav"))
		std::cerr << "ERROR: NO SE PUDO CARGAR EL SONIDO (smBattleMusic)" << std::endl;

	if (!bufferHit.loadFromFile("assets/sounds/nivel3/hit.wav"))
		std::cerr << "ERROR: NO SE PUDO CARGAR EL SONIDO (hit)" << std::endl;

	hitSound.setBuffer(bufferHit);

	if (!bufferWin.loadFromFile("assets/sounds/nivel3/win.wav"))
		std::cerr << "ERROR: NO SE PUDO CARGAR EL SONIDO (hit)" << std::endl;

	winSound.setBuffer(bufferWin);

	bgMusic.setVolume(50.f);
	bgMusic.play();

}

void SmashBros::disableNotification(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
		isNotificationShown = false;
}

void SmashBros::checkAnswers(sf::Event& event)
{
	if (index == 1) caseKey(event, sf::Keyboard::A);
	else if (index == 2 || index == 4)	caseKey(event, sf::Keyboard::B);
	else if (index == 3 || index == 5 || index == 6 || index == 7 || index == 8) caseKey(event, sf::Keyboard::C);
	
	reset();
}

void SmashBros::caseKey(sf::Event &event, int codeKey)
{
	if (event.type == sf::Event::KeyReleased && !(event.key.code == codeKey)) {
		hitSound.play();
		playerLife--;
		score -= (rand() % 2000);
	} else {
		winSound.play();
		enemyLife--;
		score += (rand() % 1900);
	}
}

void SmashBros::checkTime()
{
	if ((scsPassed == 10 && !isAnswered) && !isNotificationShown) {
		hitSound.play();
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
