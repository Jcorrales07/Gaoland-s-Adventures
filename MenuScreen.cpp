#include "MenuScreen.h"
#include "SFML/Graphics.hpp"
#include "StartScreen.h"
#include "Options.h"
#include "Ruleta.h"
#include "iostream"

using std::cout;
using std::cerr;
using std::endl;


MenuScreen::MenuScreen()
 : principalMenu(sf::VideoMode(1366, 768), "Principal Menu")
{
	principalMenu.setFramerateLimit(60);
	this->pWidth = principalMenu.getSize().x;
	this->pHeight = principalMenu.getSize().y;
	this->index = 0;
	this->musicPts = 25.0f;
	this->initMenuOptions();
	this->run();
}

MenuScreen::~MenuScreen()
{
	
}

void MenuScreen::run()
{
	//Cargar el sprite de la imagen de fondo
	initBackground();

	//Cargar sonido para boton
	initSoundEffect();

	//Cargar musica de fondo para el menu jsjsjs (no tiene sentido por ahora)
	initMusic();
	
	sf::Clock clock;

	while (principalMenu.isOpen()) {
		
		processEvents();
		update();
		
		if (clock.getElapsedTime().asSeconds() > 0.1f) {
			if (this->rectSourceSprite.left == 1500) this->rectSourceSprite.left = 0;
			else this->rectSourceSprite.left += 500;

			menuSprite.setTextureRect(this->rectSourceSprite);
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
						
						isPressed = true;
						
						if (getIndex() == 0) {
							//Aca iria el nivel 1, despues se 
							//va a conectar como cadena, los
							//demas niveles
							principalMenu.setVisible(false);
							Ruleta ruleta;
						}
						else if (getIndex() == 1) {
							this->principalMenu.setVisible(false);
							options.setMusicVolTo(musicPts);
							options.run();
							this->principalMenu.setVisible(true);
						}
						else if (getIndex() == 2) {
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
	
	principalMenu.draw(menuSprite); //Background
	drawMenuOptions(principalMenu); //Menu Options

	// QUIERO HACER QUE LA OPCION "OPCIONES" SE PUEDA MANIPULAR EN ESTA MISMA VENTANA
	/*if (isPressed && getIndex() == 1) { 
		principalMenu.clear();

		principalMenu.display();
	}*/
	
	principalMenu.display();
}

void MenuScreen::moveUp()
{
	playSoundEffect();
	if (index > 0) index--;

	if (index == 2) {
		menuBtns[index].setTextureRect(sf::IntRect(1250, 0, 250, 150)); //encendido [2]
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
	}
}

void MenuScreen::moveDown()
{
	playSoundEffect();
	if (index < 2) index++;

	if (index == 1) {
		menuBtns[index].setTextureRect(sf::IntRect(750, 0, 250, 150)); //encendido [1]
		menuBtns[index - 1].setTextureRect(sf::IntRect(0, 0, 250, 150)); //apagado [0]
	}
	else if (index == 2) {
		menuBtns[index].setTextureRect(sf::IntRect(1250, 0, 250, 150)); //encendido [2]
		menuBtns[index - 1].setTextureRect(sf::IntRect(500, 0, 250, 150)); //apagado [1]
	}
}

void MenuScreen::initMenuOptions()
{
	if (!btnTextures.loadFromFile("Assets/img/btns/btnTextures.png"))
		cerr << "Error loading the texture for btns" << endl;

	menuBtns[0].setTexture(btnTextures);
	menuBtns[0].setTextureRect(sf::IntRect(0, 0, 250, 150));
	menuBtns[0].setPosition(float(pWidth / 2.5 ), 100.0f);
	menuBtns[0].setScale(0.7f, 0.7f);

	menuBtns[1].setTexture(btnTextures);
	menuBtns[1].setTextureRect(sf::IntRect(500, 0, 250, 150));
	menuBtns[1].setPosition(float(pWidth / 2.5 ), 225.0f);
	menuBtns[1].setScale(0.7f, 0.7f);

	menuBtns[2].setTexture(btnTextures);
	menuBtns[2].setTextureRect(sf::IntRect(1000, 0, 250, 150));
	menuBtns[2].setPosition(float(pWidth / 2.5 ), 350.0f);
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

void MenuScreen::initBackground()
{
	menuTexture.loadFromFile("Assets/img/bgs/bgMarioTexture.png");
	this->menuSprite.setTexture(menuTexture);
	this->rectSourceSprite.left = 0;
	this->rectSourceSprite.top = 0;
	this->rectSourceSprite.width = 500;
	this->rectSourceSprite.height = 250;
	this->menuSprite.setTextureRect(this->rectSourceSprite);
	this->menuSprite.setScale(2.73f, 3.07f); // que se adapte a la pantalla
}

void MenuScreen::initMusic()
{
	if (!menuMusic.openFromFile("Assets/sounds/overworld.ogg"))
		cerr << "Error loading the menu music" << endl;
		
	menuMusic.setVolume(musicPts);
	menuMusic.setLoop(true);
	menuMusic.setVolume(5.0f);
	menuMusic.play();
}

void MenuScreen::initSoundEffect()
{
	if (!buffer.loadFromFile("Assets/sounds/botonbip.wav"))
		cerr << "Error loading the " << endl;
	
	this->sound.setBuffer(buffer);
}

void MenuScreen::playSoundEffect()
{
	this->sound.setVolume(75.0f);
	this->sound.play();
}

float MenuScreen::getPWidth()
{
	return this->pWidth;
}

float MenuScreen::getPHeight()
{
	return this->pHeight;
}
