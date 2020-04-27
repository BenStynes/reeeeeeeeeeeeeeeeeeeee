#ifndef MAINMENU
#define MAINMENU

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <iostream>
#include "NormalButton.h"
#include "Xbox360Controller.h"
class Game;

class MainMenu
{
private:
	
	

	

	//std::array<NormalButton, 7> m_buttons;
	GUI* m_currentButton{ nullptr };



	

	sf::IntRect mmHoveringButton{3,7,28,16};

	
	bool existing{ true };
	bool optionsMenu{ false };
	bool newGame{ false };
	bool closeGame{ false };

	int optionCounterUp = 0;
	int optionCounterDown = 0;
	
	 Game *m_game;
	

	
	
public:
	MainMenu(Game& game);
	~MainMenu();
	void movePointer(Xbox360Controller &t_control);
	void setupText();
	void Draw(sf::RenderWindow &t_window);
	void update(Xbox360Controller &t_control, sf::RenderWindow& t_window);
	static void toOptions();
	 static void toGamePlay();
	 static void toHighScore();
	 static void toCredits();
	//void Exit();
	/*void setupAudio();
	void playMenuAudio();
	void gameplayAudio();*/

};
#include "Game.h"

#endif