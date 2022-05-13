#include "MenuScreen.h"
#include "SFML/Graphics.hpp"
#include "StartScreen.h"
#include "iostream"

using std::cout;
using std::cerr;
using std::endl;


MenuScreen::MenuScreen()
 : principalMenu(sf::VideoMode(1500, 1000), "Principal Menu")
{
	principalMenu.setFramerateLimit(60);
	this->pWidth = principalMenu.getSize().x;
	this->pHeight = principalMenu.getSize().y;
	this->initMenuOptions();
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


	while (principalMenu.isOpen()) {
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

	sf::Event event;
	while (principalMenu.pollEvent(event)) {
		switch (event.type) {

			case sf::Event::KeyReleased: {
				
				switch (event.key.code) {
					// Caso de que se presione la tecla up
					case sf::Keyboard::Up:
						moveUp();
						break;

						// Caso de que se presione la tecla down
					case sf::Keyboard::Down:
						moveDown();
						break;

						// Caso de que se presione enter
					case sf::Keyboard::Return:
						if (getIndex() == 0) {
							cout << "Play" << endl;
						}
						else if (getIndex() == 1) {
							cout << "Options" << endl;
						}
						else if (getIndex() == 2) {
							cout << "Exit" << endl;
							principalMenu.close();
						}
						break;

					default:
						break;
				}
				break;
			}

			case sf::Event::Closed: {
				principalMenu.close();
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
	principalMenu.clear();
	principalMenu.draw(menuSprite);
	//mostrar el menu
	drawMenuOptions(principalMenu);
	principalMenu.display();
}

void MenuScreen::moveUp()
{
	if (index > 0) index--;

	if (index == 2) {
		menuBtns[index].setTextureRect(sf::IntRect(1250, 0, 250, 150)); //encendido [2]
		menuBtns[index - 2].setTextureRect(sf::IntRect(0, 0, 250, 150)); //apagado [0]
		menuBtns[index - 1].setTextureRect(sf::IntRect(500, 0, 250, 150)); //apagado [1]
	}
	else if (index == 1) {
		menuBtns[index].setTextureRect(sf::IntRect(750, 0, 250, 150)); //encendido [1]
		menuBtns[index - 1].setTextureRect(sf::IntRect(0, 0, 250, 150)); //apagado [0]
		menuBtns[index + 1].setTextureRect(sf::IntRect(1000, 0, 250, 150)); //apagado [2]
	}
	else if (index == 0) {
		menuBtns[index].setTextureRect(sf::IntRect(250, 0, 250, 150)); //encendido [0]	
		menuBtns[index + 1].setTextureRect(sf::IntRect(500, 0, 250, 150)); //apagado [1]
		menuBtns[index + 2].setTextureRect(sf::IntRect(1000, 0, 250, 150)); //apagado [2]
	}
}

void MenuScreen::moveDown()
{
	if (index < 2) index++;

	if (index == 1) {
		menuBtns[index].setTextureRect(sf::IntRect(750, 0, 250, 150)); //encendido [1]
		menuBtns[index - 1].setTextureRect(sf::IntRect(0, 0, 250, 150)); //apagado [0]
		menuBtns[index + 1].setTextureRect(sf::IntRect(1000, 0, 250, 150)); //apagado [2]
	}
	else if (index == 2) {
		menuBtns[index].setTextureRect(sf::IntRect(1250, 0, 250, 150)); //encendido [2]
		menuBtns[index - 2].setTextureRect(sf::IntRect(0, 0, 250, 150)); //apagado [0]
		menuBtns[index - 1].setTextureRect(sf::IntRect(500, 0, 250, 150)); //apagado [1]
	}
}

void MenuScreen::initMenuOptions()
{
	if (!btnTextures.loadFromFile("Assets/img/btns/btnTexture.png"))
		cerr << "Error loading the texture for btns" << endl;

	menuBtns[0].setTexture(btnTextures);
	menuBtns[0].setTextureRect(sf::IntRect(0, 0, 250, 150));
	menuBtns[0].setPosition( pWidth - 1400, 100);
	menuBtns[0].setScale(0.7f, 0.7f);

	menuBtns[1].setTexture(btnTextures);
	menuBtns[1].setTextureRect(sf::IntRect(500, 0, 250, 150));
	menuBtns[1].setPosition(pWidth - 1400, 300);
	menuBtns[1].setScale(0.7f, 0.7f);

	menuBtns[2].setTexture(btnTextures);
	menuBtns[2].setTextureRect(sf::IntRect(1000, 0, 250, 150));
	menuBtns[2].setPosition(pWidth - 1400, 500);
	menuBtns[2].setScale(0.7f, 0.7f);
	
}

void MenuScreen::drawMenuOptions(sf::RenderTarget& window)
{
	for (int i = 0; i < 3; i++)
		window.draw(menuBtns[i]);
}

int MenuScreen::getIndex()
{
	return index;
}

double MenuScreen::getPWidth()
{
	return this->pWidth;
}

double MenuScreen::getPHeight()
{
	return this->pHeight;
}
