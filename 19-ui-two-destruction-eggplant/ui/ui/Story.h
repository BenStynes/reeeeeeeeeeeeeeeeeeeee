#pragma once

#ifndef STORY
#define STORY
#include <SFML\Graphics.hpp>

#include "Xbox360Controller.h"
#include <cstring>
#include <iostream>
class Game;

class Story
{
public:
	Story(Game& game, sf::Font font);
	~Story();

	void update(sf::Time deltaTime,Xbox360Controller &t_controlor);
	void render(sf::RenderWindow& window);
	void advanceText();
	void advanceToGameplay();
private:
	Game* m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_comicSans;
	sf::Text m_textMessage;
	sf::Text m_textMessage2;
	sf::Text m_textMessage3;
	sf::Text m_name;
	int endlineCount;
	sf::Sprite m_background;
	sf::Texture m_backgroundTexture1;
	sf::Texture m_backgroundTexture2;
	sf::Texture m_backgroundTexture3;
	sf::Texture m_spriteTexture;
	sf::Sprite m_Sprite;
	sf::Sprite m_textbox;
	sf::Texture m_textureBox;
	std::string m_story1;
	std::string m_nameString = "? ? ?";
	bool draw = true;
	sf::Clock m_clock;
	sf::Clock m_nameTimer;
	int spacePressedCount = 0;
	bool textFinished = false;
	bool redDraw = true;
	double time = 0.05;

};
#include "Game.h"
#endif 


