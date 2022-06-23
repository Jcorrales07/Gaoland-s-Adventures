#include "MysteryBoxes.h"
#include <iostream>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

// variables locales
int posAddon = 200, const npregunta,
nbloques = 4, nfondo = 0;
float sec = 0.00f, finalsec = 0.00f;
bool blockclic = false, blockscaled = false, fondofinal = false,
preguntame = false, salir = false, respcorrecta = false,
executeonce = true, executeonce2 = true;

// Constructor
MysteryBoxes::MysteryBoxes()
	: N2M3Screen(sf::VideoMode(1024, 720), "Minijuego")
{
	N2M3Screen.setFramerateLimit(60);
	this->pWidth = N2M3Screen.getSize().x;
	this->pHeight = N2M3Screen.getSize().y;
	this->run();
}

MysteryBoxes::~MysteryBoxes()
{
}

void MysteryBoxes::setRandom() {
	npregunta = 1 - rand() % 5;
}

void MysteryBoxes::setText() {
	// N2M3Screen.clear();
	f.loadFromFile("Assets/Fonts/OcrAExt.ttf");
	t.setFont(f);
	t.setFillColor(sf::Color::Black);
	t.setCharacterSize(24);
	if (executeonce2) {
		t.setOrigin(t.getLocalBounds().width / 2, t.getLocalBounds().height / 2);
		t.setPosition(pWidth / 2, pHeight / 5);
		executeonce2 = false;
	}
	if (preguntame)
		t.setString("SOLO TIENES 15 SEGUNDOS");
	if (!respcorrecta && nfondo == 2)
		t.setString("SE ACABO EL TIEMPO");
	N2M3Screen.draw(t);
}

void MysteryBoxes::refresh() {
	N2M3Screen.clear();
	dibujarFondo(nfondo);
	if (nfondo == 0) {
		dibujarBloque(nbloques);
	}
	if (nfondo == 1) {
		dibujarPregunta();
		setText();
	}
	if (nfondo == 2) {
		mostrarResultado(respcorrecta);
	}
	N2M3Screen.display();
}

void MysteryBoxes::run() {

	sf::Event event;
	// Carga todo en un inicio
	setRandom();
	playMusic();
	dibujarFondo(nfondo);
	dibujarBloque(nbloques);
	N2M3Screen.display();
	// While este abierta la ventana
	while (N2M3Screen.isOpen()) {
		while (N2M3Screen.pollEvent(event)) {
			// responde al hacer clic en bloques
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !blockclic) {
				if (clicBtn(N2M3Screen) != 0 && !blockclic) {
					blockclic = true;
					std::cout << "FUNCIONOOOOOO" << std::endl;
					blockclic = false;
				}
			}
			// Cerrar ventana
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || salir)
				N2M3Screen.close();
			// Si esta la imagen del aviso una vez prsionado el bloque
			if (preguntame) {
				if (finalsec > 10.00f) {
					respcorrecta = false;
					fondofinal = true;
					preguntame = false;
					mostrarResultado(false);
					nfondo = 2;
				}
				if (event.type == sf::Event::KeyReleased) {
					if (sf::Keyboard::B && npregunta != 2) {
						respcorrecta = true;
						fondofinal = true;
						nfondo = 2;
						preguntame = false;
					}
					else if (sf::Keyboard::C && npregunta == 2) {
						respcorrecta = true;
						fondofinal = true;
						nfondo = 2;
						preguntame = false;
					}
					else {
						respcorrecta = false;
						fondofinal = true;
						preguntame = false;
						nfondo = 2;
					}
				}
			}
			// Si esta la imagen de la pregunta y que seleccione la respuesta
			if (fondofinal) {
				mostrarResultado(respcorrecta);
				if (event.type == sf::Event::KeyReleased)
					salir = true;
			}
			if (!nbloques) {
				fondofinal = true;
				nfondo = 2;
			}
		}

		// refresh la pantalla
		sec = elapsed.asSeconds();
		elapsed = time.getElapsedTime();
		if (sec > 0.2f) {
			if (preguntame) {
				finalsec += sec;
				std::cout << finalsec << " segundos \n";
			}

			time.restart();
			sec = 0;
			refresh();
		}
	}
}

// Tocar musica
void MysteryBoxes::playMusic() {
	
	if (!n2m3music.openFromFile("Assets/sounds/nivel2/m3/minigamemusic.wav"))
		std::cout << "Error: no musica" << std::endl;
	
	n2m3music.play();
	n2m3music.setLoop(true);
	n2m3music.setVolume(50);
}


// Crea los bloques necesarios segun la variable nbloque
void MysteryBoxes::dibujarBloque(int numerobloques) {
	if (!numerobloques) {
		nfondo = 2;
		return;
	}
	for (int i = 0; i < numerobloques; i++) {
		// carga texturas
		blocktxt[i].loadFromFile("Assets/img/textures/bloque sorpresa.png");
		blockspr[i].setTexture(this->blocktxt[i]);
		// Este booleano EVITA que se encoja infinitamente
		if (!blockscaled) {
			blockspr[i].scale(0.7f, 0.75f);
			blockspr[i].setOrigin(blockspr[i].getTexture()->getSize().x / 2, blockspr[i].getTexture()->getSize().y / 2);
		}
		std::cout << "Bloques cargada";
		// dibujar bloque
		blockspr[i].setPosition((pWidth / (numerobloques + 1)) * (i + 1), pHeight / 2);
		posAddon += 200;
		// tenerlo listo para mostrar en pantalla
		N2M3Screen.draw(blockspr[i]);
	}
	blockscaled = true;
	posAddon = 200;
}


int MysteryBoxes::clicBtn(sf::RenderWindow& window) {
	// Evalua si hizo clic izquierdo
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int i = 0; i < nbloques; i++)
		{
			if (blockspr[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
				std::cout << "Selecionaste el bloque: " << nbloques << std::endl;
				if (i == (npregunta - 1)) {
					std::cout << "ESTE ES EL BLOQUE CORRECTO DE PREGUNTAME" << std::endl;
					blockclic = true;
					nfondo = 1;
					preguntame = true;
					return 1;
				}
				if (nbloques)
					nbloques--;
				return 1;
			}
		}
	}
	// No hubo clic en nada
	return 0;
}

void MysteryBoxes::mostrarResultado(bool escorrecto) {
	N2M3Screen.clear();
	txt.loadFromFile("Assets/img/nivel2/m3/plantillapreguntas.png");
	spr.setTexture(txt);
	std::cout << "Pantalla cargada";
	// evalua si esta bueno o no
	if (escorrecto) {
		auxtxt.loadFromFile("Assets/img/nivel2/m3/ok.png");
		auxspr.setTexture(auxtxt);
		auxspr.setOrigin(auxtxt.getSize().x / 2, auxtxt.getSize().y / 2);
		auxspr.setPosition(pWidth / 2, pHeight / 2);
		std::cout << "Es correcto" << std::endl;
	}
	else if (!escorrecto) {
		auxtxt.loadFromFile("Assets/img/nivel2/m3/notok.png");
		auxspr.setTexture(auxtxt);
		auxspr.setOrigin(auxtxt.getSize().x / 2, auxtxt.getSize().y / 2);
		auxspr.setPosition(pWidth / 2, pHeight / 2);
		std::cout << "No es correcto" << std::endl;
	}
	N2M3Screen.draw(spr);
	N2M3Screen.draw(auxspr);
	N2M3Screen.display();
}

void MysteryBoxes::Tiempo(int sec) {
	f.loadFromFile("Assets/fonts/OcrAExt.ttf");
	t.setFont(f);
	t.setCharacterSize(18);
	t.setPosition(pWidth / 2.5, pHeight / 2.5 + pHeight / 3.5);
	while (sec < 10) {
		t.setString("TIEMPO RESTANTE: " + sec);
	}
	N2M3Screen.draw(t);
	N2M3Screen.display();
}


// dibuja el fondo dependiendo de la situacion
void MysteryBoxes::dibujarFondo(int frame) {
	switch (frame) {
	case 0: // Pantalla inicial
		txt.loadFromFile("Assets/img/nivel2/m3/n2m3fondo.png");
		break;
	case 1: // fondo para preguntas
		txt.loadFromFile("Assets/img/nivel2/m3/plantillapreguntas.png");
		break;
	case 2: // Fondo para felicitaciones
		txt.loadFromFile("Assets/img/nivel2/m3/n2m3fondoplantilla.png");
		break;
	}
	spr.setTexture(txt);
	spr.scale(pWidth / spr.getTexture()->getSize().x, pHeight / spr.getTexture()->getSize().y);
	std::cout << "Pantalla cargada";
	N2M3Screen.draw(spr);
}

void MysteryBoxes::dibujarPregunta() {
	txt.loadFromFile("Assets/img/nivel2/m3/plantillapreguntas.png");
	// TEXTO A DESPLEGAR RANDOM
	switch (npregunta) {
	case 1:
		auxtxt.loadFromFile("Assets/img/nivel2/m3/pregunta1.png");
		break;
	case 2:
		auxtxt.loadFromFile("Assets/img/nivel2/m3/pregunta2.png");
		break;
	case 3:
		auxtxt.loadFromFile("Assets/img/nivel2/m3/pregunta3.png");
		break;
	case 4:
		auxtxt.loadFromFile("Assets/img/nivel2/m3/pregunta4.png");
		break;
	case 5:
		auxtxt.loadFromFile("Assets/img/nivel2/m3/pregunta5.png");
		break;
	}
	auxspr.setTexture(auxtxt);
	auxspr.setOrigin(auxtxt.getSize().x / 2, auxtxt.getSize().y / 2);
	auxspr.setPosition(pWidth / 2, pHeight / 2);
	N2M3Screen.draw(auxspr);
}

