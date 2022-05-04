#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("Assets/Fonts/Roboto-Black.ttf")) {
		std::cout << "Error loading font" << std::endl;
	}
	
	menuText[0].setFont(font);
	menuText[0].setFillColor(sf::Color::Red);
	menuText[0].setString("Play");
	menuText[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menuText[1].setFont(font);
	menuText[1].setFillColor(sf::Color::White);
	menuText[1].setString("Options");
	menuText[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

	menuText[2].setFont(font);
	menuText[2].setFillColor(sf::Color::White);
	menuText[2].setString("Exit");
	menuText[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

Menu::~Menu() {

}

void Menu::drawMenuText(sf::RenderWindow &window) {
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menuText[i]);
	}

}

void Menu::moveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menuText[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		std::cout << std::to_string(selectedItemIndex) << std::endl;
		menuText[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menuText[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		std::cout << std::to_string(selectedItemIndex) << std::endl;
		menuText[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::getSelectedItem() {
	return selectedItemIndex;
}