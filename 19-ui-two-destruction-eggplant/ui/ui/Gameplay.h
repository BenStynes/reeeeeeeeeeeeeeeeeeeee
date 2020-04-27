#pragma once
#ifndef GAMEPLAY
#define GAMEPLAY

#include <SFML/Graphics.hpp>

#include <iostream>
#include "Game.h"


class Gameplay
{
public:
	Gameplay(Game& game);
	~Gameplay();
	void Draw(sf::RenderWindow& t_window);
	void update(Xbox360Controller& t_control, sf::RenderWindow& t_window);
	
private:
	Game* m_game;
	sf::Text text;
	sf::Font font;
	void setupText();
	void moveToCredits(Xbox360Controller& t_control);
	void moveToOptions(Xbox360Controller& t_control);
};

#endif 

