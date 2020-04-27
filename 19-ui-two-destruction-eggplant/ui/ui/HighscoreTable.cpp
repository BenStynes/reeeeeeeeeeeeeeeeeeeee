#include "HighscoreTable.h"


HighscoreTable::HighscoreTable(Game& game) :
	m_game(&game)
{
	setupText();
}

HighscoreTable::~HighscoreTable()
{

}

void HighscoreTable::setupText()
{
	font.loadFromFile("ASSETS/FONTS/ariblk.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(400.0f, 300.0f);
}

void HighscoreTable::update(Xbox360Controller& t_control, sf::RenderWindow& t_window)
{
	

	if (t_control.m_currentState.DpadUp)
	{

		if (!t_control.m_previousState.DpadUp)
		{
			if (i + 1 < alphabet.length())
			{
				if (nameTracker < 3)
				{
					name.at(nameTracker) = alphabet.at(i);	
					
				}
				
				
				i++;
			}
			else
			{
				i = 1;
			}
		}
	
	}
	if (t_control.m_currentState.A)
	{
		if (!t_control.m_previousState.A)
		{
			nameTracker++;
			i = 1;

			
		}
	}
	text.setString(name);
	if (nameTracker > 2)
	{
		m_game->setGameState(s_GameStates::s_credits);

	}
}

void HighscoreTable::moveToCredits(Xbox360Controller& t_control)
{
	if (t_control.m_currentState.A)
	{
		m_game->setGameState(s_GameStates::s_ending);
	}
}

void HighscoreTable::moveToOptions(Xbox360Controller& t_control)
{
	if (t_control.m_currentState.X)
	{
		m_game->setGameState(s_GameStates::s_options);
	}
}

void HighscoreTable::Draw(sf::RenderWindow& t_window)
{
	t_window.clear();
	t_window.draw(text);
	t_window.display();
}