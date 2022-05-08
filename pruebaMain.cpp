#include "SFML/Graphics.hpp"
#include "iostream"
#include "Menu.h"
#include "StartScreen.h"
#include "MenuScreen.h"
#include <cstdlib>
#include "Animation.h"

//Esto lo estoy haciendo por que no se como chuchas funciona c++ con clases.
//mas adelante voy a limpiar este codigo
//void startScreen();
//void menuScreen();

int main() {
	
	StartScreen startScreen;
	startScreen.run();

	return 0;
}

// hecho
//void startScreen() {
//	// el tamaño de la pantalla no es definitivo. falta por decidirlo
//	sf::RenderWindow startWindow(sf::VideoMode(1500, 1000), "Welcome!"); //==
//	//Tamaños X y Y de la pantalla
//	double screenX = startWindow.getSize().x; //==
//	double screenY = startWindow.getSize().y; //==
//
//	sf::RectangleShape background; //==
//	background.setSize(sf::Vector2f(screenX, screenY)); //==
//	sf::Texture startTexture; //==
//	//startTexture.loadFromFile("assets/img/bgs/startScreenSS.png");
//	startTexture.loadFromFile("assets/img/bgs/pantallaPrincipal.gif"); //==
//	background.setTexture(&startTexture); //==
//
//	// esto es la prueba del fondo de animacion
//	sf::Sprite bgSprite;
//
//	Animation startAnimation(&startTexture, sf::Vector2u(560, 272), 0.3f);
//	float deltaTime = 0.0f;
//	sf::Clock clock;
//	
//	//=========================================
//
//	
//	sf::Event ev;
//	sf::Font font;
//	sf::Text textWelcome, textPress;
//
//	//Cargar la fuente para el texto
//	if (!font.loadFromFile("assets/fonts/OcrAExt.ttf"))
//		std::cerr << "Error loading font" << std::endl;
//
//	//texto estatico
//	textWelcome.setFont(font);
//	textWelcome.setString("\tWelcome to \nGaoland's Adventures!");
//	textWelcome.setCharacterSize(70);
//	textWelcome.setFillColor(sf::Color::Black);
//	// en X es el tamaño de la pantalla entre 3.8, para poder centrarlo ((1500/3.8) = 394.73)
//	textWelcome.setPosition(screenX / 3.8, 100);
//
//	//quiero hacer que este texto parpadee
//	textPress.setFont(font);
//	textPress.setString("Press any key to continue");
//	textPress.setCharacterSize(25);
//	textPress.setFillColor(sf::Color::Black);
//	textPress.setPosition(screenX / 2.4, screenY - 100);
//
//	
//	while (startWindow.isOpen()) {
//		deltaTime = clock.restart().asSeconds();
//		
//		int num = rand() % 3;
//		
//		while (startWindow.pollEvent(ev)) {
//			switch (ev.type) {
//				case sf::Event::KeyPressed:
//					std::cout << "tecla: " << ev.key.code << std::endl;
//				case sf::Event::Closed:
//					startWindow.close();
//				break;
//
//				default:
//					break;
//			}
//		}
//
//		startAnimation.update(0, deltaTime);
//		bgSprite.setTextureRect(startAnimation.uvRect);
//
//		startWindow.clear();
//		startWindow.draw(background);
//		startWindow.draw(textWelcome);
//		//Supuestamente esto hace que parpadee pero se mira raro :/
//		if (num % 2 == 0) startWindow.draw(textPress);
//		startWindow.display();
//	}
//
//	if (ev.type != sf::Event::Closed) {
//		menuScreen();
//	}
//}
//
////falta separar esto en su clase
//void menuScreen() {
//	sf::RenderWindow window(sf::VideoMode(1500, 1000), "Principal Menu");
//	window.setFramerateLimit(60);
//
//	sf::RectangleShape background;
//	background.setSize(sf::Vector2f(1500, 1000));
//	sf::Texture mainTexture;
//	mainTexture.loadFromFile("assets/img/bgs/pantallaMenu.jpg");
//	background.setTexture(&mainTexture);
//
//	Menu menu(window.getSize().x, window.getSize().y);
//
//	while (window.isOpen()) {
//		sf::Event event;
//
//		while (window.pollEvent(event)) {
//
//			switch (event.type) {
//
//				case sf::Event::KeyReleased:
//					switch (event.key.code) {
//						case sf::Keyboard::Up:
//							menu.moveUp();
//						break;
//						case sf::Keyboard::Down:
//							menu.moveDown();
//						break;
//
//						case sf::Keyboard::Return:
//							if (menu.getSelectedItem() == 0) {
//								std::cout << "Play" << std::endl;
//							}
//							else if (menu.getSelectedItem() == 1) {
//								std::cout << "Options" << std::endl;
//							}
//							else if (menu.getSelectedItem() == 2) {
//								window.close();
//							}
//						break;
//
//						default:
//							break;
//					}
//					break;
//
//				case sf::Event::Closed:
//					window.close();
//					break;
//
//				default:
//					break;
//			}
//		}
//
//		window.clear();
//		window.draw(background);
//		menu.drawMenuImg(window);
//		window.display();
//	}
//}

	

