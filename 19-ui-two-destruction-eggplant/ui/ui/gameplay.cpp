#include "Gameplay.h"

Gameplay::Gameplay(Game& game) :
	m_game(&game)
{
	setupText();
}

Gameplay::~Gameplay()
{

}

void Gameplay::setupText()
{
	font.loadFromFile("ASSETS/FONTS/ariblk.ttf");
	text.setString("StopWatch");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(400.0f, 300.0f);
}

void Gameplay::update(Xbox360Controller& t_control, sf::RenderWindow& t_window)
{
	if (t_control.m_currentState.A)
	{
		moveToCredits(t_control);
	}
	if (t_control.m_currentState.X)
	{
		moveToOptions(t_control);
	}
}
void Gameplay::moveToCredits(Xbox360Controller& t_control)
{
	
		m_game->setGameState(s_GameStates::s_ending);
	
}

void Gameplay::moveToOptions(Xbox360Controller& t_control)
{

	


		m_game->setGameState(s_GameStates::s_options);
  
	
}

void Gameplay::Draw(sf::RenderWindow& t_window)
{
	t_window.clear();
	t_window.draw(text);
	t_window.display();
}