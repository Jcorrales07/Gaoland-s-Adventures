#include "Car.h"
#include "iostream"

using std::cerr;
using std::cout;
using std::endl;

Car::Car()
{
	cout << "Creating a car" << endl;
	this->setTexture();
}

Car::~Car()
{

}


void Car::setTexture()
{
	cout << "Loading textures..." << endl;
	if (!carTexture.loadFromFile("assets/img/textures/marioKart/carmario.png"))
		cerr << "Error loading car texture" << endl;

	this->carSprite.setTexture(carTexture);
	this->carSprite.setPosition(360, 575); // segundo carril
	this->carSprite.setScale(1.5f, 1.5f);
}

void Car::render(sf::RenderTarget& target)
{
	target.draw(this->carSprite);
}

void Car::update()
{
}

void Car::moveCar(sf::Event& event)
{
	if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
		// Condicion si el carro esta en el carril de enmedio entonces...
		if (carSprite.getPosition().x == 360) 
			carSprite.setPosition(95, 575);
		else if (carSprite.getPosition().x == 625) 
			carSprite.setPosition(360, 575);
	}
	else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
		// Condicion si el carro esta en el carril de enmedio entonces...
		if (carSprite.getPosition().x == 360) 
			carSprite.setPosition(625, 575);
		else if (carSprite.getPosition().x == 95) 
			carSprite.setPosition(360, 575);
	}
}

