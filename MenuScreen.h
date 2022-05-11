#pragma once

#include "SFML/Graphics.hpp"
#include "Menu.h"

class MenuScreen {
public:
    MenuScreen();
    ~MenuScreen();

public:
    void							run();
    void							processEvents();
    void							update();
    void 							render();

public:
    double							getPWidth();
    double							getPHeight();

private:
    sf::RenderWindow				PrincipalMenu;
    sf::RectangleShape				background;
    sf::Texture						menuTexture;
    sf::Sprite						menuSprite;
    sf::Texture						backgroundTexture;
    double                          pWidth, pHeight;
};

