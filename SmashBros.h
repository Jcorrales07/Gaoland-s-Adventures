#pragma once


#ifndef SMASH_BROS_H
#define SMASH_BROS_H

#include "Animation.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "iostream"
#include "string"
#include <vector>


using std::vector;
using std::string;

class SmashBros
{
	
	//Variables
	private:
		sf::RenderWindow				smashWindow;
		
		sf::Texture						backgroundTexture;
		sf::Sprite						backgroundSprite;
		
		//vidas 
		sf::Texture						heartTexture;
		sf::Sprite                      heartsPlayer[5];
		sf::Sprite                      heartsEnemy[5];

		//Dinamica de vida
		int                             playerLife;
		int                             enemyLife;

		// Fuente
		sf::Font   						font;
		
		// puntos
		string							scoretxt;
		int                             score;
		sf::Text						scoreText;

		//delta time
		sf::Clock						deltaTimeTimer;
		float							deltaTime;

		//Mario animation
		sf::Texture						marioTxts[6];

		sf::Sprite						marioSprtIdle;
		sf::Sprite						marioSprtDolido;
		sf::Sprite						marioSprtAtacando;
		sf::Sprite						marioSprtCorriendo;
		sf::Sprite						marioSprtCorriendoAtras;
		sf::Sprite						marioSprtCelebrando;

		Animation						marioIdle;
		Animation						marioDolido;
		Animation						marioAtacando;
		Animation						marioCorriendo;
		Animation						marioCorriendoAtras;
		Animation						marioCelebrando;

		void							setMarioTextures();

		void                            animIdleMario();
		void							animHarmedMario();
		void							animAttackMario();
		void							animRunMario();
		void							animRunBackMario();
		void							animCelebrationMario();

		void							attackMario();

		//Bowser animation
		sf::Texture						bowserTxts[5];

		sf::Sprite						bowserSprtIdle;
		sf::Sprite						bowserSprtDolido;
		sf::Sprite						bowserSprtAtacando;
		sf::Sprite						bowserSprtCorriendo;
		sf::Sprite						bowserSprtCorriendoAtras;

		Animation						bowserIdle;
		Animation						bowserDolido;
		Animation						bowserAtacando;
		Animation						bowserCorriendo;
		Animation						bowserCorriendoAtras;

		void							setBowserTextures();

		void                            animIdleBowser();
		void							animHarmedBowser();
		void							animAttackBowser();
		void							animRunBowser();
		void							animRunBackBowser();
		
		//Preguntas
		vector<string>					questions;
		sf::Text                        question;
		
		vector<string>					answers;
		sf::Text						answer[4];

		int								index = 0;
		bool							isAnswered;

		//Tiempo
		sf::Clock						time;
		int                             scsPassed;
		sf::Text						timerSeconds;

		// musica y sonido
		sf::Music						bgMusic;
		sf::SoundBuffer					bufferHit;
		sf::SoundBuffer					bufferWin;
		sf::Sound						hitSound;
		sf::Sound						winSound;

		// Notificacion
		bool							isNotificationShown;
		sf::Texture						notificationTxt;
		sf::Sprite						notificationSprt;
	
		
	//Funciones
	private:
		void                            initResources();
		
		void							run();
		void							processEvents();
		void							update();
		void							render();
		void							renderNotification();
		
		void							loadTextures();

		void                            loadFont();
		
		void                            setUpHeartSprites();
		
		void                            drawLives(int amountLife, sf::Sprite hearts[]);

		//preguntas
		void                            loadQuestions();
		void							loadAnswers();
		void                            checkAnswers(sf::Event &event);
		void                            caseKey(sf::Event& event, int codeKey);
		void							checkTime();

		//Answers
		void							setupAnswers();
		void							setAnsForQuestionNumber(int index);
		void							drawAnsText();
		
		//animaciones
		void                            setUpAnimations();

		//Tiempo
		void                            increaseSeconds();
		void                            resetSeconds();

		void							reset();

		//Score
		void							updateScore();

		//music
		void							loadSounds();

		// notification
		void							disableNotification(sf::Event &event);

		
	public:
		SmashBros();
		~SmashBros();

};

#endif // !SMASH_BROS_H
