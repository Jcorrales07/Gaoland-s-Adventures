#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("Assets/Fonts/OcrAExt.ttf")) {
		std::cout << "Error loading font" << std::endl;
	}

	/*
	menuImg[0].setSize(sf::Vector2f(1000, 1000));
	sf::Texture btn1;
	btn1.loadFromFile("assets/img/btns/btnJugar.jpg");
	menuImg[0].setTexture(&btn1);*/
	//menuImg[0].setFillColor(sf::Color::Blue);

	menuImg[0].setFont(font);
	menuImg[0].setFillColor(sf::Color::Red);
	menuImg[0].setCharacterSize(70);
	menuImg[0].setString("Play");
	menuImg[0].setPosition(sf::Vector2f(width / 6.0, height - 800.0f));

	menuImg[1].setFont(font);
	menuImg[1].setFillColor(sf::Color::White);
	menuImg[1].setCharacterSize(70);
	menuImg[1].setString("Options");
	menuImg[1].setPosition(sf::Vector2f(width / 6.0, height - 700.0f));

	menuImg[2].setFont(font);
	menuImg[2].setFillColor(sf::Color::White);
	menuImg[2].setCharacterSize(70);
	menuImg[2].setString("Exit");
	menuImg[2].setPosition(sf::Vector2f(width / 6.0, height - 600.0f));

	selectedItemIndex = 0;
}

Menu::~Menu() {

}

void Menu::drawMenuImg(sf::RenderWindow &window) {
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menuImg[i]);
	}

}

void Menu::moveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menuImg[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		std::cout << std::to_string(selectedItemIndex) << std::endl;
		menuImg[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menuImg[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		std::cout << std::to_string(selectedItemIndex) << std::endl;
		menuImg[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::getSelectedItem() {
	return selectedItemIndex;
}