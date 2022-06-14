#include "MarioKart.h"
#include "iostream"
#include "BadCar.h"

using std::cerr;
using std::cout;
using std::endl;


MarioKart::MarioKart() {
    run();
}

MarioKart::~MarioKart() {

}

void MarioKart::run() {
    initWindow();
    initText();
    initTextures();
    initCar();

    sf::Clock clock;
    while (gameWindow.isOpen()) {

        processEvents();
        procesarColiciones();
        //update();

        // animacion de la carretera
        if (clock.getElapsedTime().asSeconds() > 0.600f) {

            if (this->roadRect.top == 768 * 2) this->roadRect.top = 0;
            else roadRect.top += 768;

            this->roadSprite.setTextureRect(roadRect);
            clock.restart();
        }


        render();

    }

}

void MarioKart::initWindow() {
    this->gameWindow.create(sf::VideoMode(1200, 768), "Brick MarioKart: Car Racing");
    this->gameWindow.setFramerateLimit(60);
}

sf::RenderWindow& MarioKart::getWindow() {
    return gameWindow;
}

void MarioKart::processEvents() {
	
    sf::Event event;
    while (gameWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            gameWindow.close();

        if (event.type == sf::Event::KeyPressed) {
            cout << "Key Pressed" << endl;
            myCar->moveCar(event);
            procesarColiciones();
            if (!myCar->carSprite.getGlobalBounds().intersects(badCar->carSprite1.getGlobalBounds()) &&
                !myCar->carSprite.getGlobalBounds().intersects(badCar->carSprite2.getGlobalBounds()) &&
                !myCar->carSprite.getGlobalBounds().intersects(badCar->carSprite3.getGlobalBounds()) &&
                !myCar->carSprite.getGlobalBounds().intersects(badCar->carSprite4.getGlobalBounds())) {
                this->score += 100;
                this->valScoreTxt.setString(std::to_string(this->score));
            }
            nextLevel();
        }
    }
	
    badCar->moveCarRed1(gameWindow);
    badCar->moveCarRed2(gameWindow);
    badCar->moveCarRed3(gameWindow);
    badCar->moveCarRed4(gameWindow);
}

void MarioKart::render() {
    gameWindow.clear();

    // Drawing section
    this->renderText();
    gameWindow.draw(roadSprite); // carretera
    this->renderCar();
    //=====

    gameWindow.display();
}

//Aca hice el intento de hacer mover el carro, pero nada
void MarioKart::update() {

}

void MarioKart::initText() {
    if (!font.loadFromFile("assets/fonts/OcrAExt.ttf"))
        cerr << "Error loading font" << endl;

    separator.setFont(font);
    separator.setCharacterSize(90);
    std::string s = "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|";
    separator.setString(s);
    separator.setFillColor(sf::Color::White);
    separator.setPosition(790, 0);

    scoreTxt.setFont(font);
    scoreTxt.setString("Score:");
    scoreTxt.setCharacterSize(35);
    scoreTxt.setFillColor(sf::Color(150, 150, 150));
    scoreTxt.setPosition(850, 10);

    valScoreTxt.setFont(font);
    valScoreTxt.setString(std::to_string(this->score));
    valScoreTxt.setCharacterSize(35);
    valScoreTxt.setFillColor(sf::Color::White);
    valScoreTxt.setPosition(850, 55);

    highScoreTxt.setFont(font);
    highScoreTxt.setString("High Score:");
    highScoreTxt.setCharacterSize(35);
    highScoreTxt.setFillColor(sf::Color(150, 150, 150));
    highScoreTxt.setPosition(850, 105);

    valHiScoreTxt.setFont(font);
    valHiScoreTxt.setString(std::to_string(this->highScore));
    valHiScoreTxt.setCharacterSize(35);
    valHiScoreTxt.setFillColor(sf::Color::White);
    valHiScoreTxt.setPosition(850, 150);

    speedTxt.setFont(font);
    speedTxt.setString("Speed:");
    speedTxt.setCharacterSize(35);
    speedTxt.setFillColor(sf::Color(150, 150, 150));
    speedTxt.setPosition(850, 200);

    valSpeedTxt.setFont(font);
    valSpeedTxt.setString(std::to_string(this->actualSpeed));
    valSpeedTxt.setCharacterSize(35);
    valSpeedTxt.setFillColor(sf::Color::White);
    valSpeedTxt.setPosition(850, 245);

    livesTxt.setFont(font);
    livesTxt.setString("Lives:");
    livesTxt.setCharacterSize(35);
    livesTxt.setFillColor(sf::Color(150, 150, 150));
    livesTxt.setPosition(850, 295);

    valLivesTxt.setFont(font);
    valLivesTxt.setString(std::to_string(this->lives));
    valLivesTxt.setCharacterSize(35);
    valLivesTxt.setFillColor(sf::Color::White);
    valLivesTxt.setPosition(850, 340);

    levelTxt.setFont(font);
    levelTxt.setString("Level:");
    levelTxt.setCharacterSize(35);
    levelTxt.setFillColor(sf::Color(150, 150, 150));
    levelTxt.setPosition(850, 390);

    valLevelTxt.setFont(font);
    valLevelTxt.setString(std::to_string(this->level));
    valLevelTxt.setCharacterSize(35);
    valLevelTxt.setFillColor(sf::Color::White);
    valLevelTxt.setPosition(850, 435);
}

void MarioKart::renderText() {
    gameWindow.draw(separator);

    gameWindow.draw(scoreTxt);
    gameWindow.draw(valScoreTxt);

    gameWindow.draw(highScoreTxt);
    gameWindow.draw(valHiScoreTxt);

    gameWindow.draw(speedTxt);
    gameWindow.draw(valSpeedTxt);

    gameWindow.draw(livesTxt);
    gameWindow.draw(valLivesTxt);

    gameWindow.draw(levelTxt);
    gameWindow.draw(valLevelTxt);
}

void MarioKart::initTextures() {
    cout << "Loading textures..." << endl;
    if (!textures.loadFromFile("assets/img/textures/marioKart/roadMap.png"))
        cerr << "Error loading road texture" << endl;
    
    roadRect.left = 0;
    roadRect.top = 0;
    roadRect.width = 803;
    roadRect.height = 768;

    textures.setSmooth(true);
    roadSprite.setTexture(textures);
    //roadSprite.setScale(1.75, 1.75);
    roadSprite.setTextureRect(roadRect);

}


void MarioKart::initCar() {
    this->myCar = new Car();
    this->badCar = new BadCar();
}

void MarioKart::renderCar() {

    this->myCar->render(gameWindow);
    this->badCar->renderRedCar(gameWindow);
}

void MarioKart::deleteCar() {
    delete myCar;
}

void MarioKart::procesarColiciones() {
    if (badCar->carSprite1.getGlobalBounds().intersects(myCar->carSprite.getGlobalBounds())) {
        this->lives--;
        this->valLivesTxt.setString(std::to_string(this->lives));
        this->score -= 100;
        this->valScoreTxt.setString(std::to_string(this->score));
        this->badCar->carSprite1.setPosition(360, 0);
        cout << "Collision" << endl;
    }
    else {
        if (badCar->carSprite2.getGlobalBounds().intersects(myCar->carSprite.getGlobalBounds())) {
            this->lives--;
            this->valLivesTxt.setString(std::to_string(this->lives));
            this->score -= 100;
            this->valScoreTxt.setString(std::to_string(this->score));
            this->badCar->carSprite2.setPosition(95, 0);
        }
        else {
            if (badCar->carSprite3.getGlobalBounds().intersects(myCar->carSprite.getGlobalBounds())) {
                this->lives--;
                this->valLivesTxt.setString(std::to_string(this->lives));
                this->score -= 100;
                this->valScoreTxt.setString(std::to_string(this->score));
                this->badCar->carSprite3.setPosition(625, 0);
            }
            else {
                if (badCar->carSprite4.getGlobalBounds().intersects(myCar->carSprite.getGlobalBounds())) {
                    this->lives--;
                    this->valLivesTxt.setString(std::to_string(this->lives));
                    this->score -= 100;
                    this->valScoreTxt.setString(std::to_string(this->score));
                    this->badCar->carSprite4.setPosition(360, 0);
                }
            }
        }
    }
}

void MarioKart::nextLevel() {
    if (this->score < 1000) {
        this->level = 1;
        this->valLevelTxt.setString(std::to_string(this->level));
    }
    else if (this->score >= 1000 && this->score < 2000) {
        this->level = 2;
        this->valLevelTxt.setString(std::to_string(this->level));
        badCar->setRapidez(1.5f);
    }
    else if (this->score >= 2000 && this->score < 3000) {
        this->level = 3;
        this->valLevelTxt.setString(std::to_string(this->level));
        badCar->setRapidez(1.75f);
    }
    else if (this->score >= 3000 && this->score < 4000) {
        this->level = 4;
        this->valLevelTxt.setString(std::to_string(this->level));
        badCar->setRapidez(2.0f);
    }
    else if (this->score >= 4000 && this->score < 5000) {
        this->level = 5;
        this->valLevelTxt.setString(std::to_string(this->level));
        badCar->setRapidez(2.25f);
    }
    else if (this->score >= 5000 && this->score < 6000) {
        this->level = 6;
        this->valLevelTxt.setString(std::to_string(this->level));
        badCar->setRapidez(2.5f);
    }

}