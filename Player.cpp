//
// Created by shello on 05-05-22.
//

#include "Player.h"

void Player::initVariables()
{
    this->movementSpeed = 5.f;
}

void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}
//Aquí seteo la ubicación del Player!!!
Player::Player(float x, float y)
{
    this->shape.setPosition(x, y);

    this->initVariables();
    this->initShape();
}

Player::~Player()
{

}

void Player::update()
{
    // colisiones
    //Keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

    }
}

void Player::render(sf::RenderTarget * target)
{
    target->draw(this->shape)
};