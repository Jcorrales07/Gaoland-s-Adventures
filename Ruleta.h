#pragma once

#ifndef RULETA_H
#define RULETA_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "stdio.h"
#include "windows.h"
#include "iostream"
#include "Theme.h"

using std::cout;
using std::cerr;
using std::endl;
using std::vector;

class Ruleta
{
	public:
		Ruleta();
		~Ruleta();

	public:
		//Window functions
		void						initWindow();
		void						run();
		void						processEvents();
		void						update();
		void						render();

		//Window states
		void						renderRoulette();
		void                        renderNotification();
		void						renderArtTheme();
		void                        winBackground();
		void						renderScienceTheme(); // esta tampoco
		void						setHistoryGame(); // ya no se usa la funcion por que ya se puede hacer desde el evento
		void						renderPoliticsTheme(); // y esta

		// Select a theme
		int                         genRandomNum();
		void                        setStateTheme();
		
		//Texturas y font
		void						initTexture();
		void						initFont();

		//Evento para cuando se toque el espacio
		void						onSpacePressed(sf::Event &event);
		//void						onSpaceReleased(sf::Event &event);
		
		// para seguir con el nivel 3
		//void                        onEnterPressed(sf::Event &event);

		//animacion de la ruleta
		void						animationRoulette();
		void						resetClock();
		void						spinRoulette();

		// animacion de la caja
		void                        animationBox();

		// win animation
		void                        winAnimationBg();

		// notificacion
		void                        enterPressed(sf::Event &event);

		//primer minijuego
		// funciones para las preguntas
		void                        putQuestInScreen(string question, sf::Color color);
		void                        setUpBoxesInScreen(sf::Color color);
		void                        putAnswersInScreen();
		void                        nextQuestion(vector<string> questions, vector<string> answers, sf::Color color, int index);
		void                        onKeyAnswerPressed(sf::Event& event, vector<string> questions, vector<string> answers, sf::Color color);
		void                        setUpAnimBoxes();
		void                        drawAnimBoxes();
		void                        drawBgBoxes();
		void                        setFont();
		void                        drawAnsText();

		// corazones
		void                        drawHearts(int lives);
		void                        setUpHearts();
		
		// timer
		void                        resetTimer();
		void                        increaseSeconds();

		// funcion para checkear respuesta
		void                        checkAnswers(int &index, sf::Event &event);
		void                        decreaseLives();

		// funcion para checkear si se termino el tiempo
		void                        checkLimitTime();

		// funcion para checkear las vidas del jugador
		void                        checkLives();
		
	private:
		sf::RenderWindow			window;
		
		sf::Texture                 winTxt;
		sf::Texture					ruletaTexture, 
									bgTexture,
									btnSpaceTxt,
									themesTextures,
									notificationTxt,
									heartTxt,
									boxTexture;
		
		sf::Sprite					ruletaSprite;
		sf::Sprite					bgSprite;
		sf::Sprite					btnSpaceSprt;
		sf::Sprite					notificationSprt;
		sf::Sprite					winSprt;
		sf::Sprite					gameOverSprt;
		sf::Sprite					boxSprites[4];
		sf::Sprite					hearts[3];
		
		
		sf::Font					font;
		sf::Text					text;

		//Variables para la animacion de la ruleta
		sf::Clock                   timer, clock;
		Animation                   animation;
		Animation                   boxAnimation;
		Animation                   winAnimation;
		float                       deltaTime = 0.0f;
		bool                        isSpinning = false;

		// Window booleans states
		bool                        isRouletteShown;
		bool						isArtThemeShown = false;
		bool						isScienceThemeShown = false;
		bool						isHistoryThemeShown = false;
		bool						isPoliticsThemeShown = false;
		bool                        isOnGame;
		int                         stateNum;

		// Window notifications
		bool                        isNotificationShown = true;

		// Class states
		Theme						art;
		Theme						science;
		Theme						history;
		Theme						politics;

		//Primer minijuego
		// Question variables
		sf::Text					questionText,
									timerTxt,
									answerText[4];

		sf::Text                    congratulations, enterIns;
		
		sf::RectangleShape          questionBackground,
									answerBackground[4];
		
		int                         questionIndex;
		int                         lives;
		sf::Clock                   timeLeft;
		int                         timePassed = 0;
};

#endif // !RULETA_H
