#include "SFML/Graphics.hpp"
#include "iostream"
#include "Menu.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(60);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type) {
				
				case sf::Event::KeyReleased:
					switch (event.key.code) {
						case sf::Keyboard::Up:
							menu.moveUp();
							break;
						case sf::Keyboard::Down:
							menu.moveDown();
							break;
						
						case sf::Keyboard::Return:
							if (menu.getSelectedItem() == 0) {
								std::cout << "Play" << std::endl;
							}
							else if (menu.getSelectedItem() == 1) {
								std::cout << "Options" << std::endl;
							}
							else if (menu.getSelectedItem() == 2) {
								window.close();
							}
							break;
						default:
							break;
					}
					break;
					
					case sf::Event::Closed:
						window.close();
						break;
				default:
					break;
			}
		}

		window.clear();
		menu.drawMenuText(window);
		window.display();

	}

	return 0;

}

