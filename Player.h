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
    // Player(float x, float y); //constructor
    Player(); //constructor
    virtual ~Player(); //deconstructor

    void update();
    void render(sf::RenderTarget* target);
};


#endif //PLAYER_H
