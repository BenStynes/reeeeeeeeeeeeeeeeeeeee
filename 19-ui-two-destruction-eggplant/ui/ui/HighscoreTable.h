#pragma once
#ifndef HIGHSCORETABLE
#define HIGHSCORETABLE

#include <SFML/Graphics.hpp>

#include <iostream>
#include "Game.h"

class HighscoreTable
{



	
	public:
		HighscoreTable(Game& game);
		~HighscoreTable();
		void Draw(sf::RenderWindow& t_window);
		void update(Xbox360Controller& t_control, sf::RenderWindow& t_window);

	private:
		Game* m_game;
		sf::Text text;
		sf::Font font;
		std::string name = "---";
		std::string alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
		char playernameletter;
		int nameTracker= 0;
		int i = 1;
		void setupText();
		void moveToCredits(Xbox360Controller& t_control);
		void moveToOptions(Xbox360Controller& t_control);




};
#endif 