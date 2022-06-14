#include <iostream>
#include "BadCar.h"

using std::cerr;
using std::cout;
using std::endl;

BadCar::BadCar() {
    cout << "Creating a car" << endl;
    this->setTexture();
}

BadCar::~BadCar() {

}

void BadCar::setTexture() {
    cout << "Loading textures..." << endl;
	
    if (!carTextures.loadFromFile("assets/img/textures/marioKart/marioKarts.png"))
        cerr << "Error loading car texture" << endl;
	
    carTextures.setSmooth(true);

    this->carSprite1.setTexture(carTextures); //carbowser
    this->carSprite1.setTextureRect(sf::IntRect(52 * 0, 0, 52, 80));
    this->carSprite1.setPosition(360, 0); // segundo carril
    this->carSprite1.setScale(1.5f, 1.5);

    this->carSprite4.setTexture(carTextures); //carluigi
    this->carSprite4.setTextureRect(sf::IntRect(52 * 1, 0, 52, 80));
    this->carSprite4.setPosition(360, -1200); // segundo carril
    this->carSprite4.setScale(1.5f, 1.5f);

    this->carSprite3.setTexture(carTextures); //carpeach
    this->carSprite3.setTextureRect(sf::IntRect(52 * 2, 0, 52, 80));
    this->carSprite3.setPosition(625, -900); // tercer carril
    this->carSprite3.setScale(1.5f, 1.5f);

    this->carSprite2.setTexture(carTextures); //caryoshi
    this->carSprite2.setTextureRect(sf::IntRect(52 * 3, 0, 52, 80));
    this->carSprite2.setPosition(95, -600); // primer carril
    this->carSprite2.setScale(1.5f, 1.5f);
}

void BadCar::renderRedCar(sf::RenderTarget& target) const {
    target.draw(this->carSprite1);
    target.draw(this->carSprite2);
    target.draw(this->carSprite3);
    target.draw(this->carSprite4);
}

void BadCar::update() {
}

void BadCar::moveCarRed1(sf::RenderWindow& render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
	
    carSprite1.move(_velocidad * tiempo.asSeconds());
	
    if (carSprite1.getPosition().y > 800) {
        carSprite1.setPosition(360, -600);
    }
    else {
        carSprite1.move(_velocidad * tiempo.asSeconds());
    }
}

void BadCar::moveCarRed2(sf::RenderWindow& render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
	
    carSprite2.move(_velocidad * tiempo.asSeconds());
	
    if (carSprite2.getPosition().y > 800) {
        carSprite2.setPosition(95, -600);
    }
    else {
        carSprite2.move(_velocidad * tiempo.asSeconds());
    }
}

void BadCar::moveCarRed3(sf::RenderWindow& render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
	
    carSprite3.move(_velocidad * tiempo.asSeconds());
	
    if (carSprite3.getPosition().y > 800) {
        carSprite3.setPosition(625, -600);
    }
    else {
        carSprite3.move(_velocidad * tiempo.asSeconds());
    }
}

void BadCar::moveCarRed4(sf::RenderWindow& render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
	
    carSprite4.move(_velocidad * tiempo.asSeconds());
	
    if (carSprite4.getPosition().y > 800) {
        carSprite4.setPosition(360, -600);
    }
    else {
        carSprite4.move(_velocidad * tiempo.asSeconds());
    }
}

sf::Texture BadCar::getCarTextures()
{
    return this->carTextures;
}

void BadCar::setRapidez(float _rapidez) {
    this->rapidez = _rapidez;
}

float BadCar::getRapidez() const {
    return this->rapidez;
}


