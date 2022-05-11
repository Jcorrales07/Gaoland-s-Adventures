//
// Created by shello on 05-05-22.
//

#include "Game.h"

void Game::initVariables()
{
    this->endGame =false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxObjetoCarga = 10;
}

void Game::initWindow()
{
    //this-> videoMode = sf::VideoMode::getDesktopMode();
    this-> videoMode = sf::VideoMode(1920,1080);
    this-> window = new sf::RenderWindow(this->videoMode, "Prueba de Movimientos de Usuario", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(240);
}

//constructor and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

//Funciones
const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->sfmlwindowEvent))
    {
        //Aquí recibo los eventos en mi Ventana
        switch (this->sfmlwindowEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->sfmlwindowEvent.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::spawnObjetoCarga()
{
    //timer
    if(this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else
    {
        if (this->objetoCargaS.size() < this->maxObjetoCarga)
        {
            this->objetoCargaS.push_back(objetoCarga(*this->window));
            this->spawnTimer = 0.f;
        }
    }
}

void Game::update()
{
    this->pollEvents();

    this->spawnObjetoCarga();
    this->player.update(this->window);
}

void Game::render()
{
    //clear el frame anterior.
    this->window->clear();

    //Render aqui del Player
    this->player.render(this->window);

    for (auto i : this->objetoCargaS) {
        i.render(*this->window);
    }

    this->window->display();
}