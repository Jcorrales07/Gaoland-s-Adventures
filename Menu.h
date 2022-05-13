#pragma once

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3   

using namespace sf;
class Menu {
	public:
		//Constructor
		Menu(float width, float height);
		
		//Destructor
		~Menu();
		
		//Variables
		sf::Sprite	        btnsp[MAX_NUMBER_OF_ITEMS];

		//Functions
		void                drawMenuImg(RenderWindow &window);
		int					clicBtn(RenderWindow& window);
		int				    getSelectedItem();

	private:
		int				    selectedItemIndex;
		Texture				btntxt[MAX_NUMBER_OF_ITEMS];;
		double              mWidth, mHeight;
}; 
