#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
    sf::RectangleShape shape;

    float movementSpeed;

    void initVariables();
    void initShape();

public:
    Player(float x = 0.f, float y = 0.f); //constructor
    //Player(); //constructor
    virtual ~Player(); //deconstructor

    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);

};


#endif //PLAYER_H
