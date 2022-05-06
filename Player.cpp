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
Player::Player()
{
    this->initVariables();
    this->initShape();
}

Player::~Player()
{

}

void Player::update()
{

}

void Player::render(sf::RenderTarget * target)
{
    target->draw(this->shape);
}