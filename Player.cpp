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

void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();

    //Collisions
    this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget * target)
{
    target->draw(this->shape);
}

void Player::updateInput()
{
    //Keyboard input

    //IZQUIERDA
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //OJO CON EL NEGATIVO!!!
        this->shape.move(-this->movementSpeed, 0.f);
    }//DERECHA
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed, 0.f);
    }//ARRIBA
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f, -this->movementSpeed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->movementSpeed);
    }
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget *target)
{

    sf::FloatRect playerBounds = this->shape.getGlobalBounds();
    //IZQUIERDAAAA
    if(playerBounds.left <= 0.f)
        this->shape.setPosition(0.f, playerBounds.top);
    //DERECHA
    if(playerBounds.left +playerBounds.width >= target->getSize().x)
        this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
    //ARRIBA
    if(playerBounds.top <= 0.f)
        this->shape.setPosition(playerBounds.left, 0.f);
    //Abajo
    if(playerBounds.top +playerBounds.height >= target->getSize().y)
        this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
}