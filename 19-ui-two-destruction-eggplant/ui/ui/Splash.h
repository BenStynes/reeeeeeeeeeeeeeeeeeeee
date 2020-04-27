#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

class Splash
{
public:

	Splash(Game& game);
	~Splash();
	void update();
	void render(sf::RenderWindow& window);
	bool m_licenseScreenOver = false;

private:
	
	Game* m_game;

	void init();
	void movement();


	sf::Clock m_textOn;
	sf::Clock m_textOff;
	int m_letter = 0;
	int m_sheildMovement = 30;
	bool onscreen = true;

	std::string m_splashString = "Kingdom of Avilon";
	sf::Text m_splashText;
	sf::Font m_splashFont;
	std::string m_continueString = "press a to Contine";


	sf::Texture m_shieldTexture;
	sf::Sprite sheildSprite;

	int m_spaceCount = 0;
	int m_shieldCount = 0;
	sf::Vector2f m_sheildPosition{ 200, 200 };
	sf::Vector2f m_splashPosition{ 200, 200 };
}; 


