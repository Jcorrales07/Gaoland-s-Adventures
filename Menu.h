#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3   

class Menu {
	public:
		//Constructor
		Menu(float width, float height);
		
		//Destructor
		~Menu();
		
		//Functions
		void                drawMenuText(sf::RenderWindow &window);
		void                moveUp();
		void				moveDown();
		int				getSelectedItem();

	private:
		int				    selectedItemIndex;
		sf::Font		    font;
		sf::Text	        menuText[MAX_NUMBER_OF_ITEMS];
}; 
