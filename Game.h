#pragma once

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <vector>
//Este incluye las librerias de SFML, no need to copy again, están en Player.h
#include "Player.h"
#include "objetoCarga.h"

class Game {

private:
    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event sfmlwindowEvent;

    Player player;
    std::vector<objetoCarga> objetoCargaS;

    float spawnTimerMax;
    float spawnTimer;
    int maxObjetoCarga;

    void initVariables();
    void initWindow();

public:
    //Constructor y Desconstructor del Juego
    Game();
    ~Game();

    //Getters

    //Setters

    //Funciones
    const bool running() const;
    void pollEvents();

    void spawnObjetoCarga();
    void update();
    void render();

};


#endif //GAME_H
