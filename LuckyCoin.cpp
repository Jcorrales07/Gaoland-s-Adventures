#include <iostream>
#include "LuckyCoin.h"
#include "MarioKart.h"

using std::cerr, std::cout, std::endl;

LuckyCoin::LuckyCoin() {
    cout << "Creating a coin" << endl;
    this->setTexture();
}

LuckyCoin::~LuckyCoin() = default;

void LuckyCoin::setTexture() {
    cout << "Loading textures Coin..." << endl;
    if (!coinTexture.loadFromFile("assets/textures/coinLuck.png"))
        cerr << "Error loading coin texture" << endl;
    coinTexture.setSmooth(true);

    this->coinSprite1.setTexture(coinTexture);
    this->coinSprite1.setPosition(360, -300); // segundo carril
    this->coinSprite1.setScale(1.5f, 1.5);

    this->coinSprite2.setTexture(coinTexture);
    this->coinSprite2.setPosition(95, -300); // primer carril
    this->coinSprite2.setScale(1.5f, 1.5f);

    this->coinSprite3.setTexture(coinTexture);
    this->coinSprite3.setPosition(625, -300); // tercer carril
    this->coinSprite3.setScale(1.5f, 1.5f);

    this->coinSprite4.setTexture(coinTexture);
    this->coinSprite4.setPosition(360, -300); // segundo carril
    this->coinSprite4.setScale(1.5f, 1.5f);

    this->coinSprite5.setTexture(coinTexture);
    this->coinSprite5.setPosition(360, -300); // segundo carril
    this->coinSprite5.setScale(1.5f, 1.5f);

}

void LuckyCoin::renderCoin(sf::RenderTarget &target) const {
    target.draw(this->coinSprite1);
    target.draw(this->coinSprite2);
    target.draw(this->coinSprite3);
    target.draw(this->coinSprite4);
    target.draw(this->coinSprite5);
}

void LuckyCoin::moveCoin1(sf::RenderWindow &render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
    this->coinSprite1.move(_velocidad * tiempo.asSeconds());
}

void LuckyCoin::moveCoin2(sf::RenderWindow &render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
    this->coinSprite2.move(_velocidad * tiempo.asSeconds());
}

void LuckyCoin::moveCoin3(sf::RenderWindow &render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
    this->coinSprite3.move(_velocidad * tiempo.asSeconds());
}

void LuckyCoin::moveCoin4(sf::RenderWindow &render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
    this->coinSprite4.move(_velocidad * tiempo.asSeconds());
}

void LuckyCoin::moveCoin5(sf::RenderWindow &render_window) {
    sf::Time tiempo = sf::seconds(1.0f);
    sf::Vector2f _velocidad;
    _velocidad.x = 0;
    _velocidad.y = rapidez;
    this->coinSprite5.move(_velocidad * tiempo.asSeconds());
}

void LuckyCoin::setRapidez(float rapidez) {
    this->rapidez = rapidez;
}