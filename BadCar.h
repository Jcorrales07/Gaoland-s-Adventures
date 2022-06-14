//redCar.h***
#pragma once

#ifndef BRICKGAME_REDCAR_H
#define BRICKGAME_REDCAR_H

#include "SFML/Graphics.hpp"

class BadCar
{
    private:
        //Movement
        sf::Vector2f velocidad;
        float rapidez = 1.0f;
	
    public:
        BadCar();

        ~BadCar();

        //Car texture and sprite functions
        void setTexture();

        //Core
        void renderRedCar(sf::RenderTarget& target) const;

        void update();

        // Movimiento automatico del carro
        virtual void moveCarRed1(sf::RenderWindow& render_window);
        virtual void moveCarRed2(sf::RenderWindow& render_window);
        virtual void moveCarRed3(sf::RenderWindow& render_window);
        virtual void moveCarRed4(sf::RenderWindow& render_window);

        //Textura general de los carros
        sf::Texture carTextures;
        sf::Texture getCarTextures();


        sf::Sprite carSprite1;
        //sf::Texture carTexture2;
        sf::Sprite carSprite2;
        //sf::Texture carTexture3;
        sf::Sprite carSprite3;
        //sf::Texture carTexture4;
        sf::Sprite carSprite4;

        void setRapidez(float rapidez);
        float getRapidez() const;

};

#endif //BRICKGAME_REDCAR_H

