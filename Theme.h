#pragma once

#ifndef THEME_H
#define THEME_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include <vector>
#include "iostream"

using std::vector;
using std::string;

class Theme
{
	public:
		Theme();
		~Theme();
	
		//FUNCION PARA LAS PREGUNTAS
		void                    setArtQuestions();
		void                    setArtAnswers();
		
		void                    setPoliticsQuestions();
		void                    setPoliticsAnswers();
		
		void                    setScienceQuestions();
		void                    setScienceAnswers();

		void                    setHistoryQuestions();
		void                    setHistoryAnswers();
		
		void					setQuestions();
		void                    setAnswers();
		int						genRandomNum();

		//Funcion para poner el background
		void                    setBackground(sf::Texture& texture, sf::IntRect rect);
		
		//Funcion para poner la textura de la caja
		void                    setBox(sf::Texture& texture, sf::Vector2u rect);
		
		void                    drawAt(sf::RenderTarget& target);

		vector<string>			getQuestions();

	private:
		sf::Sprite              background;
		vector<string>			questions;
		vector<string>			answers;
};


#endif // !THEME_H
