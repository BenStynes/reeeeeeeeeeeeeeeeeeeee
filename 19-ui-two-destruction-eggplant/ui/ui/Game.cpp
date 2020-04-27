#include "Game.h"
#include <iostream>


///initializer
Game::Game() : m_exitGame(false),
	m_window(sf::VideoMode(800, 600), "Stopwatch game thingy")
	
{

	
	if (!m_dangan2.loadFromFile("Baskervville-Regular.ttf"))
	{
		std::cout << "problem loading font file" << std::endl;
	}

	
	m_license = new License(*this, m_dangan2);
	m_story = new Story(*this, m_dangan2);
	menu = new MainMenu(*this);
	gameplay = new Gameplay(*this);
	options = new Options(*this);
	highscore = new HighscoreTable(*this);
	//m_credits = new Credits(*this, m_dangan2);
	//m_credits->load(1, m_name);

	

}

///deconstrouctor
Game::~Game()
{
	delete(m_license);
	delete(m_story);
	delete(menu);
	delete(gameplay);
	delete(options);
	delete(highscore);
	std::cout << "destructing game" << std::endl;
}


/// <summary>
/// run the game loop
/// 60fps updates and as many renders as possible
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);



	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
			render();
		}
		
	}
}

/// <summary>
/// method to allow for a change of gamestate
/// </summary>
/// <param name="gameState"></param>
void Game::setGameState(s_GameStates gameState)
{
	m_gameStates = gameState;
}

/// <summary>
/// update the game call appropiate update based on
/// current game state passing delta time
/// </summary>
/// <param name="time">delta update time</param>
void Game::update(sf::Time time)
{
	m_controlor.update();
	switch (m_gameStates)
	{
	case s_GameStates::s_licenceScreen:
		m_license->update(time);
		break;
	case s_GameStates::s_splashScreen:
		
		break;
	case s_GameStates::s_titleScreen:
		menu->update(m_controlor,m_window);
		break;
	case s_GameStates::s_story:
		m_story->update(time, m_controlor);
		break;
	case s_GameStates::s_gameplay:
		gameplay->update(m_controlor, m_window);
		break;
	case s_GameStates::s_ending:
		highscore->update(m_controlor,m_window);
		break;
	case s_GameStates::s_credits:
		break;
	case s_GameStates::s_options:
		options->update(m_controlor, m_window);
		break;
	default:
		break;
	}
	
}

/// <summary>
/// process windows events &
/// close window on exit request (alt F4 etc.)
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
	
}


/// <summary>
/// draw the frame and then switch buffers
/// </summary>



/// <summary>
/// display the relevant game screen
/// use a switch to choose
/// </summary>

void Game::render()
{

	switch(m_gameStates)
	{
	case s_GameStates::s_licenceScreen:
		m_license->render(m_window);
		break;
	case s_GameStates::s_splashScreen:
		
		break;
	case s_GameStates::s_titleScreen:
		menu->Draw(m_window);
		break;
	case s_GameStates::s_story:
		m_story->render(m_window);
		break;
	case s_GameStates::s_gameplay:
		gameplay->Draw(m_window);
		break;
	case s_GameStates::s_ending:
		highscore->Draw(m_window);
		break;
	case s_GameStates::s_credits:
		break;
	case s_GameStates::s_options:
		options->Draw(m_window);
		break;
	default:
		menu->Draw(m_window);
		break;
	}
}




