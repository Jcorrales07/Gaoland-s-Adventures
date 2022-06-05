#include "Menu.h"
#include <iostream>
#include "MenuScreen.h"

using namespace std;
using namespace sf;

Menu::Menu(float width, float height) {

	/* Resumen: asigna btntxt[i] una textura y el sprite agarra la textura
	 y lo pone en una posicion float de Vector2f*/
	if(!btntxt[0].loadFromFile("Assets/img/btns/btnJugar.png"))
		cout << "No se pudo cargar JUGAR.jpg";
	btnsp[0].setTexture(btntxt[0]);
	btnsp[0].setPosition(Vector2f(width / 2.5, height - 800.0f));

	if (!btntxt[1].loadFromFile("Assets/img/btns/btnOpciones.png"))
		cout << "No se pudo cargar OPCIONES.jpg";
	btnsp[1].setTexture(btntxt[1]);
	btnsp[1].setPosition(Vector2f(width / 2.5, height - 600.0f));

	if (!btntxt[2].loadFromFile("Assets/img/btns/btnSalir.png"))
		cout << "No se pudo cargar SALIR.jpg";
	btnsp[2].setTexture(btntxt[2]);
	btnsp[2].setPosition(Vector2f(width / 2.5, height - 400.0f));

	selectedItemIndex = 0;
}

Menu::~Menu() {

}

// Dibuja los botones en pantalla
void Menu::drawMenuImg(RenderWindow &window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		window.draw(btnsp[i]);
}

/* clicBtn Retorna un valor entero basado en selectedIndexItem
*  0 - JUGAR
*  1 - OPCIONES
*  2 - SALIR
*/

int Menu::clicBtn(RenderWindow& window) {
	// Evalua si hizo clic izquierdo
	if (Mouse::isButtonPressed(Mouse::Left)){
		//BOTON JUGAR
		if (btnsp[0].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
			return 0;
		else if (btnsp[1].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
			return 1;
		else if (btnsp[2].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
			return 2;
	}
	// No hubo clic en nada
	return -1;
}

int Menu::getSelectedItem() {
	return selectedItemIndex;
}