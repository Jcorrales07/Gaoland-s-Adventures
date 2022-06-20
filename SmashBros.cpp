#include "SmashBros.h"

SmashBros::SmashBros()
	: smashWindow(sf::VideoMode(1366, 768), "Smash Bros"), playerLife(5), enemyLife(5)
{
	run();
}

SmashBros::~SmashBros()
{
}

void SmashBros::run()
{
	loadTextures();

	while (smashWindow.isOpen()) {

		processEvents();
		update();
		render();

	}

}

void SmashBros::processEvents()
{
	sf::Event event;
	
	while (smashWindow.pollEvent(event)) {
		
		//cerrar la ventana
		if (event.type == sf::Event::Closed) {
			smashWindow.close();
		}

	}

}

void SmashBros::update()
{
}

void SmashBros::render()
{
	smashWindow.clear();

	// draw section
	smashWindow.draw(backgroundSprite);
	
	//dibujar las vidas de los jugadores
	drawLives(playerLife, heartsPlayer);
	drawLives(enemyLife, heartsEnemy);

	smashWindow.display();
}

void SmashBros::loadTextures()
{

	if (!backgroundTexture.loadFromFile("assets/img/bgs/finalDestinationBg.jpg")) 
		std::cerr << "ERROR:: no se pudo cargar la textura (bg)" << std::endl;

	backgroundSprite.setTexture(backgroundTexture);
	
	if (!heartTexture.loadFromFile("assets/img/textures/hardcoreHeart2.png"))
		std::cerr << "ERROR:: no se pudo cargar la textura (hearts)" << std::endl;
		
	setUpHeartSprites();
		
}

void SmashBros::setUpHeartSprites()
{
	for (int i = 0; i < 5; i++) {
		heartsPlayer[i].setTexture(heartTexture);
		heartsEnemy[i].setTexture(heartTexture);

	}

	heartsPlayer[0].setPosition(50 * 1, 30);
	heartsPlayer[1].setPosition(50 * 2, 30);
	heartsPlayer[2].setPosition(50 * 3, 30);
	heartsPlayer[3].setPosition(50 * 4, 30);
	heartsPlayer[4].setPosition(50 * 5, 30);

	heartsEnemy[0].setPosition(1056, 30);
	heartsEnemy[1].setPosition(1106, 30);
	heartsEnemy[2].setPosition(1156, 30);
	heartsEnemy[3].setPosition(1206, 30);
	heartsEnemy[4].setPosition(1256, 30);
}

void SmashBros::drawLives(int amountLife, sf::Sprite hearts[])
{
	for (int i = 0; i < amountLife; i++)
		smashWindow.draw(hearts[i]);
}
