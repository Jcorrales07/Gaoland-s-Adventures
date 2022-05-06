#pragma once

#ifndef OBJETOCARGA_H
#define OBJETOCARGA_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class objetoCarga {
private:
    sf::CircleShape shape;

    void initShape();
public:
    objetoCarga();
    virtual ~objetoCarga();

    void update();
    void render(sf::RenderTarget& target);
};


#endif //GAOLAND_S_ADVENTURES_OBJETOCARGA_H
