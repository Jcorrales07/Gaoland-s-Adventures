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
	window.create(sf::VideoMode(1366, 768), "Roulette");
	window.setFramerateLimit(60);
	this->isRouletteShown = true;
	this->questionIndex = 0;
	initFont();
	initTexture();
	putQuestInScreen("Presione la tecla A, B, C o D para iniciar\nDe su respuesta de la misma manera.\nNOTA: ud dispone de 120s para contestar!", sf::Color(0, 0, 0, 0.5));
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

	if(!notificationTxt.loadFromFile("assets/img/bgs/notificaciones.png"))
		cerr << "ERROR::COULDN'T LOAD THE NOTIFICATION TEXTURE" << endl;
	
	notificationSprt.setTexture(notificationTxt);
	gameOverSprt.setTexture(notificationTxt);

	if(!heartTxt.loadFromFile("assets/img/textures/hardcoreHeart2.png"))
		cerr << "ERROR::COULDN'T LOAD THE HEART TEXTURE" << endl;

	setUpHearts();
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
	setFont();
	
	timerTxt.setFont(font);
	timerTxt.setCharacterSize(36);
	timerTxt.setStyle(sf::Text::Bold);
	timerTxt.setFillColor(sf::Color::Black);
	timerTxt.setPosition(1105, 28);
}

void Ruleta::onSpacePressed(sf::Event& event)
{																					// si la ruleta no esta girando
	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (isSpinning == false)) { 
		btnSpaceSprt.setTextureRect(sf::IntRect(250, 0, 250, 150));
		isSpinning = true;
		this->stateNum = genRandomNum() + 1; // Genera un numero random del 1 al 4
		this->stateNum = 1; // quitar
		std::cout << "El numero es: " << this->stateNum << endl;
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
	if (isSpinning && this->clock.getElapsedTime().asSeconds() < 4) 
		animationRoulette();
}

void Ruleta::animationBox()
{
	boxAnimation.update(0, deltaTime);
	boxSprites[0].setTextureRect(boxAnimation.uvRect);
	boxSprites[1].setTextureRect(boxAnimation.uvRect);
	boxSprites[2].setTextureRect(boxAnimation.uvRect);
	boxSprites[3].setTextureRect(boxAnimation.uvRect);
}

void Ruleta::enterPressed(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
		isNotificationShown = false;

		//verificar que numero salio de forma random y asi mostrar las cosas 
		if (stateNum == 1) isArtThemeShown = true;
		else if (stateNum == 2) isPoliticsThemeShown = true;
		else if (stateNum == 3) isScienceThemeShown = true;
		else if (stateNum == 4) isHistoryThemeShown = true;
	}
}

void Ruleta::putQuestInScreen(string question, sf::Color color)
{
	questionText.setString(question);
	questionText.setStyle(sf::Text::Bold);
	questionText.setFillColor(sf::Color::Black);
	questionText.setPosition(211.77f, 142.51f);
	questionBackground.setSize(sf::Vector2f(1000, 171.89f));
	questionBackground.setPosition(182.5f, 114.5f);
	questionBackground.setFillColor(color);
	questionBackground.setOutlineColor(sf::Color::Black);
	questionBackground.setOutlineThickness(2.0f);
}

void Ruleta::setUpBoxesInScreen(sf::Color color)
{
	for (int i = 0; i < 4; i++) {
		answerBackground[i].setFillColor(color);
		answerBackground[i].setSize(sf::Vector2f(336, 60));
		answerBackground[i].setOutlineColor(sf::Color::Black);
		answerBackground[i].setOutlineThickness(3);
	}

	answerBackground[0].setPosition(183.5f, 450.5f);
	answerBackground[1].setPosition(183.5f, 550.5f);
	answerBackground[2].setPosition(845.5f, 450.5f);
	answerBackground[3].setPosition(845.5f, 550.5f);

	setUpAnimBoxes();
	boxSprites[0].setPosition(184, 450.5f);
	boxSprites[1].setPosition(184, 550.5f);
	boxSprites[2].setPosition(845.5f, 450.5f);
	boxSprites[3].setPosition(845.5f, 550.5f);
}

void Ruleta::putAnswersInScreen()
{
	if (questionIndex == 0) {
		answerText[0].setString(art.getAnswers().at(0));
		answerText[1].setString(art.getAnswers().at(1));
		answerText[2].setString(art.getAnswers().at(2));
		answerText[3].setString(art.getAnswers().at(3));
	}
	else if (questionIndex == 1) {
		answerText[0].setString(art.getAnswers().at(4));
		answerText[1].setString(art.getAnswers().at(5));
		answerText[2].setString(art.getAnswers().at(6));
		answerText[3].setString(art.getAnswers().at(7));
	}
	else if (questionIndex == 2) {
		answerText[0].setString(art.getAnswers().at(8));
		answerText[1].setString(art.getAnswers().at(9));
		answerText[2].setString(art.getAnswers().at(10));
		answerText[3].setString(art.getAnswers().at(11));
	}
	else if (questionIndex == 3) {
		answerText[0].setString(art.getAnswers().at(12));
		answerText[1].setString(art.getAnswers().at(13));
		answerText[2].setString(art.getAnswers().at(14));
		answerText[3].setString(art.getAnswers().at(15));
	}
	else if (questionIndex == 4) {
		answerText[0].setString(art.getAnswers().at(16));
		answerText[1].setString(art.getAnswers().at(17));
		answerText[2].setString(art.getAnswers().at(18));
		answerText[3].setString(art.getAnswers().at(19));
	}
}

void Ruleta::nextQuestion(vector<string> questions, vector<string> answers, sf::Color color, int index)
{
	putQuestInScreen(questions[index], color);
	setUpBoxesInScreen(color);
	putAnswersInScreen();
}

void Ruleta::onKeyAnswerPressed(sf::Event& event, vector<string> questions, vector<string> answers, sf::Color color)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::B || event.key.code == sf::Keyboard::C || event.key.code == sf::Keyboard::D) {
			

			if (questionIndex < questions.size()) {
				nextQuestion(questions, answers, color, questionIndex);
				checkAnswers(questionIndex, event);
			}
				cout << "questionIndex: " << questionIndex << endl;
				questionIndex++;
			
		}
	}
}

void Ruleta::setUpAnimBoxes()
{
	for (int i = 0; i < 4; i++)	{
		boxSprites[i].setTexture(boxTexture);
		boxSprites[i].setTextureRect(sf::IntRect(0, 0, 320, 320));
		boxSprites[i].setScale(0.2f, 0.2f);
	}
}

void Ruleta::drawAnimBoxes()
{
	for (int i = 0; i < 4; i++) 
		window.draw(boxSprites[i]);
}

void Ruleta::drawBgBoxes()
{
	for (int i = 0; i < 4; i++)
		window.draw(answerBackground[i]);
}

void Ruleta::setFont()
{
	for (int i = 0; i < 4; i++) {
		answerText[i].setFont(font);
		answerText[i].setCharacterSize(20);
		answerText[i].setStyle(sf::Text::Bold);
		answerText[i].setFillColor(sf::Color::Black);
	}

	answerText[0].setPosition(250, 465);
	answerText[1].setPosition(916, 465);
	answerText[2].setPosition(250, 565);
	answerText[3].setPosition(916, 565);
}

void Ruleta::drawAnsText()
{
	for (int i = 0; i < 4; i++)
		window.draw(answerText[i]);
}

void Ruleta::drawHearts(int lives)
{
	for (int i = 0; i < lives; i++) {
		window.draw(hearts[i]);
	}
}

void Ruleta::setUpHearts()
{
	for (int i = 0; i < 3; i++) {
		hearts[i].setTexture(heartTxt);
	}
	
	// posiciones de las vidas
	hearts[0].setPosition(30, 30);
	hearts[1].setPosition(80, 30);
	hearts[2].setPosition(130, 30);
	//hearts[3].setPosition(180, 30);
	//hearts[4].setPosition(230, 30);
}

void Ruleta::resetTimer()
{
	if (questionIndex == 0) {
		timeLeft.restart();
		timePassed = 0;
		timerTxt.setString("Time: " + std::to_string(timePassed) + "s");
	}
}

void Ruleta::increaseSeconds()
{
	if (this->timeLeft.getElapsedTime().asSeconds() > timePassed) {
		timePassed++;
		timerTxt.setString("Time: " + std::to_string(timePassed) + "s");
	}
}

void Ruleta::checkAnswers(int &index, sf::Event& event)
{
	//cout << "Current index: " << index << endl;
	if (index == 1 || index == 2 || index == 5) {
		if (event.type == sf::Event::KeyReleased && !(event.key.code == sf::Keyboard::A)) 
			decreaseLives();
		else cout << "Correct answer" << endl;
	} 
	else if (index == 3 || index == 4) {
		if (event.type == sf::Event::KeyReleased && !(event.key.code == sf::Keyboard::B)) 
			decreaseLives();
		else cout << "Correct answer" << endl;
	}
	cout << "Lives: " << lives << endl;
}

void Ruleta::decreaseLives()
{
	if (lives > 0)
		lives--;
}

void Ruleta::checkLimitTime()
{
	if (this->timeLeft.getElapsedTime().asSeconds() > 120)
		lives = 0;
}

void Ruleta::checkLives()
{
	if (lives == 0) {
		// poner bg que diga que perdio el juego
		cout << "El juego termino" << endl;
		gameOverSprt.setTextureRect(sf::IntRect(5464, 0, 1366, 768));
		window.draw(gameOverSprt);
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

void Ruleta::processEvents(){

	sf::Event event;

	while (window.pollEvent(event)) {

		// Close window: exit
		if (event.type == sf::Event::Closed)
			window.close();

		//Tecla space presionada
		onSpacePressed(event);
		
		//Tecla space soltada
		onSpaceReleased(event);

		// este es para quitar la notificar
		enterPressed(event);
		
		//Primer juego
		//Tecla A || B || C || D presionada
		if (isArtThemeShown) {
			vector<string> questions = art.getQuestions();
			vector<string> answers = art.getAnswers();
			sf::Color color = sf::Color(118, 189, 209);
			onKeyAnswerPressed(event, questions, answers, color);
		}
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
	if (isRouletteShown)			renderRoulette();
	else if (isNotificationShown)	renderNotification();
	else if (isArtThemeShown) {
		renderArtTheme();
		checkLimitTime();
		checkLives();
		increaseSeconds();
		resetTimer();
	}
	else if (isPoliticsThemeShown)	renderPoliticsTheme();
	else if (isScienceThemeShown)	renderScienceTheme();
	else if (isHistoryThemeShown)	renderHistoryTheme();
	
	window.display();
}

void Ruleta::renderRoulette()
{
	window.draw(bgSprite);
	window.draw(ruletaSprite);
	window.draw(btnSpaceSprt);
}

void Ruleta::renderNotification()
{

	if (stateNum == 1) {
		notificationSprt.setTextureRect(sf::IntRect(0, 0, 1366, 768));
		this->lives = 3;
		//cout << "Time passed on timeLeft: " << timeLeft.getElapsedTime().asSeconds() << endl;
		timeLeft.restart();
	}
	else if (stateNum == 2) 
		notificationSprt.setTextureRect(sf::IntRect(1366, 0, 1366, 768));
	else if (stateNum == 3) 
		notificationSprt.setTextureRect(sf::IntRect(2732, 0, 1366, 768));
	else if (stateNum == 4) 
		notificationSprt.setTextureRect(sf::IntRect(4098, 0, 1366, 768));

	window.draw(notificationSprt);
}

void Ruleta::renderArtTheme()
{
	art.setBackground(this->themesTextures, sf::IntRect(0, 0, 1366, 768));
	art.drawAt(window);
	drawHearts(lives);
	window.draw(questionBackground);
	window.draw(questionText);
	drawBgBoxes();
	drawAnimBoxes();
	drawAnsText();
	window.draw(timerTxt);
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
		window.setTitle("Roulette - Art Questions");
		isRouletteShown = false;
		art.setArtQuestions();
		art.setArtAnswers();
	}
	else if (stateNum == 2) { 
		window.setTitle("Roulette - Politics Questions");
		isRouletteShown = false; 
	}
	else if (stateNum == 3) { 
		window.setTitle("Roulette - Science Questions");
		isRouletteShown = false;
	}
	else if (stateNum == 4) { 
		window.setTitle("Roulette - History Questions");
		isRouletteShown = false; 
	}
}
