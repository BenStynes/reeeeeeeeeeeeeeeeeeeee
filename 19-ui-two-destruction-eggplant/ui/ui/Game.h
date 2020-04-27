#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include "License.h"
#include "Story.h"
#include "GAMESTATES.h"
#include "Xbox360Controller.h"


//#include "Credits.h"
class License;
class Story;
class MainMenu;
class Gameplay;
class Options;
class HighscoreTable;

class Game
{
public:
	Game();
	~Game();

	void run();
	s_GameStates m_gameStates = s_GameStates::s_story;
	void setGameState(s_GameStates gameState);
	//NameData m_name;

private:
	void	processEvents();
	void    render();

	Xbox360Controller m_controlor;




	// sfml window for drawing
	
	// splash screen
	License* m_license;
	// comic sans font

	sf::Font m_dangan2;
	Story* m_story;
	//Credits* m_credits;
	MainMenu* menu;
	Gameplay* gameplay;
	Options* options;
	HighscoreTable* highscore; 
	void update(sf::Time t_deltaTime);

	
	

	sf::RenderWindow m_window; // main SFML window
	
	bool m_exitGame; // control exiting game
	

};
#include "MainMenu.h"
#include "Gameplay.h"
#include "Options.h"
#include "HighscoreTable.h"
#endif // !GAME_HPP

