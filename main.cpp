#include "iostream"
#include "SFML/Graphics.hpp"

using std::cout; using std::endl;


int main() {

	cout << " Este es el main " << endl;
	cout << "...No tocar nada... " << endl;

    // prueba de SFML
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}