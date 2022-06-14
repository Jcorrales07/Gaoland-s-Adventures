#pragma once

#ifndef CAR_H
#define	CAR_H

#include "SFML/Graphics.hpp"

class Car
{
	private:
		//Movement
		sf::Vector2f			movement;
		sf::Texture				carTexture;
	
	public:
		Car();
		~Car();

		//Car texture and sprite functions
		void					setTexture();




		//Core
		void                    render(sf::RenderTarget& target);
		void                    update();


		// el codigo de la tecla event.key.code y que si el codigo es sf::Keyboard::Left, ::Right, ::A, y ::D, se mueva el carro
		void                    moveCar(sf::Event& event);
		sf::Sprite				carSprite;

		void                    setPositionX(float);
		void                    setPositionY(float);

		float                    getPositionX();
		float                    getPositionY();
};

#endif // !CAR_H
