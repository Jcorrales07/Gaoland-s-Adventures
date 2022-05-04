#include "StartScreen.h"
#include "SFML/Graphics.hpp"
#include "iostream"

StartScreen::StartScreen() {

	//if (!font.loadFromFile("Assets/Fonts/Roboto-Black.ttf")) {
	//	std::cerr << "Error loading font" << std::endl;
	//}

	////Texto estatico
	//startTxt.setFont(font);
	//startTxt.setString("Welcome to our Game!");
	//startTxt.setCharacterSize(70);
	//startTxt.setFillColor(sf::Color::Black);
	//startTxt.setPosition(100, 200);

	////Quiero hacer que este texto parpadee
	//press2PlayTxt.setFont(font);
	//press2PlayTxt.setString("Press any key to continue");
	//press2PlayTxt.setCharacterSize(20);
	//press2PlayTxt.setFillColor(sf::Color::Black);
	//press2PlayTxt.setPosition(500, 500);

}

void StartScreen::createWindow() {
	sf::RenderWindow startWindow(sf::VideoMode(1200, 600), "Welcome!");
	std::cout << "si paso";
	sf::sleep(sf::seconds(5));
}
