#include "MenuScreen.h"
#include "SFML/Graphics.hpp"
#include "StartScreen.h"
#include "Menu.h"
#include "iostream"

using std::cout;
using std::endl;


MenuScreen::MenuScreen()
 : PrincipalMenu(sf::VideoMode(1500, 1000), "Principal Menu")
{
	PrincipalMenu.setFramerateLimit(60);
	this->pWidth = PrincipalMenu.getSize().x;
	this->pHeight = PrincipalMenu.getSize().y;
	this->run();
}

MenuScreen::~MenuScreen()
{
	
}

void MenuScreen::run()
{
	//Cargar el sprite de la imagen de fondo
	menuTexture.loadFromFile("assets/img/bgs/menuScreenSS.png");
	this->menuSprite.setTexture(menuTexture);
	sf::IntRect rectSourceSprite(0, 0, 1500, 1000);
	this->menuSprite.setTextureRect(rectSourceSprite);
	
	sf::Clock clock;


	while (PrincipalMenu.isOpen()) {
		processEvents();
		update();
		
		if (clock.getElapsedTime().asSeconds() > 0.1f) {
			if (rectSourceSprite.left == 10500) rectSourceSprite.left = 0;
			else rectSourceSprite.left += 1500;

			menuSprite.setTextureRect(rectSourceSprite);
			clock.restart();
		}

		render();
	}
}

void MenuScreen::processEvents()
{

	Menu menu(1500, 1000);
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
	Menu menu(1500, 1000);
	PrincipalMenu.clear();
	PrincipalMenu.draw(menuSprite);
	menu.drawMenuImg(PrincipalMenu);
	PrincipalMenu.display();	
}

double MenuScreen::getPWidth()
{
	return this->pWidth;
}

double MenuScreen::getPHeight()
{
	return this->pHeight;
}
