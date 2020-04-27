#ifndef OPTIONS
#define OPTIONS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h"
#include "Xbox360Controller.h"

class Options
{
private:
	Game* m_game;
	sf::Music menuMusic;
	sf::Music gameMusic;
	sf::Music endMusic;
	//const int  MAX_OPTIONS = 3;
	sf::RectangleShape options[3];
	sf::Text menuText[3];

	sf::Text subText[3];
	
	sf::Text titleText;
	sf::Texture m_radio;
	sf::Texture m_check;
	sf::Texture m_slide;
	sf::Texture m_tick;
	sf::Texture m_radio2;
	sf::Texture m_radio3;
	sf::Texture m_slideButt;


	sf::Texture m_texturePointer;
	sf::Texture m_backgroundTexture;

	sf::Sprite m_OptionsSprite[3];
	sf::Sprite m_pointerSprite;
	sf::Sprite m_backgroundSprite;

	float sizeIncrease[3];


	sf::IntRect mmHoveringButton{ 3,7,28,16 };


	bool existing{ true };
	bool optionsMenu{ false };
	bool newGame{ false };
	bool closeGame{ false };
	sf::Font overallText;
	int optionCounterUp;
	int optionCounterDown;


	bool getExisting();
	void setExisting(bool t_showing);
	void advanceToNewGame();
	void advanceToOptions();
	void exitGame();
	bool getNewGame();
	bool getOptionsMenu();
	bool getExitGame();
	void returnToOptions();

	void buttonsHovered(Xbox360Controller& t_control, sf::RenderWindow& t_window);
public:
	Options(Game& game);
	~Options();
	void movePointer(Xbox360Controller& t_control);
	void setupText();

	void Draw(sf::RenderWindow& t_window);
	void update(Xbox360Controller& t_control, sf::RenderWindow& t_window);

	/*void setupAudio();
	void playMenuAudio();
	void gameplayAudio();*/

};

#endif 
