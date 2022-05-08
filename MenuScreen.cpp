#include "MenuScreen.h"
#include "SFML/Graphics.hpp"
#include "StartScreen.h"
#include "Menu.h"
#include "iostream"

using std::cout;
using std::endl;


StartScreen ss;

MenuScreen::MenuScreen()
 : PrincipalMenu(sf::VideoMode(1500, 1000), "Principal Menu")
{
	PrincipalMenu.setFramerateLimit(60);
	this->pWidth = PrincipalMenu.getSize().x;
	this->pHeight = PrincipalMenu.getSize().y;
	
	// Aca se tiene que poner un fondo animado, no estatico
	this->background.setSize(sf::Vector2f(pWidth, pHeight));
	this->backgroundTexture.loadFromFile("assets/img/bgs/mainMenu.gif");
	this->background.setTexture(&this->backgroundTexture);
}

MenuScreen::~MenuScreen()
{
	
}

void MenuScreen::run()
{
	Menu menu(pWidth, pHeight);
	
	while (PrincipalMenu.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void MenuScreen::processEvents()
{
	Menu menu(pWidth, pHeight);
	sf::Event event;
	while (PrincipalMenu.pollEvent(event)) {
		switch (event.type) {

			case sf::Event::KeyReleased: {
				
				switch (event.key.code) {
					// Caso de que se presione la tecla up
					case sf::Keyboard::Up:
						menu.moveUp();
						break;

						// Caso de que se presione la tecla down
					case sf::Keyboard::Down:
						menu.moveDown();
						break;

						// Caso de que se presione enter
					case sf::Keyboard::Return:
						if (menu.getSelectedItem() == 0) {
							cout << "Play" << endl;
						}
						else if (menu.getSelectedItem() == 1) {
							cout << "Options" << endl;
						}
						else if (menu.getSelectedItem() == 2) {
							PrincipalMenu.close();
						}
						break;

					default:
						break;
				}
				break;
			}

			case sf::Event::Closed: {
				PrincipalMenu.close();
				break;
			}

			default:
				break;
		}
	}
}

void MenuScreen::update()
{
	
}

void MenuScreen::render()
{
	Menu menu(pWidth, pHeight);
	PrincipalMenu.clear();
	PrincipalMenu.draw(background);
	menu.drawMenuImg(PrincipalMenu);
	PrincipalMenu.display();	
}

void MenuScreen::menuScreen()
{
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "Principal Menu");
	window.setFramerateLimit(60);

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1500, 1000));
	sf::Texture mainTexture;
	mainTexture.loadFromFile("assets/img/bgs/pantallaMenu.jpg");
	background.setTexture(&mainTexture);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type) {

			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;

				case sf::Keyboard::Return:
					if (menu.getSelectedItem() == 0) {
						std::cout << "Play" << std::endl;
					}
					else if (menu.getSelectedItem() == 1) {
						std::cout << "Options" << std::endl;
					}
					else if (menu.getSelectedItem() == 2) {
						window.close();
					}
					break;

				default:
					break;
				}
				break;

			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		window.clear();
		window.draw(background);
		menu.drawMenuImg(window);
		window.display();
	}
}

double MenuScreen::getPWidth()
{
	return this->pWidth;
}

double MenuScreen::getPHeight()
{
	return this->pHeight;
}
