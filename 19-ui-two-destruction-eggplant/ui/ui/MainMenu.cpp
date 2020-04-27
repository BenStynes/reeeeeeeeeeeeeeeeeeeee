#include "MainMenu.h"
MainMenu::MainMenu(Game &game) : m_game(&game)

{

	

	/// <summary>
	/// init all of the buttons
	/// </summary>
	

	/// <summary>
	/// sets the initial button that is selected
	/// </summary>


}

MainMenu::~MainMenu()
{
}

void MainMenu::setupText()
{

	/*
	if (!m_texturePointer.loadFromFile("ASSETS\\IMAGES\\pointer.png"))
	{
		std::cout << "problem loading pointer" << std::endl;
	}
	m_pointerSprite.setTexture(m_texturePointer);
	m_pointerSprite.setOrigin(m_pointerSprite.getGlobalBounds().width / 2, m_pointerSprite.getGlobalBounds().height / 2);
	m_pointerSprite.setPosition({ 220.0f, 285.0f });
	m_pointerSprite.scale(3, 3);*/


	

	


}

void MainMenu::update(Xbox360Controller &t_control,sf::RenderWindow &t_window)
{
	
	movePointer( t_control);
	
}

void MainMenu::movePointer(Xbox360Controller& t_control)
{

	if (t_control.m_currentState.DpadDown || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!t_control.m_previousState.DpadDown)
		{
			optionCounterDown++;
		}
	}

	if (t_control.m_currentState.DpadUp )
	{
		if (!t_control.m_previousState.DpadUp || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			optionCounterDown--;
		}

	}
	if (t_control.m_currentState.A)
	{
		if (!t_control.m_previousState.A || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			m_currentButton->onClick();
		}
	}
	if (optionCounterDown < 0)
	{
		optionCounterDown = 4;
	}
	else if (optionCounterDown > 5)
	{
		optionCounterDown = 0;
	}
	//switch (optionCounterDown)
	//{
	//case 0:
	//	m_pointerSprite.setPosition(m_pointerSprite.getPosition().x, 10.0f);
	//	break;
	//case 1:
	//	m_pointerSprite.setPosition(m_pointerSprite.getPosition().x,95.0f);
	//	break;
	//case 2:
	//	m_pointerSprite.setPosition(m_pointerSprite.getPosition().x,180.0f);
	//	break;
	//case 3:
	//	m_pointerSprite.setPosition(m_pointerSprite.getPosition().x, 265.0f);
	//	break;
	//case 4:
	//	m_pointerSprite.setPosition(m_pointerSprite.getPosition().x, 350.0f);
	//	break;
	//}

}
void MainMenu::Draw(sf::RenderWindow &t_window)
{
	t_window.clear();
	//for (NormalButton button : m_buttons)
	//{
	//	button.render(t_window);
	//}


	//t_window.draw(m_pointerSprite);
	
	
	t_window.display();
}

//
//
void MainMenu::toOptions() {  /*m_game->setGameState(s_GameStates::s_options);*/ }
void MainMenu::toGamePlay() { /*m_game->setGameState(s_GameStates::s_story);*/}
void MainMenu::toHighScore() { /*m_game->setGameState(s_GameStates::s_ending);*/ }
void MainMenu::toCredits() {/*m_game->setGameState(s_GameStates::s_credits);*/ }
//void MainMenu::Exit() {}